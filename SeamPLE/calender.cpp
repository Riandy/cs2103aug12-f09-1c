#include "calender.h"


static string _DELETE = "delete";
static string _ADDITION = "add";
static string _EDIT = "edit";
static int NOTFOUND = -1;


calender::calender()
{
    calender::loadFile();
    _faulty = _faulty->getInstance();
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
        _storage.clear();

    }
    else
    {
    saveHistory(_DELETE);
    saveDelete(taskID-1);
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
            saveDelete(i);
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




bool calender::loadFile()
{

    _storage.clear();

    ifstream readFile("storage.txt");

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
    if (_history.size() == 0)
        return false;
    else
    {

        string lastCommand = _history.top();

        if (lastCommand == _ADDITION)
        {
            _redoCommands.push(_ADDITION);
            int ID = getTaskID(_addHistory.top());
            _redoHistory.push(_storage[ID]);
            _storage.erase(_storage.begin()+ID);
            _addHistory.pop();
        }

        else if (lastCommand == _DELETE)
        {
            _redoCommands.push(_DELETE);
            task tempTask = _deleteHistory.top();
            _storage.push_back(tempTask);
            _deleteHistory.pop();
        }
        else if (lastCommand == _EDIT)
        {
            _redoCommands.push(_EDIT);
            task tempTask = _newEdits.top();

            int position = getTaskID(tempTask.getEventName());
                if (position != NOTFOUND) // defensive programming
            {
                 _storage[position] = _originalEdits.top();
                //swapTops(tempTask);
                 redoOriginalEdits(_newEdits.top());
                 redoNewEdits(_originalEdits.top());
                 _originalEdits.pop();
                 _newEdits.pop();
            }
            else if (position == NOTFOUND)
                return false;
        }
    }
    _history.pop();
    writeFile();
    return true;
}

bool calender::redoAction()
{
    if (_redoCommands.size() == 0)
        return false;
    else
    {
        if (_redoCommands.top() == _ADDITION)
        {
            task lastUndo = _redoHistory.top();
            _storage.push_back(lastUndo);
            saveHistory(_ADDITION);
            saveAdd(lastUndo.getEventName());
            _redoHistory.pop();
        }
        else if (_redoCommands.top() == _DELETE)
        {
            int taskID = _storage.size();
            saveDelete(taskID-1);
            _storage.erase(_storage.begin()+taskID-1);
            saveHistory(_DELETE);

        }
        else if (_redoCommands.top() == _EDIT)
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
        _redoCommands.pop();
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


void calender::saveDelete(int taskID)
{
    task temp = _storage[taskID];
    if (_deleteHistory.size() < 3)
        _deleteHistory.push(temp);

    else if (_deleteHistory.size() == 3)
    {
        stack<task> tempStack;
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
        _deleteHistory.push(temp);

    }
}

void calender::saveHistory(string command)
{
    if (_history.size() < 3)
        _history.push(command);
    else if (_history.size() == 3)
    {
        stack<string> tempStack;
        while (_history.size() != 1)
        {
            tempStack.push(_history.top());
            _history.pop();
        }
        _history.pop();
        while(_history.size() != 2)
        {
            _history.push(tempStack.top());
            tempStack.pop();
        }
        _history.push(command);

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


void calender::undoOriginalEdits(task _oldTask)
{
    if (_originalEdits.size() < 3)
        _originalEdits.push(_oldTask);
    else if (_originalEdits.size() == 3)
    {
        stack<task> tempStack;
        while (_originalEdits.size() != 1)
        {
            tempStack.push(_originalEdits.top());
            _originalEdits.pop();
        }
        _originalEdits.pop();
        while(_originalEdits.size() != 2)
        {
            _originalEdits.push(tempStack.top());
            tempStack.pop();
        }
        _originalEdits.push(_oldTask);
    }

}

void calender::undoNewEdits(task _newTask)
{
    if (_newEdits.size() < 3)
        _newEdits.push(_newTask);
    else if (_newEdits.size() == 3)
    {
        stack<task> tempStack;
        while (_newEdits.size() != 1)
        {
            tempStack.push(_newEdits.top());
            _newEdits.pop();
        }
        _newEdits.pop();
        while(_newEdits.size() != 2)
        {
            _newEdits.push(tempStack.top());
            tempStack.pop();
        }
        _newEdits.push(_newTask);
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

