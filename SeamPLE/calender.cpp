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
    saveStringToStack(_addHistory, currentTask.getEventName());
    saveStringToStack(_commandHistory, _ADDITION);
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
    saveStringToStack(_commandHistory, _DELETE);
    lastCommandUndo = false;
    saveToStack(_deletedTasks, _storage[taskID-1]);
    _storage.erase(_storage.begin()+taskID-1);
    writeFile();
    return true;
}
//@John A0069517W
bool calender::deleteAll()
{
    if (_storage.size() != 0)
    {
        writeBackupFile();
        _storage.clear();
        saveStringToStack(_commandHistory, _DELETEALL);
        lastCommandUndo = false;
        writeFile();
        return true;
    }
    else
        return false;
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
            saveStringToStack(_commandHistory, _DELETE);
            lastCommandUndo = false;
            saveToStack(_deletedTasks, _storage[i]);
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
        saveStringToStack(_commandHistory, _EDIT);
        lastCommandUndo = false;
        task _original = *taskMatch;
        saveToStack(_undoOriginalEdits, _original);

        bool startDateentered = !(_edited.getStartDate().tm_year == 0 && _edited.getStartDate().tm_mon == 0
                                  && _edited.getStartDate().tm_mday ==0);


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
        saveToStack(_undoNewEdits, *taskMatch);
        writeFile();
        return true;

    }


}
//@Riandy A0088392R
//This function search the category given of every task in _storage and return the
//tasks that match the category into a vector<task>
vector<task> calender::SearchByCat(string searchItem)
{
    vector<task> _bufferStorage;
    for (int i = 0; i < int(_storage.size()); i++)
    {
        string  bufferString = _storage[i].getCategory();
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

//@PAN WENREN A0083711L
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
//@PAN WENREN A0083711L
vector<task> calender::SearchByPartialTask(string searchItem)
{
    string searchItemBuffer = searchItem.substr(0,searchItem.length());
    vector<task> _bufferStorage;
    for (int i = 0; i < int(_storage.size()); i++)
    {
        string  bufferString = _storage[i].getEventName();
        if(bufferString.length() >= searchItem.length())//defensive programming
        {
            string compareString = (bufferString.substr(0, searchItem.length()));
            if(compareString == searchItemBuffer)
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
void calender::saveStringToStack(stack<string>& thisStack, string thisString)
{
    if (thisStack.size() < 3)
        thisStack.push(thisString);
    else if (thisStack.size() == 3)
    {
        stack<string> tempStack;
        while (thisStack.size() != 1)
        {
            tempStack.push(thisStack.top());
            thisStack.pop();
        }
        thisStack.pop();
        while(thisStack.size() != 2)
        {
            thisStack.push(tempStack.top());
            tempStack.pop();
        }
        thisStack.push(thisString);
    }

}


//@JOHN A0069517W
void calender::saveToStack(stack<task>& thisStack, task thisTask)
{
    if (thisStack.size() < 3)
        thisStack.push(thisTask);
    else if (thisStack.size() == 3)
    {
        stack<task> tempStack;
        while (thisStack.size() != 1)
        {
            tempStack.push(thisStack.top());
            thisStack.pop();
        }
        thisStack.pop();
        while(thisStack.size() != 2)
        {
            thisStack.push(tempStack.top());
            tempStack.pop();
        }
        thisStack.push(thisTask);
    }

}

//@JOHN A0069517W
void calender::saveIntToStack(stack<int>& thisStack, int thisInt)
{
    if (thisStack.size() < 3)
        thisStack.push(thisInt);
    else if (thisStack.size() == 3)
    {
        stack<int> tempStack;
        while (thisStack.size() != 1)
        {
            tempStack.push(thisStack.top());
            thisStack.pop();
        }
        thisStack.pop();
        while(thisStack.size() != 2)
        {
            thisStack.push(tempStack.top());
            tempStack.pop();
        }
        thisStack.push(thisInt);
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
//compare two given task with its startDate
bool calender::taskDateComparator(task task1,task task2)
{
    tm date1=task1.getStartDate();
    tm date2=task2.getStartDate();
    return calender::dateComparator(date1,date2);
}

//@Riandy A0088392R
//compare the date given and return true if date1 is earlier than date2
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
    saveToStack(_undoneAddTasks, _storage[ID]);
    ASSERT(ID != -1, "Database error");
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
    saveStringToStack(_deleteHistory, tempTask.getEventName());
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
        saveToStack(_redoOriginalEdits, _undoNewEdits.top());
        saveToStack(_redoNewEdits, _undoOriginalEdits.top());
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
    _storage = loadFile(BACKUP_FILENAME);

    remove(BACKUP_FILENAME);

    _undoHistory.push(_DELETEALL);
}

//@JOHN A0069517W
void calender::redoAdd()
{
    task lastUndo =  _undoneAddTasks.top();
    _storage.push_back(lastUndo);
    saveStringToStack(_commandHistory, _ADDITION);
    saveStringToStack(_addHistory, lastUndo.getEventName());
    _undoneAddTasks.pop();
}
//@JOHN A0069517W
void calender::redoDelete()
{
    saveStringToStack(_commandHistory, _DELETE);
    int ID = getTaskID(_deleteHistory.top());
    saveToStack(_deletedTasks, _storage[ID]);
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
        saveStringToStack(_commandHistory, _EDIT);
        saveToStack(_undoOriginalEdits, _redoNewEdits.top());
        saveToStack(_undoNewEdits, _redoOriginalEdits.top());
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
    saveStringToStack(_commandHistory, _DELETEALL);
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
//This function is used to update the recurring events based on the datetypes
//in every task/event. You should call this function in the constructor before archiving the past
//events
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
//This function updates the date supplied by num days
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
//Return the number of days in a month, taking consideration of leap year
int calender::daysInAMonth(int year,int month)
{
    //defensive coding
    if(month<1 || month >12)
        return 0;

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
//Updates the fortnightly task provided in the parameter
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
//This function is used to update a monthly task.
//it will update both startDate and endDate
//if current month is 12, then year will be auto added by 1
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
//This function is used to update the month on a provided date.
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
