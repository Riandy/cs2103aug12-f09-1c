#include "calender.h"


calender::calender()
{
    _numberTasks = 0;
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
    currentTask.setID(++_numberTasks);

    cout<<"storage size after add"<<_storage.size()<<endl;
    _storage.push_back(currentTask);
    cout<<"storage size after add"<<_storage.size()<<endl;
    writeFile();
    //_numberTasks++;
    return true;
}

// The reason we delete at taskID-1 is because _storage.begin() is [0], but task ID starts from
// 1 when the user is doing input.
bool calender::deleteItem(int taskID)
{

    _storage.erase(_storage.begin()+taskID-1);
    _numberTasks--;
    writeFile();
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
    _numberTasks=0;
    string startDate,endDate;
    //variable temp is used to read unecessary string/ character

    while(readFile>>temp)
    {
        _numberTasks++;

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
        newTask->setID(_numberTasks);
        newTask->setEventName(description);
        newTask->setStartDate(_startDate);
        newTask->setEndDate(_endDate);
        newTask->setPriority(priority);
        newTask->setCategory(category);
        _storage.push_back(*newTask);

    }
    return true;
}
