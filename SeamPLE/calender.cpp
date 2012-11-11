#include "calender.h"


static string _DELETE = "delete";
static string _ADDITION = "add";
static string _EDIT = "edit";
static string _DELETEALL = "deleteAll";
static int NOTFOUND = -1;
static int F10AT = 4;
static char* ARCHIVE_FILENAME = "archive.txt";
static char* STORAGE_FILENAME = "storage.txt";
static char* BACKUP_FILENAME = "backup.txt";
const int  calender::DATENORMAL         = 0;
const int  calender::DATEWEEKLY         = 1;
const int  calender::DATEFORTNIGHTLY    = 2;
const int  calender::DATEMONTHLY        = 3;

calender::calender()
{
    _storage=loadFile(STORAGE_FILENAME);
    _faulty = _faulty->getInstance();
    calender::SortByDate();
    calender::updateRecurringEvents();
    calender::archivePastEvent();
    if (fileExists(BACKUP_FILENAME))
        remove(BACKUP_FILENAME);
}

calender::~calender()
{

    _faulty->endInstance();
}
//@Riandy A0088392R
//this function converts the given time to this format "dd / mm / yyyy - HH : MM : SS"
//and return it as a string
string calender::convertToDate(tm _date)
{
    string _dateString;
    ostringstream convert;
    convert<< _date.tm_mday << " / " << _date.tm_mon << " / " << _date.tm_year<< " - " ;
    convert<< _date.tm_hour << " : " << _date.tm_min << " : " << _date.tm_sec;
    _dateString=convert.str();
    return _dateString;

}
//@Riandy A0088392R
//this function converts the given time to this format "dd / mm / yyyy"
//and return it as a string
string calender::convertToDateNoTime(tm _date)
{
    string _dateString;
    ostringstream convert;
    convert<< _date.tm_mday << " / " << _date.tm_mon << " / " << _date.tm_year;
    _dateString=convert.str();
    return _dateString;
}


//@John A0069517W
bool calender::addItem(task currentTask)
{
    ASSERT(currentTask.getEventName() !="","Fail to add, task doesn't contain event name");
    string _currentName = currentTask.getEventName();
    string _uniqueName = ensureUniqueName(_currentName);
    currentTask.setEventName(_uniqueName);

    if (currentTask.getPriority() == "")
    {
        currentTask.setPriority("LOW");
    }

    saveAdd(currentTask.getEventName());
    saveHistory(_ADDITION);
    lastCommandUndo = false;
    _storage.push_back(currentTask);
    if(writeFile())
        return true;
    else
    {
        _faulty->report("cannot write to file");
        return false;
    }
}

//@John A0069517W
string calender::ensureUniqueName(string _name)
{
    if (!checkNameExists(_name))
        return _name;
    else
    {
        // 1 can be treated as a string, which will be appended to events with duplicate
        // names, so as to ensure unique names. This will be incremented until a unique name is
        // found.

        int collisionNumber = 1;
        string _originalName = _name;

        while (checkNameExists(_name))
        {
            ostringstream tempString;

            tempString.str("");
            tempString.clear();
            tempString<<_originalName;
            tempString<<"[";
            tempString<<collisionNumber;
            tempString<<"]";
            _name = tempString.str();
            collisionNumber++;
        }

        return _name;
    }

}

//@John A0069517W
bool calender::checkNameExists(string _name)
{
    for (int i = 0; i < _storage.size(); i++)
    {
        if (_name == _storage[i].getEventName())
            return true;
    }
    return false;
}
//@John A0069517W
bool calender::markTask(task markedTask)
{
    if(this->deleteItem(markedTask.getEventName()))
    {
        this->archiveEvent(markedTask);
        return true;
    }
    else
        return false;

}
//@John A0069517W
vector<task> calender::getFloatingEvents()
{
    vector<task> _bufferStorage;
    for (int i = 0; i < _storage.size(); i++)
    {
        if (_storage[i].getDateType() == F10AT)
            _bufferStorage.push_back(_storage[i]);
    }
    return _bufferStorage;
}
//@John A0069517W
bool calender::deleteItem(int taskID)
{
    saveHistory(_DELETE);
    lastCommandUndo = false;
    saveDeletedTask(taskID-1);
    _storage.erase(_storage.begin()+taskID-1);
    writeFile();
    return true;
}
//@John A0069517W
bool calender::deleteAll()
{
    writeBackupFile();
    _storage.clear();
    saveHistory(_DELETEALL);
    lastCommandUndo = false;
    writeFile();
    return true;
}

