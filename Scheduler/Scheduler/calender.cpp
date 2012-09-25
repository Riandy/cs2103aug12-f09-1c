#include "calender.h"


calender::calender()
{
	_numberTasks = 0;
	
}

calender::~calender()
{
}

bool calender::addItem(task* currentTask)
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

// The only command available publicly. Scheduler will parse from Seample then send a string, and task.
void calender::execute(string command, task currentTask)
{
if (command=="add") 
{
	task* placeholderTask = &currentTask;
	this->addItem(placeholderTask);
}

// Can't really remember if I need to delete the memory space.
else if (command=="delete")
{
	task* placeholderTask = new task;
	placeholderTask = &currentTask;
	int IDTag = placeholderTask->_id;

	this->deleteItem(IDTag);

	delete placeholderTask;
}
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
		writeFile<<"Description : "<<_storage[i]->_description<<endl;
		writeFile<<"Start_Date : "<<_storage[i]->_startDate<<endl;
		writeFile<<"End_Date : "<<_storage[i]->_endDate<<endl;
		writeFile<<"Priority : "<<_storage[i]->_priority<<endl<<endl;
	}
	return true;
}
bool calender::loadFile()
{
	//clear all the content of the storage before loading the new one from
	//storage textfile

	_storage.clear();
	
	ifstream readFile("storage.txt");
	string temp,description;
	int priority,startDate,endDate,count=0;

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
		newTask->_startDate=startDate;
		newTask->_priority=priority;
		newTask->_endDate=endDate;
		newTask->_id=count;

		_storage.push_back(newTask);
	}
	return true;
}