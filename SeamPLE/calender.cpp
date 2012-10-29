#include "calender.h"


calender::calender()
{
	calender::loadFile();
}

calender::~calender()
{
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
    saveHistory(_ADDITION);
	_storage.push_back(currentTask);


    if(writeFile())
        return true;
    else
        return false;
}


bool calender::deleteItem(int taskID)
{
    saveHistory(_DELETE);
	saveDelete(taskID-1);
	_storage.erase(_storage.begin()+taskID-1);	
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
    cout<<taskID<<endl;
    if (taskID > int(_storage.size()) || taskID<1)
		return false;
	else
		return true;
}


bool calender::editTask(task edited)
{
    saveHistory(_EDIT);
return true;
}

vector<task> calender::SearchByCat(string searchItem)
{
	
	vector<task> _bufferStorage;
	for (int i = 0; i < int(_storage.size()); i++)
	{
		string  bufferString = _storage[i].getCategory();
		if (bufferString.find(searchItem))
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
//start of ad hoc edit code
vector<task> calender::SearchByPartialTask(string searchItem)
{

    vector<task> _bufferStorage;
    for (int i = 0; i < int(_storage.size()); i++)
    {
        string  bufferString = _storage[i].getEventName();
        //str.find(str2)
        if (bufferString.find(searchItem)!=string::npos)
        {
            _bufferStorage.push_back(_storage[i]);
        }
    }
    return _bufferStorage;
}
//end of ad hoc edit code
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
	//@Riandy
	//clear all the content of the storage before loading the new one from
	//storage textfile
	_storage.clear();
	
	ifstream readFile("storage.txt");
	
	string temp,description,priority,category;
	char space;

	string startDate,endDate;
	//variable temp is used to read unecessary string/ character

	while(readFile>>temp)
	{
	
	
		//read the semicolon
		readFile>>temp;
		//read the space
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

// Allow 3 undo, allow one redo. 
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
			int ID = _storage.size()-1;

			_redoHistory.push(_storage[ID]);
			_storage.erase(_storage.begin()+ID);

		}
        else if (lastCommand == _DELETE)
		{
            _redoCommands.push(_DELETE);
			task tempTask = _deleteHistory.top();
			_storage.push_back(tempTask);
			_deleteHistory.pop();
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
		_redoCommands.pop();
		_redoHistory.pop();

		}
        else if (_redoCommands.top() == _DELETE)
		{
			int taskID = _storage.size();
			
			saveDelete(taskID-1);
			_storage.erase(_storage.begin()+taskID-1);
	
            saveHistory(_DELETE);
			_redoCommands.pop();
			
		}
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

	// Following ensures the stack size remains <= 3
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