//@Riandy A0088392R
//this function delete an event based on the eventName provided
//return true if delete is successful, else return false
//it will also update the History if successful in deleting
bool calender::deleteItem(string eventName)
{
    for(int i=0 ; i<_storage.size() ; i++)
        if(_storage[i].getEventName()==eventName)
        {
            saveHistory(_DELETE);
            lastCommandUndo = false;
            saveDeletedTask(i);

            _storage.erase(_storage.begin()+i);
            writeFile();
            return true;
        }
    return false;
}

//@Riandy A0088392R
//this function is used to write _storage (vector of task)
//to STORAGE_FILENAME (storage.txt)
bool calender::writeFile()
{
    calender::SortByDate();
    ofstream writeFile(STORAGE_FILENAME);
    for (int i=0;i<int(_storage.size());i++)
    {
        vector<string> temp=_storage[i].toString();
        for(int j=1;j <int(temp.size());j++)
            writeFile<<temp[j]<<endl;
        writeFile<<endl;
        temp.clear();
    }

    return true;
}

//@JOHN A0069517W
void calender::writeBackupFile()
{
    std::ifstream    inFile(STORAGE_FILENAME);
    std::ofstream    outFile(BACKUP_FILENAME);
    outFile << inFile.rdbuf();
}
//@JOHN A0069517W
bool calender::checkID(int taskID)
{
    if (taskID > int(_storage.size()) || taskID<1)
        return false;
    else
        return true;
}

//@JOHN A0069517W
bool calender::editTask( task _edited)
{
    task* taskMatch = pointerSearchByTask( _edited.getEventName());
    if (taskMatch == NULL)// no match found
        return false;
    else
    {
        saveHistory(_EDIT);
        lastCommandUndo = false;
        task _original = *taskMatch;
        undoOriginalEdits(_original);

        bool startDateentered = !(_edited.getStartDate().tm_year == 0 && _edited.getStartDate().tm_mon == 0
                                  && _edited.getStartDate().tm_mday ==0);
        // if( difftime( mktime(&(_edited.getStartDate())),mktime(&task::getEmptyDateTm()) ) != 0)

        if(startDateentered)
        {
            // check if floating event, to set to non-float
            if (taskMatch->getDateType() == F10AT)
                taskMatch->setDateType(0);
            taskMatch->setStartDate(_edited.getStartDate());

        }

        bool endDateentered = !(_edited.getEndDate().tm_year == 0 && _edited.getEndDate().tm_mon == 0

                                && _edited.getEndDate().tm_mday ==0);
        if(endDateentered)
        {
            taskMatch->setEndDate(_edited.getEndDate());
        }

        if(_edited.getPriority() !="" )
        {
            taskMatch->setPriority(_edited.getPriority());
        }

        if(_edited.getCategory() != "#" )
            taskMatch->setCategory(_edited.getCategory());

        undoNewEdits(*taskMatch);
        writeFile();
        return true;

    }


}
//@Riandy A0088392R
vector<task> calender::SearchByCat(string searchItem)
{
    vector<task> _bufferStorage;
    for (int i = 0; i < int(_storage.size()); i++)
    {
        string  bufferString = _storage[i].getCategory();
        cout<<_storage[i].getCategory();
        if (bufferString.compare(searchItem)==0)
        {
            _bufferStorage.push_back(_storage[i]);

        }
    }
    return _bufferStorage;
}

//@Riandy A0088392R
//this function search the database based on the string provided and return
//all the results in vector<task>.
vector<task> calender::SearchByTask(string searchItem)
{
    vector<task> _bufferStorage;
    for (int i = 0; i < int(_storage.size()); i++)
    {
        string  bufferString = _storage[i].getEventName();
        if (bufferString.find(searchItem,0)!=string::npos)
        {
            _bufferStorage.push_back(_storage[i]);
        }
    }
    return _bufferStorage;
}

