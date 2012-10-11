#include "calender.h"


calender::calender()
{
	_numberTasks = 0;
	
}

calender::~calender()
{
}

bool calender::addItem(task currentTask)
{
	_storage.push_back(currentTask);
	_numberTasks++;
	return true;
}

// The reason we delete at taskID-1 is because _storage.begin() is [0], but task ID starts from 
// 1 when the user is doing input. 
bool calender::deleteItem(int taskID)
{
	_storage.erase(_storage.begin() + (taskID-1));
	_numberTasks--;
	return true;
}


//Riandy, could you write these two? Don't have to append strings yet. Just basic saving per line.
// The vector is called _storage.
// Format should be integer for number of items, and cin to variable _numberTasks
// Then the description, date, date, priority. If you want you can issue an ID to the number as you load (just the [i] position + 1 in the for-loop)
bool calender::writeFile()
{
	ofstream writeFile("storage.txt");

	for (int i=0;i<int(_storage.size());i++)
	{
		writeFile<<"Description : "<<_storage[i]._description<<endl;
		//change to tm struct
		//writeFile<<"Start_Date : "<<_storage[i]._startDate<<endl;
		//writeFile<<"End_Date : "<<_storage[i]._endDate<<endl;
		writeFile<<"Priority : "<<_storage[i]._priority<<endl<<endl;
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

return true;
}

vector<task> calender::SearchByCat(string searchItem)
{
	
	vector<task> _bufferStorage;
	for (int i = 0; i < int(_storage.size()); i++)
	{
		string  bufferString = _storage[i]._category;
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
		string  bufferString = _storage[i]._description;
		if (bufferString.find(searchItem))
		{
			_bufferStorage.push_back(_storage[i]);
			
		}
	}
	return _bufferStorage;
} // please check the _bufferStorage.size() in the scheduler



vector<task> calender::displayDatabase()
{
    return _storage;
}




bool calender::loadFile()
{
	//clear all the content of the storage before loading the new one from
	//storage textfile

	_storage.clear();
	
	ifstream readFile("storage.txt");
	string temp,description;
	int priority,count=0;
	int startDate,endDate;

	while(readFile>>temp)
	{
		count++;
		//read the semicolon
		readFile>>temp;
		getline(readFile,description);

		readFile>>temp;
		readFile>>temp;
		readFile>>startDate;

		readFile>>temp;
		readFile>>temp;
		readFile>>endDate;
		
		readFile>>temp;
		readFile>>temp;
		readFile>>priority;

		task* newTask= new task;
		newTask->_description=description;
		//newTask->_startDate=startDate;
		newTask->_priority=priority;
		//newTask->_endDate=endDate;
		newTask->_id=count;

		_storage.push_back(*newTask);
	}
	return true;
}