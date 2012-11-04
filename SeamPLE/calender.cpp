#include "calender.h"


static string _DELETE = "delete";
static string _ADDITION = "add";
static string _EDIT = "edit";
static string _DELETEALL = "deleteAll";
static int NOTFOUND = -1;


calender::calender()
{
    calender::loadFile("storage.txt");
    _faulty = _faulty->getInstance();
    calender::SortByDate();
}

calender::~calender()
{
    _faulty->endInstance();
}

string calender::convertToDate(tm _date)
{
    string _result;
    ostringstream convert;
    convert<< _date.tm_mday << " / " << _date.tm_mon << " / " << _date.tm_year << " - " ;
    convert<< _date.tm_hour << " : " << _date.tm_min << " : " << _date.tm_sec;
    _result=convert.str();
    return _result;

}


bool calender::addItem(task currentTask)
{
    //ASSERT(currentTask.getEventName()=="","Fail to add, task doesn't contain event name");
    saveHistory(_ADDITION);
    string _currentName = currentTask.getEventName();
    string _uniqueName = ensureUniqueName(_currentName);

    currentTask.setEventName(_uniqueName);
    saveAdd(currentTask.getEventName());

    _storage.push_back(currentTask);
    if(writeFile())
        return true;
    else
    {
        _faulty->report("cannot write to file");
        return false;
    }
}


string calender::ensureUniqueName(string _name)
{
    if (!checkNameExists(_name))
        return _name;
    else
    {
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


bool calender::checkNameExists(string _name)
{
    for (int i = 0; i < _storage.size(); i++)
    {
        if (_name == _storage[i].getEventName())
            return true;
    }
    return false;
}


bool calender::deleteItem(int taskID)
{
    if (taskID == 9999) // change this to ALL later, debugging tool
    {
        writeBackupFile();
        _storage.clear();
        saveHistory(_DELETEALL);

    }
    else
    {
    saveHistory(_DELETE);
    saveDeletedTask(taskID-1);
    _storage.erase(_storage.begin()+taskID-1);
    }
    writeFile();
    return true;

}

bool calender::deleteItem(string eventName)
{
    for(int i=0 ; i<_storage.size() ; i++)
        if(_storage[i].getEventName()==eventName)
        {
            saveHistory(_DELETE);
            saveDeletedTask(i);
            _storage.erase(_storage.begin()+i);
            writeFile();
            return true;
        }
    return false;
}

bool calender::writeFile()
{
    ofstream writeFile("storage.txt");

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

void calender::writeBackupFile()
{
        std::ifstream    inFile("storage.txt");
        std::ofstream    outFile("backup.txt");

        outFile << inFile.rdbuf();

}

bool calender::checkID(int taskID)
{

    if (taskID > int(_storage.size()) || taskID<1)     
        return false;
    else
       return true;
}


bool calender::editTask( task _edited)
{
    task* taskMatch = pointerSearchByTask( _edited.getEventName());
    if (taskMatch == NULL)// no match found
        return false;
    else
    {
        saveHistory(_EDIT);
        task _original = *taskMatch;
        undoOriginalEdits(_original);
        bool startDateentered = !(_edited.getStartDate().tm_year == 0 && _edited.getStartDate().tm_mon == 0
                                  && _edited.getStartDate().tm_mday ==0);
        // if( difftime( mktime(&(_edited.getStartDate())),mktime(&task::getEmptyDateTm()) ) != 0)
        if(startDateentered)
        {
            taskMatch->setStartDate(_edited.getStartDate());
            cout<<"startdate  entered"<<endl;
        }

        bool endDateentered = !(_edited.getEndDate().tm_year == 0 && _edited.getEndDate().tm_mon == 0
                                && _edited.getEndDate().tm_mday ==0);
        //if( difftime( mktime(&(_edited.getEndDate())),mktime(&task::getEmptyDateTm()) ) != 0)
        if(endDateentered)
        {
            cout<<"enddate entered"<<endl;
            taskMatch->setEndDate(_edited.getEndDate());
        }

        if(_edited.getPriority() != "LOW" )
        {  taskMatch->setPriority(_edited.getPriority());

        }
        if(_edited.getCategory() != "#" )
        taskMatch->setCategory(_edited.getCategory());

        undoNewEdits(*taskMatch);
         writeFile();
       return true;

    }


}

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


task* calender::pointerSearchByTask(string searchItem)// only return first match
{// refactor this as u like to remove the dependency on pointer,because right now ,all the searches only return by value
    // so i need a way to change the value of the search results in order to edit the values
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
            //cout<<"zzz"<<compareString<<"zzz"<<searchItemBuffer<<"zz"<<endl;
            if(compareString == searchItemBuffer) //match exactly
                _bufferStorage.push_back(_storage[i]);
        }
    }
    return _bufferStorage;
}

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





vector<task> calender::displayDatabase()
{
    return _storage;
}




bool calender::loadFile(char* fileName)
{

    _storage.clear();

    ifstream readFile(fileName);

    string temp,description,priority,category;
    char space;

    string startDate,endDate;
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
        readFile>>priority;

        readFile>>temp;
        readFile>>temp;
        readFile>>category;

        task* newTask= new task;
        newTask->setID(_storage.size());
        newTask->setEventName(description);
        newTask->setStartDate(_startDate);
        newTask->setEndDate(_endDate);
        newTask->setPriority(priority);
        newTask->setCategory(category);
        _storage.push_back(*newTask);

    }
    return true;
}