task* calender::pointerSearchByTask(string searchItem) //@WENREN
// only return first match
{
    task *match = NULL;
    for (int i = 0; i < int(_storage.size()); i++)
    {
        string  bufferString = _storage[i].getEventName();
        if (bufferString.find(searchItem,0)!=string::npos)
        {
            return&(_storage[i]);
        }//this part can add defensive programming and assertion,exception handling if detected more than 1 exact match
    }
    return match;

}


//@JOHN A0069517W
int calender::getTaskID(string searchItem)
{
    int taskID = NOTFOUND;
    for (int i=0; i< int(_storage.size()); i++)
    {
        if (_storage[i].getEventName() == searchItem)
            taskID = i;
    }
    return taskID;
}
vector<task> calender::SearchByPartialTask(string searchItem)
{
    string searchItemBuffer = searchItem.substr(0,searchItem.length()/*-1*/);//remove the null charcter at the end of string
    vector<task> _bufferStorage;
    for (int i = 0; i < int(_storage.size()); i++)
    {
        string  bufferString = _storage[i].getEventName();
        if(bufferString.length() >= searchItem.length()/*-1*/)//defensive programming
        {
            string compareString = (bufferString.substr(0, searchItem.length()/*-1*/));
            ////cout<<"zzz"<<compareString<<"zzz"<<searchItemBuffer<<"zz"<<endl;
            if(compareString == searchItemBuffer) //match exactly
                _bufferStorage.push_back(_storage[i]);
        }
    }
    return _bufferStorage;
}
//@JOHN A0069517W
vector<task> calender::displayDatabase()
{
    return _storage;
}



//@Riandy A0088392R
//This function loads the data to vector<task> based on the filename provided
//The format in the txt file is fixed.
vector<task> calender::loadFile(char* fileName)
{
    vector<task> list;

    ifstream readFile(fileName);

    string temp,description,priority,category;
    char space;
    int dateType;
    string startDate,endDate,test;
    //variable temp is used to read unecessary string/ character

    while(readFile>>temp)
    {
        readFile>>temp;
        readFile.get(space);
        getline(readFile,description);

        readFile>>temp;
        readFile>>temp;
        getline(readFile,startDate);
        istringstream iss(startDate);
        tm _startDate;
        iss >> _startDate.tm_mday;
        iss >> temp;
        iss >> _startDate.tm_mon;
        iss >> temp;
        iss >> _startDate.tm_year;
        iss >> temp;
        iss >> _startDate.tm_hour;
        iss >> temp;
        iss >> _startDate.tm_min;
        iss >> temp;
        iss >> _startDate.tm_sec;

        readFile>>temp;
        readFile>>temp;
        getline(readFile,endDate);
        istringstream isss(endDate);
        tm _endDate;
        isss >> _endDate.tm_mday;
        isss >> temp;
        isss >> _endDate.tm_mon;
        isss >> temp;
        isss >> _endDate.tm_year;
        isss >> temp;
        isss >> _endDate.tm_hour;
        isss >> temp;
        isss >> _endDate.tm_min;
        isss >> temp;
        isss >> _endDate.tm_sec;

        readFile>>temp;
        readFile>>temp;
        getline(readFile,test);
        istringstream in(test);
        in >> dateType;

        readFile>>temp;
        readFile>>temp;
        readFile>>priority;

        readFile>>temp;
        readFile>>temp;
        readFile>>category;

        task* newTask= new task;
        newTask->setID(_storage.size());
        newTask->setEventName(description);
        newTask->setStartDate(_startDate);
        newTask->setEndDate(_endDate);
        newTask->setDateType(dateType);
        newTask->setPriority(priority);
        newTask->setCategory(category);
        list.push_back(*newTask);

    }
    return list;
}

//@JOHN A0069517W
bool calender::undoAction()
{
    if (_commandHistory.size() == 0)
        return false;
    else
    {
        string lastCommand = _commandHistory.top();
        lastCommandUndo = true;
        if (lastCommand == _ADDITION)
        {

            this->undoAdd();
        }

        else if (lastCommand == _DELETE)
        {

            this->undoDelete();
        }

        else if (lastCommand == _EDIT)
        {
            if(!(this->undoEdit()))
                return false;
        }
        else if (lastCommand == _DELETEALL)
        {
            this->undoDeleteAll();
        }
        else
            _faulty->report("Calender class: Unknown undo command");
        _commandHistory.pop();
        writeFile();
    }

    return true;
}
//@JOHN A0069517W
bool calender::redoAction()
{
    if (_undoHistory.size() == 0 || lastCommandUndo == false)
        return false;
    else
    {
        if (_undoHistory.top() == _ADDITION)
        {

            this->redoAdd();
        }
        else if (_undoHistory.top() == _DELETE)
        {
            this->redoDelete();
        }
        else if (_undoHistory.top() == _EDIT)
        {

            if(!(this->redoEdit()))
                return false;
        }
        else if (_undoHistory.top() == _DELETEALL)
        {

            this->redoDeleteAll();
        }
        else
            _faulty->report("Calender class: Unknown redo command");
        _undoHistory.pop();
        writeFile();

    }
    return true;
}

