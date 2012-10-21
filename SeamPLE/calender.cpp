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
	convert<< _date.tm_yday << " / " << _date.tm_mon << " / " << _date.tm_year << " - " ;
	convert<< _date.tm_hour << " : " << _date.tm_min << " : " << _date.tm_sec;
	_result=convert.str();
	//cout<<"YAY"<<_result<<endl;
	return _result;
}


bool calender::addItem(task currentTask)
{
	// currentTask.setID(_storage.size());
    saveHistory(_ADDITION);
	cout<<"add item is called"<<endl;
	cout<<"storage size after add"<<_storage.size()<<endl;
	_storage.push_back(currentTask);
	cout<<"storage size after add"<<_storage.size()<<endl;
	writeFile();
	return true;
}


bool calender::deleteItem(int taskID)
{
    saveHistory(_DELETE);
	saveDelete(taskID-1);
	_storage.erase(_storage.begin()+taskID-1);
	
	writeFile();
	return true;
}


bool calender::writeFile()
{
	ofstream writeFile("storage.txt");

	for (int i=0;i<int(_storage.size());i++)
	{
		writeFile<<"Description : "<<_storage[i].getEventName()<<endl;
		//changed to tm struct
		writeFile<<"Start_Date : "<<convertToDate(_storage[i].getStartDate())<<endl;
		writeFile<<"End_Date : "<<convertToDate(_storage[i].getEndDate())<<endl;
		writeFile<<"Priority : "<<_storage[i].getPriority()<<endl;
		writeFile<<"Category : "<<_storage[i].getCategory()<<endl<<endl;
		//cout<<"Test Date : "<<convertToDate(_storage[i].getStartDate())<<endl;
	}

	return true;
}

bool calender::checkID(int taskID)
{
	if (taskID > int(_storage.size()))
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
		if (bufferString.find(searchItem))
		{
			_bufferStorage.push_back(_storage[i]);
			
		}
	}
	return _bufferStorage;
} // please check the _bufferStorage.size() in the scheduler

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

	cout<<"Hello World"<<endl;
	
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
		//cout<<description<<endl;
		
		readFile>>temp;
		//cout<<temp;
		readFile>>temp;
		getline(readFile,startDate);
		istringstream iss(startDate);
		tm _startDate;
		iss >> _startDate.tm_yday;
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

		//cout<<_startDate.tm_yday<<" "<<_startDate.tm_sec<<endl;
		//cout<<description<<endl;
		//readFile>>startDate;
		//cout<<"date : "<<_startDate.tm_min<<endl;
		readFile>>temp;
		//cout<<temp;
		readFile>>temp;
		getline(readFile,endDate);
		istringstream isss(endDate);
		tm _endDate;
		isss >> _endDate.tm_yday;
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
		//cout<<_endDate.tm_yday<<" "<<_endDate.tm_sec<<endl;

		readFile>>temp;
		readFile>>temp;
		readFile>>priority;
		//cout<<priority<<endl;

		readFile>>temp;
		readFile>>temp;
		readFile>>category;
		//cout<<category<<endl;

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
	if (_redoHistory.size() == 0)
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

// NOT DONE
vector<task> calender::getToday() 
{
	vector<task> _bufferStorage;
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