bool calender::undoAction()
{
    if (_commandHistory.size() == 0)
        return false;
    else
    {

        string lastCommand = _commandHistory.top();
        if (lastCommand == _ADDITION)
        {
            _undoHistory.push(_ADDITION);
            int ID = getTaskID(_addHistory.top());
             _undoneAddTasks.push(_storage[ID]);
            _storage.erase(_storage.begin()+ID);
            _addHistory.pop();
        }

        else if (lastCommand == _DELETE)
        {
            _undoHistory.push(_DELETE);
            task tempTask = _deletedTasks.top();
            _storage.push_back(tempTask);
            saveUndoneDelete(tempTask.getEventName());
            _deletedTasks.pop();
        }

        else if (lastCommand == _EDIT)
        {
            _undoHistory.push(_EDIT);
            task tempTask = _undoNewEdits.top();

            int position = getTaskID(tempTask.getEventName());
                if (position != NOTFOUND) // defensive programming
            {
                 _storage[position] = _undoOriginalEdits.top();
                //swapTops(tempTask);
                 redoOriginalEdits(_undoNewEdits.top());
                 redoNewEdits(_undoOriginalEdits.top());
                 _undoOriginalEdits.pop();
                 _undoNewEdits.pop();
            }
            else if (position == NOTFOUND)
                return false;
        }
        else if (lastCommand == _DELETEALL)
        {
            loadFile("backup.txt");
            remove("backup.txt");
            _undoHistory.push(_DELETEALL);
        }
        else
            _faulty->report("Calender class: Unknown undo command");
        _commandHistory.pop();
        writeFile();
    }

    return true;
}

bool calender::redoAction()
{
    if (_undoHistory.size() == 0)
        return false;
    else
    {
        if (_undoHistory.top() == _ADDITION)
        {
            task lastUndo =  _undoneAddTasks.top();
            _storage.push_back(lastUndo);
            saveHistory(_ADDITION);
            saveAdd(lastUndo.getEventName());
             _undoneAddTasks.pop();
        }
        else if (_undoHistory.top() == _DELETE)
        {
           /* int taskID = _storage.size();
            saveDeletedTask(taskID-1);
            _storage.erase(_storage.begin()+taskID-1);
            saveHistory(_DELETE);*/
            saveHistory(_DELETE);
            int ID = getTaskID(_deleteHistory.top());
            //ASSERT(ID == NOTFOUND, "Fail to redo an undone delete, task not found in storage");
            saveDeletedTask(ID);
            _storage.erase(_storage.begin()+ ID);
            _deleteHistory.pop();



        }
        else if (_undoHistory.top() == _EDIT)
        {
            task tempTask = _redoNewEdits.top();
            int position = getTaskID(tempTask.getEventName());
            if (position != NOTFOUND) // defensive programming
            {
                _storage[position] = _redoOriginalEdits.top();
               // swapTops(tempTask);
                saveHistory(_EDIT);
                undoOriginalEdits(_redoNewEdits.top());
                undoNewEdits(_redoOriginalEdits.top());
                _redoNewEdits.pop();
                _redoOriginalEdits.pop();
            }
            else if (position == NOTFOUND)
                return false;
        }
        else if (_undoHistory.top() == _DELETEALL)
        {
            writeBackupFile();
            _storage.clear();
            saveHistory(_DELETEALL);
        }
        else
            _faulty->report("Calender class: Unknown redo command");
        _undoHistory.pop();
        writeFile();

    }
    return true;
}


vector<task> calender::SearchByDate(string todayDate)
{

    vector<task> _bufferStorage;
    for (int i = 0; i < int(_storage.size()); i++)
    {
        string  bufferDate;
        tm _date=_storage[i].getStartDate();
        ostringstream convert;
        convert<< _date.tm_mday << "-" << _date.tm_mon << "-" << _date.tm_year;
        bufferDate=convert.str();

        if(todayDate==bufferDate)
            _bufferStorage.push_back(_storage[i]);
    }
    return _bufferStorage;
}

vector<task> calender::getToday()
{
    vector<task> _bufferStorage;

    // get time now in the format dd-mm-yyyy
    time_t t = time(0);
    struct tm * now = localtime( & t );
    ostringstream convert;
    convert << now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900);
    string todayDate=convert.str();

    _bufferStorage=SearchByDate(todayDate);

    return _bufferStorage;
}


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

void calender::SortByDate()
{
    sort(_storage.begin(),_storage.end(),dateComparator);
}

bool calender::dateComparator(task task1,task task2)
{
    //check in the sequence of
    //year,month,day,hour,min,sec
    tm date1=task1.getStartDate();
    tm date2=task2.getStartDate();
    bool result=true;

    if(date1.tm_year<date2.tm_year)
        return date1.tm_year<date2.tm_year;
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