//@Riandy A0088392R
vector<task> calender::SearchByDate(string searchDate)
{

    vector<task> _bufferStorage;
    for (int i = 0; i < int(_storage.size()); i++)
    {
        string  bufferDate;
        tm _date=_storage[i].getStartDate();
        ostringstream convert;
        convert<< _date.tm_mday << " / " << _date.tm_mon << " / " << _date.tm_year;
        bufferDate=convert.str();

        if(searchDate==bufferDate)
            _bufferStorage.push_back(_storage[i]);
    }
    return _bufferStorage;
}

//@Riandy A0088392R
vector<task> calender::getToday()
{
    vector<task> _bufferStorage;

    // get time now in the format dd-mm-yyyy
    time_t t = time(0);
    struct tm * now = localtime( & t );
    ostringstream convert;
    convert << now->tm_mday << " / " << (now->tm_mon + 1) << " / " << (now->tm_year + 1900);
    string todayDate=convert.str();

    _bufferStorage=SearchByDate(todayDate);

    return _bufferStorage;
}

//@JOHN A0069517W
// Following method saves the deleted task in a temporary stack, such that
// we can call an undo later on to restore the task.
void calender::saveDeletedTask(int taskID)
{
    task temp = _storage[taskID];
    if (_deletedTasks.size() < 3)
        _deletedTasks.push(temp);

    else if (_deletedTasks.size() == 3)
    {
        stack<task> tempStack;
        while (_deletedTasks.size() != 1)
        {
            tempStack.push(_deletedTasks.top());
            _deletedTasks.pop();
        }
        _deletedTasks.pop();
        while(_deletedTasks.size() != 2)
        {
            _deletedTasks.push(tempStack.top());
            tempStack.pop();
        }
        _deletedTasks.push(temp);

    }
}
//@JOHN A0069517W
// Following method saves latest command in a temporary stack, such that
// we can call an undo later on based on the most recent command.
void calender::saveHistory(string command)
{
    if (_commandHistory.size() < 3)
        _commandHistory.push(command);
    else if (_commandHistory.size() == 3)
    {
        stack<string> tempStack;
        while (_commandHistory.size() != 1)
        {
            tempStack.push(_commandHistory.top());
            _commandHistory.pop();
        }
        _commandHistory.pop();
        while(_commandHistory.size() != 2)
        {
            _commandHistory.push(tempStack.top());
            tempStack.pop();
        }
        _commandHistory.push(command);

    }

}
//@JOHN A0069517W
// Following method saves the name of added tasks in a temporary stack, such that
// we can search the storage based on the unique name to delete it during undo.
void calender::saveAdd(string Item)
{
    if (_addHistory.size() < 3)
        _addHistory.push(Item);
    else if (_addHistory.size() == 3)
    {
        stack<string> tempStack;
        while (_addHistory.size() != 1)
        {
            tempStack.push(_addHistory.top());
            _addHistory.pop();
        }
        _addHistory.pop();
        while(_addHistory.size() != 2)
        {
            _addHistory.push(tempStack.top());
            tempStack.pop();
        }
        _addHistory.push(Item);

    }

}
//@JOHN A0069517W
// Following method saves the name of an undone deleted task in a temporary stack, such that
// we can find it and and delete it when redo is called.
void calender::saveUndoneDelete(string Item)
{
    if (_deleteHistory.size() < 3)
        _deleteHistory.push(Item);
    else if (_deleteHistory.size() == 3)
    {
        stack<string> tempStack;
        while (_deleteHistory.size() != 1)
        {
            tempStack.push(_deleteHistory.top());
            _deleteHistory.pop();
        }
        _deleteHistory.pop();
        while(_deleteHistory.size() != 2)
        {
            _deleteHistory.push(tempStack.top());
            tempStack.pop();
        }
        _deleteHistory.push(Item);

    }

}


