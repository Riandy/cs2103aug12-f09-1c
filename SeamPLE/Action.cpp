#include "Action.h"

const  string Action::EMPTYCOMMAND = "";
//@PAN WENREN A0083711L
Action::Action(void)
{
    this->_command = EMPTYCOMMAND;
}


Action::~Action(void)
{
}


task Action::getTask()
{
    return _task;
}

void Action::setTask(task T)
{
    _task=T;
}

string Action::getEventName()
{
    return _task.getEventName();
}
void Action::setEventName(string name)
{
    _task.setEventName(name);
}



tm Action::getStartDate()
{
    return _task.getStartDate();
}
void Action::setStartDate(tm newDate)
{
    _task.setStartDate(newDate);

}

tm Action::getEndDate()
{
    return _task.getEndDate();
}
void Action::setEndDate(tm newDate)
{
    _task.setEndDate(newDate);

}

bool Action::checkDateEmpty(tm date)
{
    if(date.tm_year ==0 || date.tm_mon ==0 || date.tm_mday ==0)
    {
        return true;}
    else{
        return false;}
}

//@author: U094659H
void Action::determineDate(tm date1,tm date2)
{
    if(checkDateEmpty(date1))
    {
        setStartDate(date2);
        return;
    }
    if(date1.tm_year > date2.tm_year)
    {
        setStartDate(date2);setEndDate(date1);
        return;
    }else if(date2.tm_year>date1.tm_year)
    {
        setStartDate(date1);setEndDate(date2);
        return;
    }else if(date2.tm_year == date1.tm_year)
    {
        if(date1.tm_mon>date2.tm_mon)
        {
            setStartDate(date2);setEndDate(date1);
            return;
        }else if(date2.tm_mon > date1.tm_mon)
        {
            setStartDate(date1);setEndDate(date2);
            return;
        }else if(date1.tm_mon==date2.tm_mon)
        {
            if(date1.tm_mday>date2.tm_mday)
            {
                setStartDate(date2);setEndDate(date1);
                return;
            }else if(date2.tm_mday > date1.tm_mday)
            {
                setStartDate(date1);setEndDate(date2);
                return;
            }else if(date1.tm_mday == date2.tm_mday)
            {

                if(date1.tm_hour>date2.tm_hour)
                {
                    setStartDate(date2);setEndDate(date1);
                    return;
                }else if(date2.tm_hour > date1.tm_hour)
                {
                    setStartDate(date1);setEndDate(date2);
                    return;
                }else if(date2.tm_hour==date1.tm_hour)
                {
                    if(date1.tm_min>date2.tm_min)
                    {
                        setStartDate(date2);setEndDate(date1);
                        return;
                    }else if(date2.tm_min>date1.tm_min)
                    {
                        setStartDate(date1);setEndDate(date2);
                        return;
                    }else if (date1.tm_min==date2.tm_min)
                    {
                        setStartDate(date2);setEndDate(date1);
                        return;
                    }
                }
            }
        }
    }

}

//@PAN WENREN A0083711L
void Action::setStartDateWithoutTime(tm newDate)
{
    newDate.tm_hour     = 0;
    newDate.tm_min      = 0;
    _task.setStartDate(newDate);

}

string Action::getPriority()
{
    return _task.getPriority();
}
void Action::setPriority(string newPriority)
{
    _task.setPriority(newPriority);
}


string Action::getCommand()
{
    return this->_command;
}
void Action::setCommand(string newCommand)
{
    this->_command = newCommand;
}

string Action::getCategory()
{
    return _task.getCategory();
}
void Action::setCategory(string newCategory)
{
    _task.setCategory(newCategory);
}


int Action::getID()
{
    return _task.getID();
}
void Action::setID(int newID)
{
    _task.setID(newID);
}
int Action::getDateType()
{
    return _task.getDateType();
}
void Action::setDateType(int datetype)
{
    _task.setDateType(datetype);
}