//@JOHN A0069517W
// Following method saves the original task before it is being edited, such that
// we can restore it when undo is called.
void calender::undoOriginalEdits(task _oldTask)
{
    if (_undoOriginalEdits.size() < 3)
        _undoOriginalEdits.push(_oldTask);
    else if (_undoOriginalEdits.size() == 3)
    {
        stack<task> tempStack;
        while (_undoOriginalEdits.size() != 1)
        {
            tempStack.push(_undoOriginalEdits.top());
            _undoOriginalEdits.pop();
        }
        _undoOriginalEdits.pop();
        while(_undoOriginalEdits.size() != 2)
        {
            _undoOriginalEdits.push(tempStack.top());
            tempStack.pop();
        }
        _undoOriginalEdits.push(_oldTask);
    }

}
//@JOHN A0069517W
// Following method saves newly edited task in a temporary stack,
// so that we know which task was most recently undone when redo is called
void calender::undoNewEdits(task _newTask)
{
    if (_undoNewEdits.size() < 3)
        _undoNewEdits.push(_newTask);
    else if (_undoNewEdits.size() == 3)
    {
        stack<task> tempStack;
        while (_undoNewEdits.size() != 1)
        {
            tempStack.push(_undoNewEdits.top());
            _undoNewEdits.pop();
        }
        _undoNewEdits.pop();
        while(_undoNewEdits.size() != 2)
        {
            _undoNewEdits.push(tempStack.top());
            tempStack.pop();
        }
        _undoNewEdits.push(_newTask);
    }
}
//@JOHN A0069517W
// Following method is an opposite of the previous methods regarding edit,
// so that we can call undo 3 times then call redo 3 times.
void calender::redoOriginalEdits(task _oldTask)
{
    if (_redoOriginalEdits.size() < 3)
        _redoOriginalEdits.push(_oldTask);
    else if (_redoOriginalEdits.size() == 3)
    {
        stack<task> tempStack;
        while (_redoOriginalEdits.size() != 1)
        {
            tempStack.push(_redoOriginalEdits.top());
            _redoOriginalEdits.pop();
        }
        _redoOriginalEdits.pop();
        while(_redoOriginalEdits.size() != 2)
        {
            _redoOriginalEdits.push(tempStack.top());
            tempStack.pop();
        }
        _redoOriginalEdits.push(_oldTask);
    }

}
//@JOHN A0069517W
// Following method is an opposite of the previous methods regarding edit,
// so that we can call undo 3 times then call redo 3 times.
void calender::redoNewEdits(task _newTask)
{
    if (_redoNewEdits.size() < 3)
        _redoNewEdits.push(_newTask);
    else if (_redoNewEdits.size() == 3)
    {
        stack<task> tempStack;
        while (_redoNewEdits.size() != 1)
        {
            tempStack.push(_redoNewEdits.top());
            _redoNewEdits.pop();
        }
        _redoNewEdits.pop();
        while(_redoNewEdits.size() != 2)
        {
            _redoNewEdits.push(tempStack.top());
            tempStack.pop();
        }
        _redoNewEdits.push(_newTask);
    }
}

//@Riandy A0088392R
//This function is used to sort the _storage vector according to the
//taskDateComparator specified
void calender::SortByDate()
{
    sort(_storage.begin(),_storage.end(),taskDateComparator);
}

//@Riandy A0088392R
bool calender::taskDateComparator(task task1,task task2)
{
    tm date1=task1.getStartDate();
    tm date2=task2.getStartDate();
    return calender::dateComparator(date1,date2);
}

//@Riandy A0088392R
bool calender::dateComparator(tm date1,tm date2)
{
    //check in the sequence of
    //year,month,day,hour,min,sec
    bool result=false;

    if(date1.tm_year<date2.tm_year)
        return true;
    else if(date1.tm_year==date2.tm_year)
    {

        if(date1.tm_mon<date2.tm_mon)
            result=true;
        else if(date1.tm_mon==date2.tm_mon)
        {
            if(date1.tm_mday<date2.tm_mday)
                result=true;
            else if(date1.tm_mday==date2.tm_mday)
            {
                if(date1.tm_hour<date2.tm_hour)
                    result=true;
                else if(date1.tm_hour==date2.tm_hour)
                {
                    if(date1.tm_min<date2.tm_min)
                        result=true;
                    else if(date1.tm_min==date2.tm_min)
                    {
                        if(date1.tm_sec<date2.tm_sec)
                            result=true;
                    }
                }
            }
        }
    }

    return result;

}

//@Riandy A0088392R
vector<task> calender::SearchPastEvent()
{
    time_t t = time(0);   // get time now
    tm  now = *localtime( & t );
    now.tm_year+=1900;
    now.tm_mon+=1;

    vector<task> bufferStorage;

    for(int i=0;i<_storage.size();i++)
        if(dateComparator(_storage[i].getEndDate(),now)==true && _storage[i].getDateType() != F10AT)

            bufferStorage.push_back(_storage[i]);

    return bufferStorage;
}

//@Riandy A0088392R
bool calender::archivePastEvent()
{
    vector<task> pastEvents;

    pastEvents = SearchPastEvent();

    // Delete from real storage vector
    for (int i = 0; i< pastEvents.size(); i++)
    {
        int ID = getTaskID(pastEvents[i].getEventName());
        _storage.erase(_storage.begin() + ID);
    }

    SortByDate();
    writeFile();

    //write the past event to the archive file.
    ofstream write (ARCHIVE_FILENAME, fstream::app);

    for(int i=0;i<pastEvents.size();i++)
    {
        vector<string> temp= pastEvents[i].toString();
        for(int j=1;j <int(temp.size());j++)
            write<<temp[j]<<endl;
        write<<endl;
        temp.clear();
    }
    pastEvents.clear();
    write.close();


    return true;
}

//@JOHN A0069517W
bool calender::archiveEvent(task markedTask)
{
    ofstream write (ARCHIVE_FILENAME, fstream::app);
    vector<string> temp =markedTask.toString();
    for (int j=1; j<int(temp.size());j++)
        write<<temp[j]<<endl;
    write<<endl;
    temp.clear();
    write.close();
    return true;
}

//@JOHN A0069517W
bool calender::fileExists(const char *fileName)
{

    ifstream ifile(fileName);
    if (ifile)
        return true;
    else
        return false;
}



//@JOHN A0069517W
void calender::undoAdd()
{
    _undoHistory.push(_ADDITION);
    int ID = getTaskID(_addHistory.top());
    _undoneAddTasks.push(_storage[ID]);
    _storage.erase(_storage.begin()+ID);
    _addHistory.pop();
}
//@JOHN A0069517W
void calender::undoDelete()
{
    ASSERT(_deletedTasks.size() != 0,"Nothing in deleted tasks stack");
    _undoHistory.push(_DELETE);
    task tempTask = _deletedTasks.top();
    _storage.push_back(tempTask);
    saveUndoneDelete(tempTask.getEventName());
    _deletedTasks.pop();
}
//@JOHN A0069517W
bool calender::undoEdit()
{
    ASSERT(_undoNewEdits.size() != 0, "Nothing in undo stack");
    _undoHistory.push(_EDIT);
    task tempTask = _undoNewEdits.top();

    int position = getTaskID(tempTask.getEventName());
    if (position != NOTFOUND) // defensive programming
    {
        _storage[position] = _undoOriginalEdits.top();
        redoOriginalEdits(_undoNewEdits.top());
        redoNewEdits(_undoOriginalEdits.top());
        _undoOriginalEdits.pop();
        _undoNewEdits.pop();
        return true;
    }
    else if (position == NOTFOUND)
        return false;
}
//@JOHN A0069517W
void calender::undoDeleteAll()
{
    loadFile(BACKUP_FILENAME);

    remove(BACKUP_FILENAME);

    _undoHistory.push(_DELETEALL);
}

//@JOHN A0069517W
void calender::redoAdd()
{
    task lastUndo =  _undoneAddTasks.top();
    _storage.push_back(lastUndo);
    saveHistory(_ADDITION);
    saveAdd(lastUndo.getEventName());
    _undoneAddTasks.pop();
}
//@JOHN A0069517W
void calender::redoDelete()
{
    saveHistory(_DELETE);
    int ID = getTaskID(_deleteHistory.top());
    saveDeletedTask(ID);
    _storage.erase(_storage.begin()+ ID);
    _deleteHistory.pop();
}
//@JOHN A0069517W
bool calender::redoEdit()
{
    task tempTask = _redoNewEdits.top();
    int position = getTaskID(tempTask.getEventName());
    if (position != NOTFOUND) // defensive programming
    {
        _storage[position] = _redoOriginalEdits.top();
        saveHistory(_EDIT);
        undoOriginalEdits(_redoNewEdits.top());
        undoNewEdits(_redoOriginalEdits.top());
        _redoNewEdits.pop();
        _redoOriginalEdits.pop();
        return true;
    }
    else if (position == NOTFOUND)
        return false;
}
//@JOHN A0069517W
void calender::redoDeleteAll()
{
    writeBackupFile();
    _storage.clear();
    saveHistory(_DELETEALL);
}

//@Riandy A0088392R
//This function is used to display the archive events store in the
//ARCHIVE_FILENAME and return it as vector of task
vector<task> calender::displayArchiveEvent()
{
    vector<task> temp=loadFile(ARCHIVE_FILENAME);
    vector<task> archive;
    //reverse the result from latest to earliest
    for(int i=0;i<temp.size();i++)
        archive.push_back(temp[temp.size()-i-1]);
    return archive;
}

//@Riandy A0088392R
bool calender::updateRecurringEvents()
{
    time_t t = time(0);   // get time now
    tm  now = *localtime( & t );
    now.tm_year+=1900;
    now.tm_mon+=1;

    for(int i=0;i<_storage.size();i++)
    {
        //check if the date of a particular event has passed.
        if(dateComparator(_storage[i].getEndDate(),now)==true)
        {
            int dateType = _storage[i].getDateType();
            if(dateType==DATEWEEKLY)
            {
                updateWeekly(_storage[i]);
            }
            else if(dateType==DATEFORTNIGHTLY)
            {
                updateFortnightly(_storage[i]);
            }
            else if(dateType==DATEMONTHLY)
            {
                updateMonthly(_storage[i]);
            }
        }
    }

    return true;
}

//@Riandy A0088392R
void calender::updateDate(int num, tm &date)
{
    int numOfDays=daysInAMonth(date.tm_mon,date.tm_year);
    date.tm_mday+=num;
    if(date.tm_mday>numOfDays)
    {
        date.tm_mday-=numOfDays;
        if(date.tm_mon<12)
        {
            date.tm_mon++;
        }
        else
        {
            date.tm_mon++;
            date.tm_mon-12;
            date.tm_year+1;
        }
    }
}

//@Riandy A0088392R
//this function is used to update the weekly event
void calender::updateWeekly(task &event)
{
    tm startDate=event.getStartDate();
    tm endDate=event.getEndDate();

    //update the startDate
    updateDate(7,startDate);
    //update the endDate
    updateDate(7,endDate);

    event.setStartDate(startDate);
    event.setEndDate(endDate);
}

//@Riandy A0088392R
int calender::daysInAMonth(int year,int month)
{
    int numberOfDays;
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {numberOfDays = 30;}
    else if (month == 2)
    { bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear)
        { numberOfDays = 29;}
        else
        { numberOfDays = 28;}
    }
    else
    { numberOfDays = 31;}

    return numberOfDays;
}

//@Riandy A0088392R
void calender::updateFortnightly(task &event)
{
    tm startDate=event.getStartDate();
    tm endDate=event.getEndDate();

    //update the startDate
    updateDate(14,startDate);
    //update the endDate
    updateDate(14,endDate);

    event.setStartDate(startDate);
    event.setEndDate(endDate);
}

//@Riandy A0088392R
void calender::updateMonthly(task &event)
{
    tm startDate=event.getStartDate();
    tm endDate=event.getEndDate();

    //update the startDate
    updateMonth(1,startDate);
    //update the endDate
    updateMonth(1,endDate);

    event.setStartDate(startDate);
    event.setEndDate(endDate);
}

//@Riandy A0088392R
void calender::updateMonth(int num, tm &date)
{

    if(date.tm_mon+num<12)
    {
        date.tm_mon+=num%12;
    }
    else
    {
        date.tm_mon+=(num%12);
        date.tm_year+(num/12);
    }
}
