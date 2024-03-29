#include "Intellisense.h"
#include "ndebug.h"



const string Intellisense::months[24] = {"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};


//important date events
imptDate imptDates[]= {  imptDate("CHRISTMAS","2512"),imptDate("NEWYEAR","0101")};
int imptDatesSize = 2;

const string Intellisense::ADDCOMMAND               = "ADD";
const string Intellisense::DELETECOMMAND            = "DELETE";
const string Intellisense::DISPLAYCOMMAND           = "DISPLAY";
const string Intellisense::MARKCOMMAND              = "MARK";
const string Intellisense::SORTCOMMAND              = "SORT";
const string Intellisense::FINDCOMMAND              = "FIND";
const string Intellisense::EDITCOMMAND              = "EDIT";
const string Intellisense::EDITENTERCOMMAND         = "EDITENTER";
const string Intellisense::EXITCOMMAND              = "EXIT";
const string Intellisense::UNDOCOMMAND              = "UNDO";
const string Intellisense::REDOCOMMAND              = "REDO";
const string Intellisense::TODOCOMMAND              = "TODO";
const string Intellisense::TODAYCOMMAND             = "TODAY";
const string Intellisense::DISPLAYARCHIVECOMMAND    = "DISPLAYARCHIVE";

//changed to array test
const string Intellisense::addCommandArray[]            = { "add", "-a", "create" ,"new","++","-a"};
const string Intellisense::deleteCommandArray[]         = { "delete","del","dd","cancel","-d" };
const string Intellisense::markCommandArray[]           = { "mark", "done","-m"};
const string Intellisense::displayCommandArray[]        = { "display" ,"show","-d","dsp"};
const string Intellisense::exitCommandArray[]           = {"exit","quit","-q"};
const string Intellisense::sortCommandArray[]           = {"sort","arrange","-s"};
const string Intellisense::findCommandArray[]           = {"find","search","-f"};
const string Intellisense::editCommandArray[]           = {"edit","change","-e","defer","reschedule","change"};
const string Intellisense::undoCommandArray[]           = {"undo","revert","-u"};
const string Intellisense::redoCommandArray[]           = {"redo","-r"};
const string Intellisense::todoCommandArray[]           = {"todo"};
const string Intellisense::todayCommandArray[]          = {"today"};
const string Intellisense::displayarchiveCommandArray[] = {"displayarchive"};


const string Intellisense::EMPTYCATEGORY                = "#";
const string Intellisense::EMPTYEVENT                   = "";
const string Intellisense::EMPTYPRIORITY                = "";
const int    Intellisense::EMPTYID                      = -1;
const string Intellisense::HIGHPRIORITY                 = "HIGH";
const string Intellisense::HIGHPRIORITY_L               = "high";
const string Intellisense::LOWPRIORITY                  = "LOW";
const string Intellisense::LOWPRIORITY_L                = "low";

const string Intellisense::WEEKLY                       = "weekly";
const string Intellisense::MONTHLY                      = "monthly";
const string Intellisense::FORTNIGHTLY                  = "fortnightly";

const string Intellisense::ADDFEEDBACK_1                = "eg. add Mum's Birthday 24012012 25122012 HIGH #family";
const string Intellisense::ADDFEEDBACK_2                = "eg. add Mum's Birthday 24012012 25122012 HIGH #family";
const string Intellisense::EDITFEEDBACK_1               = "eg. edit Jogging at the Park #HIGH <font color = LemonChiffon>OR</font> edit Jogging at the Park 25122012";
const string Intellisense::EDITFEEDBACK_2               = "eg. edit Jogging at the Park #HIGH <font color = LemonChiffon>OR</font> edit Jogging at the Park 25122012";
const string Intellisense::DELFEEDBACK_1                = "eg. del 3   <font color = LemonChiffon>OR</font> eg. del Mum's Birthday";
const string Intellisense::DELFEEDBACK_2                = "eg. del 3   <font color = LemonChiffon>OR</font> eg. del Mum's Birthday";
const string Intellisense::EXITFEEDBACK_1               = " Are you sure you want to exit?";
const string Intellisense::DISPLAYFEEDBACK_1            = "Display will show all events. Press Enter to continue.";
const string Intellisense::DISPLAYFEEDBACK_2            = "Display will show all events. Press Enter to continue.";
const string Intellisense::FINDFEEDBACK_1               = "eg.find birthday <font color = LemonChiffon>OR</font>  eg.find 24012012 <font color = LemonChiffon>OR</font> eg.find #SPORTS";
const string Intellisense::FINDFEEDBACK_2               = "eg.find birthday <font color = LemonChiffon>OR</font>  eg.find 24012012 <font color = LemonChiffon>OR</font> eg.find #SPORTS";
const string Intellisense::SORTFEEDBACK_1               = " The Events Will be Sorted By Date";
const string Intellisense::SORTFEEDBACK_2               = " The Events Will be Sorted By Date";
const string Intellisense::REDOFEEDBACK_1               = "Press enter to redo your last operation";
const string Intellisense::UNDOFEEDBACK_1               = "Press enter to undo your last operation";
const string Intellisense::MARKFEEDBACK_1               = "eg. mark  Dinner with Myat";
const string Intellisense::MARKFEEDBACK_2               = "eg. mark  Dinner with Myat";

const  string Intellisense::GREENEVENTTEXT              = "<font color=Chartreuse >[EventNAME] </font>";
const  string Intellisense::REDEVENTTEXT                = "<font color=Salmon >[EventNAME] </font>";

const  string Intellisense::GREENSTARTDATETEXT          = "<font color=Chartreuse>[StartDate] </font>" ;
const  string Intellisense::REDSTARTDATETEXT            = "<font color=Salmon   >[StartDate] </font>";

const  string Intellisense::GREENENDDATETEXT            = "<font color=Chartreuse>[EndDate] </font>";
const  string Intellisense::REDENDDATETEXT              = "<font color=Salmon  >[EndDate] </font>";

const  string Intellisense::GREENPRIORITYTEXT           = "<font color=Chartreuse>[PRIORITY] </font>";
const  string Intellisense::REDPRIORITYTEXT             = "<font color=Salmon>[PRIORITY] </font>";

const  string Intellisense::GREENCATEGORYTEXT           = "<font color=Chartreuse>[CATEGORY] </font>";
const  string Intellisense::REDCATEGORYTEXT             = "<font color=Salmon >[CATEGORY] </font>";

const  string Intellisense::GREENIDTEXT                 = "<font color=Chartreuse>[ID] </font>";
const  string Intellisense::REDIDTEXT                   = "<font color=Salmon>[ID] </font>";

const string Intellisense::LINEBREAK                    = "<br>";

const char Intellisense::CATEGORYRECOGNISER             = '#' ;




bool Intellisense::instanceFlag = false;
Intellisense* Intellisense::intellisense = NULL;

//@author: U094659H
//returns a char in lower case
char toLower(char in){
    if(in<='Z' && in>='A')
    { return in-('Z'-'z');}
    return in;
}


//@author: U094659H
//singleton pattern instance
Intellisense* Intellisense::getInstance()
{
    if(!instanceFlag)
    {
        intellisense = new Intellisense();
        instanceFlag=true;
        return intellisense;
    }
    else
    {
        return intellisense;
    }

}
//@author: U094659H
//singleton constructor
Intellisense::Intellisense(void)
{
    initFlags();

    logger->getInstance();
}

void Intellisense::initFlags()
{
    for(int i=0; i<MAXNOOFPARAMETERS; i++)
    {
        statusFlags[i] = true;
    }
    requirementsMet = false;
}


//@author: U094659H
Intellisense::~Intellisense(void)
{
    instanceFlag=false;
    logger->endInstance();
}

//@author: U094659H
//parses string input and perfom task according the command word detected
//return a action class containing the parsed information in each fields
Action Intellisense::check(string query)
{
    Action task;
    ASSERT(query.size()<query.max_size(),"query size exceed max string size");
    trim(query);

    vector<string> buffer = tokenize(query);

    switch(determinOperation(buffer))
    {
    case ADD:
        task = addOperation(buffer);
        break;
    case DELETE:
        task = deleteOperation(buffer);
        break;
    case DISPLAY:
        task = displayOperation(buffer);
        break;
    case MARK:
        task = markOperation(buffer);
        break;
    case SORT:
        task = sortOperation(buffer);
        break;
    case FIND:
        task = findOperation(buffer);
        break;
    case EDIT:
        task = editOperation(buffer);
        break;
    case EXIT:
        task = exitOperation(buffer);
        break;
    case INVALID:
        task = quickAddOperation(buffer);
        break;
    case UNDO:
        task = undoOperation(buffer);
        break;
    case REDO:
        task = redoOperation(buffer);
        break;
    case TODO:
        task = todoOperation(buffer);
        break;
    case TODAY:
        task = todayOperation(buffer);
        break;
    case DISPLAYARCHIVE:
        task = displayarchiveOperation(buffer);
        break;

    default:
        logger->report("@Intellisense -> Unexpected command received" + determinOperation(buffer));    //logging the unexpected command
        ASSERT(false,"Command is not recognised");
        break;
    }


    return task;
}



//@author: U094659H
//returns operation type based on the first string token
operation Intellisense::determinOperation(vector<string>& tokens)
{

    if(tokens.size() == 0)
    {
        return INVALID;    //Defensive coding: prevents empty input to pass through
    }

    string commandword=tokens[0];
    if(checkCommandArray(commandword,addCommandArray, sizeof(addCommandArray)/sizeof(string) ))//the sizeof operator  have to work at this level of abstraction due to auto convertion of array to pointer and arraysize information loss
    {
        return ADD;
    }else if(checkCommandArray(commandword,deleteCommandArray,sizeof(deleteCommandArray)/sizeof(string)))
    {
        return DELETE;
    }else if(checkCommandArray(commandword,todayCommandArray,sizeof(todayCommandArray)/sizeof(string)))
    {
        return TODAY;
    }else if(checkCommandArray(commandword,editCommandArray,sizeof(editCommandArray)/sizeof(string)))
    {
        return EDIT;
    }else if(checkCommandArray(commandword,markCommandArray,sizeof(markCommandArray)/sizeof(string)))
    {
        return MARK;
    }else if(checkCommandArray(commandword,findCommandArray,sizeof(findCommandArray)/sizeof(string)))
    {
        return FIND;
    }else if(checkCommandArray(commandword,sortCommandArray,sizeof(sortCommandArray)/sizeof(string)))
    {
        return SORT;
    }else if(checkCommandArray(commandword,displayCommandArray,sizeof(displayCommandArray)/sizeof(string)))
    {
        return DISPLAY;
    }else if(checkCommandArray(commandword,exitCommandArray,sizeof(exitCommandArray)/sizeof(string)))
    {
        return EXIT;
    }
    else if(checkCommandArray(commandword,undoCommandArray,sizeof(undoCommandArray)/sizeof(string)))
    {
        return UNDO;
    }
    else if(checkCommandArray(commandword,redoCommandArray,sizeof(redoCommandArray)/sizeof(string)))
    {
        return REDO;
    }else if(checkCommandArray(commandword,displayarchiveCommandArray,sizeof(displayarchiveCommandArray)/sizeof(string)))
    {
        return DISPLAYARCHIVE;
    }
    else if(checkCommandArray(commandword,todoCommandArray,sizeof(todoCommandArray)/sizeof(string)))
    {
        return TODO;
    }
    else
    {
        return INVALID;
    }
}

//@author: U094659H
//compares 2 strings words irregardless of upper/lower casing
//returns true if both strings are the same, false otherwise
bool Intellisense::checkString(const string& input, const string& command)
{
    if(input.size() != command.size())
    {
        return false;
    }

    for(string::const_iterator s1=input.begin(),s2=command.begin();s1!=input.end();++s1,++s2)    //converts both strings to lower cases for fair comparison
    {
        if(tolower(*s1) != tolower(*s2))
        {
            return false;
        }
    }
    return true;
}
//@author: A0083711L
//returns a string to lower casing
string Intellisense::toLowerString(string input)
{
    transform(input.begin(), input.end(), input.begin(),toLower);
    return input;
}

//@author: A0083711L
bool Intellisense::checkCommandArray(const string& input, const string command[],int arraySize)
{
    ASSERT(arraySize!= 0,"Available command cannot be 0.");
    ASSERT(command!= NULL,"null command array pointer in check command");
    bool isCommandFound = false;
    string inputBuffer;
    string commandBuffer;
    inputBuffer = toLowerString(input);
    try
    {
        for (int i = 0 ; i < arraySize; i++)
        {
            commandBuffer = toLowerString(command[i]);
            if(inputBuffer == commandBuffer)
                isCommandFound = true;
        }

        return isCommandFound;
    }
    catch(exception& e)
    {
        logger->report("@Intelliense -> exception caught:" + string(e.what()));
        return false;
    }

}
//@author: U094659H
//returns the first string token
string Intellisense::getfirst_Word(string command)
{
    return tokenize(command)[0];
}

//@author: U094659H
//returns the command word from string tokens
string Intellisense::getCommand(vector<string>& tokens,string _command)
{
    vector<string>::iterator it=tokens.begin();
    string command = _command;
    it=tokens.erase(it);

    return command;
}
//@author: U094659H
//returns an int representing an ID
int Intellisense::getID(vector<string>& tokens)
{
    if(tokens.size()==0 || isAllInt(tokens.front())== false || tokens.size()>2)
    {
        return -1;
    }
    else
    {
        return atoi(tokens.front().c_str());
    }

}

//@author: U094659H
//returns HIGH or LOW if keyword "HIGH" or "LOW" is detected at the head or end of token
string Intellisense::getPriority(vector<string>& tokens)
{
    if(tokens.size()>0) //defensive
    {
        string checkHeadString =  tokens.front();    //check the first word in string
        string checkTailString =  tokens.back();     //check the last word in string



        if((checkHeadString.compare(HIGHPRIORITY)==0)|| checkHeadString.compare(HIGHPRIORITY_L)==0)
        {
            tokens.erase(tokens.begin());
            return HIGHPRIORITY;
        }

        if((checkTailString.compare(HIGHPRIORITY)==0)|| checkTailString.compare(HIGHPRIORITY_L)==0)
        {
            tokens.pop_back();
            return HIGHPRIORITY;
        }
        if((checkHeadString.compare(LOWPRIORITY)==0)|| checkHeadString.compare(LOWPRIORITY_L)==0)
        {
            tokens.erase(tokens.begin());
            return LOWPRIORITY;
        }
        if((checkTailString.compare(LOWPRIORITY)==0)|| checkTailString.compare(LOWPRIORITY_L)==0)
        {
            tokens.pop_back();
            return LOWPRIORITY;
        }

    }
    return EMPTYPRIORITY;
}

//@author: U094659H
//returns a struct tm which contains the date and time after parsing through the tokens
//different processing is performed based on the size of string
tm Intellisense::getTime(vector<string>& tokens,tm &date)
{
    string time;

    vector<string>::iterator it=tokens.begin();
    while (it!=tokens.end())  //defensive, better than "for loop", ensures that will not get out of range
    {
        time=it->c_str();
        switch(time.size())
        {

        case 3:   if( processTimeFormat1(date, time))
            {it=tokens.erase(it);
                return date;}
            break;

        case 4:   if(processTimeFormat2(date, time))
            {it=tokens.erase(it);
                return date;}
            if(processTimeFormat8(date, time))
            {it=tokens.erase(it);
                return date;}
            break;

        case 5: if(processTimeFormat3(date, time))
            {it=tokens.erase(it);
                return date;}
            if(processTimeFormat5(date, time))
            {it=tokens.erase(it);
                return date;}
            break;

        case 6:if(processTimeFormat4(date,time))
            {it=tokens.erase(it);
                return date;}
            if(processTimeFormat6(date,time))
            {it=tokens.erase(it);
                return date;}
            break;

        case 7:   if(processTimeFormat7(date,time))
            {it=tokens.erase(it);
                return date;}
            break;


        default:break;

        }

        if (it!=tokens.end())
            ++it;//only increment if it is not the last position
    }

    return date;
}

//@author: U094659H
//returns true if time is detected, date.tm_hour & date.tm_min is updated
//function checks for time format "x:xx"
bool Intellisense::processTimeFormat8 (tm &date, string time)
{
    if(time.at(1) == ':' )
    {
        if(time.size()==4)
        {
            time=removeChar(time,":");
            if(isAllInt(time))
            {

                date.tm_hour=atoi(time.substr(0,1).c_str());
                date.tm_min=atoi(time.substr(1,2).c_str());
                return true;
            }

        }
    }
    return false;
}

//@author: U094659H
//returns true if time is detected, date.tm_hour & date.tm_min is updated
//function checks for time format "12:xxPM"
bool Intellisense::processTimeFormat7 (tm &date, string checkString)
{
    if(checkString.at(2) == '.'  || checkString.at(2) == ':' )
    {
        checkString=removeChar(checkString,":.");
        if(processTimeFormat6(date, checkString))
        {return true;}
    }

    return false;
}

//@author: U094659H
//returns true if time is detected, date.tm_hour & date.tm_min is updated
//function checks for time format "12xxPM"
bool Intellisense::processTimeFormat6 (tm &date, string time)
{
    if(checkString("PM",time.substr(4,2))|| checkString("AM",time.substr(4,2)))
    {
        if(isAllInt(time.substr(0,4)))
        {

            if(checkString("PM",time.substr(4,2)))
            {
                date.tm_hour=atoi(time.substr(0,2).c_str())+12;\
                if(date.tm_hour>=24)
                { date.tm_hour = 0;}
                date.tm_min=atoi(time.substr(2,2).c_str());
                return true;
            }
            else
            {
                date.tm_hour=atoi(time.substr(0,2).c_str());
                date.tm_min=atoi(time.substr(2,2).c_str());
                return true;
            }

        }
    }

    return false;
}

//@author: U094659H
//returns true if time is detected, date.tm_hour & date.tm_min is updated
//function checks for time format "9xxPM"
bool Intellisense::processTimeFormat5 (tm &date, string time)
{
    if(checkString("PM",time.substr(3,2))|| checkString("AM",time.substr(3  ,2)))
    {
        if(isAllInt(time.substr(0,3)))
        {

            if(checkString("PM",time.substr(3,2)))
            {
                date.tm_hour=atoi(time.substr(0,1).c_str())+12;
                date.tm_min=atoi(time.substr(1,2).c_str());
                return true;
            }
            else
            {
                date.tm_hour=atoi(time.substr(0,1).c_str());
                date.tm_min=atoi(time.substr(1,2).c_str());
                return true;

            }

        }

    }

    return false;
}
//@author: U094659H
//returns true if time is detected, date.tm_hour & date.tm_min is updated
//function checks for time format "9:xxPM"
bool Intellisense::processTimeFormat4 (tm &date, string checkString)
{
    if(checkString.at(1) == '.'  || checkString.at(1) == ':' )
    {
        checkString=removeChar(checkString,":.");
        if(processTimeFormat5(date, checkString))
        {return true;}
    }

    return false;
}
//@author: U094659H
//returns true if time is detected, date.tm_hour & date.tm_min is updated
//function checks for time format "xx:xx"
bool Intellisense::processTimeFormat3 (tm &date, string time)
{
    if(time.at(2) == ':' )
    {
        if(time.size()==5)
        {
            time=removeChar(time,":");
            if(isAllInt(time))
            {

                date.tm_hour=atoi(time.substr(0,2).c_str());
                date.tm_min=atoi(time.substr(2,2).c_str());
                return true;
            }

        }
    }
    return false;
}

//@author: U094659H
//returns true if time is detected, date.tm_hour & date.tm_min is updated
//function checks for time format "XXPM" . e.g. 12PM
bool Intellisense::processTimeFormat2 (tm &date, string time)
{
    if(checkString("PM",time.substr(2,2))|| checkString("AM",time.substr(2,2)))
    {
        if(isAllInt(time.substr(0,2)))
        {

            if(checkString("PM",time.substr(2,2)))
            {
                date.tm_hour=atoi(time.substr(0,2).c_str())+12;
                date.tm_min=atoi(time.substr(2,2).c_str());

            }
            else
            {
                date.tm_hour=atoi(time.substr(0,2).c_str());
                date.tm_min=atoi(time.substr(2,2).c_str());

            }
            return true;
        }
    }

    return false;
}
//@author: U094659H
//returns true if time is detected, date.tm_hour & date.tm_min is updated
//function checks for time format "XPM" . e.g. 1PM
bool Intellisense::processTimeFormat1 (tm &date, string time)
{

    if(checkString("PM",time.substr(1,2))|| checkString("AM",time.substr(1,2)))
    {
        if(isAllInt(string(1,time.at(0))))
        {


            if(checkString("PM",time.substr(1,2)))
            {
                date.tm_hour=atoi(time.substr(0,2).c_str())+12;
                date.tm_min=atoi(time.substr(2,2).c_str());

            }
            else
            {
                date.tm_hour=atoi(time.substr(0,2).c_str());
                date.tm_min=atoi(time.substr(2,2).c_str());

            }

            return true;

        }
    }
    return false;
}

//@author: A0083711L
//returns a string contain the category
//fucntion parsers the token for category word based on identifier
string Intellisense::getCategory(vector<string>& tokens)
{
    string category = EMPTYCATEGORY;
    vector<string>::iterator it=tokens.begin();
    while(it!=tokens.end())
    {
        if(it->at(0) == CATEGORYRECOGNISER)
        {
            category = it->substr(1,it->size()-1);
            it = tokens.erase(it);
            break;
        }

        if(it != tokens.end())
        {
            it++;//only increment if it is not the last position
        }
    }
    return category;
}

//@author: U094659H
//removes characters from string as indicated
string Intellisense::removeChar(string s,char chars[])
{
    for (unsigned int i = 0; i < sizeof(chars); ++i)
    {
        s.erase (std::remove(s.begin(), s.end(), chars[i]), s.end());
    }
    return s;
}
//@author: U094659H
//removes blank spaces from the front of the string
string& Intellisense::trim_left_inplace( string& s,  const string& delimiters)
{
    return s.erase(  0, s.find_first_not_of( delimiters ) );
}
//@author: U094659H
//removes blank spaces from back of string
string& Intellisense::trim_right_inplace( string& s, const string& delimiters)
{
    return s.erase( s.find_last_not_of( delimiters ) + 1 );
}
//@author: U094659H
//removes blank spaces from front and back of string
string& Intellisense::trim(string& s ,const string& delimiters )
{
    return trim_left_inplace( trim_right_inplace( s, delimiters ), delimiters );
}

//@author: U094659H
//checks for the string idenifier and returns the date for the holiday event
void Intellisense::getImptDate(string _date, tm &date)
{
    time_t timeNow;
    struct tm * timeinfo;
    time (&timeNow);
    timeinfo = localtime ( &timeNow );     // get current date time information

    date.tm_mday=atoi(_date.substr(0,2).c_str());
    date.tm_mon=atoi(_date.substr(2,2).c_str());
    date.tm_year=timeinfo->tm_year+1900;   // get current year format


    return ;
}


//@author: U094659H
//retrieve date holiday event keywords such as "CHRISTMAS" & "NEWYEAR"
//functions updates the date with the occasion
bool Intellisense::checkImptDate(vector<string>& tokens, tm &date)
{
    string checkString;
    vector<string>::iterator it1=tokens.begin();
    while (it1!=tokens.end())
    {
        checkString = it1->c_str();
        for(int i =0; i<=imptDatesSize;i++)
        {
            if(checkString.compare(imptDates[i].name)==0)
            {
                getImptDate(imptDates[i].date, date);
                return true;
            }
        }

        if (it1!=tokens.end())
            ++it1;//only increment if it is not the last position

    }

    return false;
}

//@author: U094659H
//returns true if date format is identified
// function checks for date format in the form "DDMMYYYY"
bool Intellisense::checkDateFormat1(string checkString, tm &date)
{
    if(isAllInt(checkString))
    {

        date.tm_mday=atoi(checkString.substr(0,2).c_str());
        date.tm_mon=atoi(checkString.substr(2,2).c_str());
        date.tm_year=atoi(checkString.substr(4,4).c_str());
        return true;
    }

    return false;
}
//@author: U094659H
//returns true if date format is identified
// function checks for date format in the form "DD/MM/YYYY"
bool Intellisense::checkDateFormat2(string checkString, tm &date)
{
    if(checkString.at(2) == '\\' && checkString.at(5)=='\\'  || checkString.at(2) == '/' && checkString.at(5)=='/' ||  checkString.at(2)=='.' &&checkString.at(5)=='.' )
    {
        checkString=removeChar(checkString,"/\\.");
        if(isAllInt(checkString))
        {

            date.tm_mday=atoi(checkString.substr(0,2).c_str());
            date.tm_mon=atoi(checkString.substr(2,2).c_str());
            date.tm_year=atoi(checkString.substr(4,4).c_str());
            return true;
        }
    }

    return false;
}
//@author: U094659H
//returns true if date format is identified
// function checks for date format in the form "D/M/YYYY"
bool Intellisense::checkDateFormat3(string checkString, tm &date)
{
    if(checkString.at(1) == '\\' && checkString.at(3)=='\\'  || checkString.at(1) == '/' && checkString.at(3)=='/' ||  checkString.at(1)=='.' &&checkString.at(3)=='.' )
    {
        checkString=removeChar(checkString,"/\\.");
        if(isAllInt(checkString))
        {

            date.tm_mday=atoi(checkString.substr(0,1).c_str());
            date.tm_mon=atoi(checkString.substr(1,1).c_str());
            date.tm_year=atoi(checkString.substr(2,4).c_str());
            return true;
        }
    }

    return false;
}
//@author: U094659H
//returns true if date format is identified
// function checks for date format in the form "DD/M/YYYY"
bool Intellisense::checkDateFormat4(string checkString, tm &date)
{
    if(checkString.at(2) == '\\' && checkString.at(4)=='\\'  || checkString.at(2) == '/' && checkString.at(4)=='/' ||  checkString.at(2)=='.' &&checkString.at(4)=='.' )
    {
        checkString=removeChar(checkString,"/\\.");
        if(isAllInt(checkString))
        {

            date.tm_mday=atoi(checkString.substr(0,2).c_str());
            date.tm_mon=atoi(checkString.substr(2,1).c_str());
            date.tm_year=atoi(checkString.substr(3,4).c_str());
            return true;
        }
    }

    return false;
}
//@author: U094659H
//returns true if date format is identified
// function checks for date format in the form "D/MM/YYYY"
bool Intellisense::checkDateFormat5(string checkString, tm &date)
{
    if(checkString.at(1) == '\\' && checkString.at(4)=='\\'  || checkString.at(1) == '/' && checkString.at(4)=='/' ||  checkString.at(1)=='.' &&checkString.at(4)=='.' )
    {
        checkString=removeChar(checkString,"/\\.");
        if(isAllInt(checkString))
        {

            date.tm_mday=atoi(checkString.substr(0,1).c_str());
            date.tm_mon=atoi(checkString.substr(1,2).c_str());
            date.tm_year=atoi(checkString.substr(3,4).c_str());
            return true;
        }
    }

    return false;
}
//@author: U094659H
//returns true if date format is identified
//functions checks for date in numerical entered by user and updates the fields in structure date
//string format example " 16/5/2013 "
bool Intellisense::checkDateNumericalFormat(vector<string>& tokens, tm &date)
{
    string checkString;
    vector<string>::iterator it=tokens.begin();
    while (it!=tokens.end())
    {
        checkString = it->c_str();

        switch(checkString.size()){

        case 8:if(checkDateFormat1(checkString, date))
            {it=tokens.erase(it);
                return true;}
            if(checkDateFormat3(checkString, date))
            {it=tokens.erase(it);
                return true;}
            break;
        case 9:if(checkDateFormat4(checkString, date))
            {it=tokens.erase(it);
                return true;}
            if(checkDateFormat5(checkString, date))
            {it=tokens.erase(it);
                return true;}
            break;


        case 10:if(checkDateFormat2(checkString, date))
            {it=tokens.erase(it);
                return true;}
            break;

        default : break;
        }

        if (it!=tokens.end())
            ++it;//only increment if it is not the last position


    }
    return false;
}
//@author: U094659H
//returns true if date format is identified
//functions checks for date in string entered by user and updates the fields in structure date
//string format example " 16 may 2013 "
bool Intellisense::checkDateStringFormat(vector<string>& tokens, tm &date)
{
    string checkString;
    vector<string>::iterator it=tokens.begin();

    while (it!=tokens.end())
    { checkString = it->c_str();
        if(tokens.size()>=3)
        {
            int check=checkDateString(checkString);

            if(check !=-1)
            {
                it--;
                vector<string>::iterator it_day = it++;

                if(++it == tokens.end())
                {                // wenbin's own note, iterator unexplained
                    return false;
                }
                --it;
                vector<string>::iterator it_year = ++it;

                string day =it_day->c_str();
                if(day.size()>2 || day.size()<=0 || !isAllInt(day))
                {
                    return false;
                }
                string year = it_year->c_str();
                if(year.size()!=4 || !isAllInt(year))
                {
                    return false;
                }
                if(atoi(day.c_str())<=0 || atoi(year.c_str())<=0)
                {

                    return false;
                }
                int month = check;
                if(month>12)
                {month -=12;}

                it_day=tokens.erase(it_day);
                it_day=tokens.erase(it_day);
                it_day=tokens.erase(it_day);

                it=it_day;

                date.tm_mday=atoi(day.c_str());
                date.tm_mon=month;
                date.tm_year=atoi(year.c_str());
                return true;


            }
        }



        if (it!=tokens.end())
            ++it;//only increment if it is not the last position
    }

    return false;
}

//@author: U094659H
//returns a tm struct containing date which user entered
tm Intellisense::getDate(vector<string>& tokens)
{

    tm date;
    date.tm_hour=NULL;
    date.tm_min=NULL;
    date.tm_sec=NULL;
    date.tm_mday=NULL;
    date.tm_mon=NULL;
    date.tm_year=NULL;


    if(checkImptDate(tokens, date))
    {return date=getTime(tokens,date);}

    else if(checkDateNumericalFormat(tokens,date))
    {return date=getTime(tokens,date);}


    else if(checkDateStringFormat(tokens,date))
    {return date=getTime(tokens,date);}

    else
    {return date=getTime(tokens,date);}


}


//@author: U094659H
//returns an int representative of month
//example. march = 3
int Intellisense::checkMonthByString(string token)
{
    for(int i=0;i<=11;++i)
    {
        if(checkString(token,months[i]))
        {
            return i+1;
        }
    }

    return -1;
}

//@author: A0083711L
//returns the string containing event description
string Intellisense::getEventName(vector<string>& tokens)
{
    stringstream ss;

    vector<string>::iterator it=tokens.begin();
    while (it!=tokens.end())
    {
        ss<<it->c_str();
        ++it;
        if (it!=tokens.end())
        {
            ss<<string(" ");
        }
    }
    return ss.str();
}

//@author: A0083711L
//returns the datetype indicated by user
int Intellisense::getDateType(vector<string>& tokens)
{
    int dType = task::DATENORMAL;      //Defensive coding: default normal if cant find other date types
    vector<string>::iterator it=tokens.begin();
    while(it!=tokens.end())
    {
        string lowerString = toLowerString(*it);
        if(checkDateType(lowerString))
        {
            dType = checkDateType(lowerString);
            it = tokens.erase(it);
        }
        if(it!= tokens.end())
            it++;//increment if it is not the last iterator

    }
    return dType;

}
//@author: A0083711L
int Intellisense::checkDateType(string lowerString)
{
    int dateTypeFound = task::DATENORMAL;

    if( lowerString == WEEKLY )
    {
        dateTypeFound = task::DATEWEEKLY;
    }
    else if(lowerString == FORTNIGHTLY)
    {
        dateTypeFound = task::DATEFORTNIGHTLY;
    }
    else if( lowerString == MONTHLY)
    {
        dateTypeFound = task::DATEMONTHLY;
    }

    return dateTypeFound;
}
//@author: U094659H
//returns true if string input only contains integer
bool Intellisense::isAllInt(const string& s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(! (s[i] >= '0' && s[i] <= '9' || s[i] == ' ') )
        {
            return false;
        }
    }
    return true;
}

//@author: U094659H
//string tokenizer
//returns a vector of tokens
vector<string> Intellisense::tokenize(string command)
{
    vector<string> token;
    char *cstr, *p;

    string str = command;
    cstr = new char [str.size()+1];
    strcpy(cstr, str.c_str());

    p=strtok (cstr," ");
    while (p!=NULL)
    {
        token.push_back(p);
        p=strtok(NULL," ");
    }
    delete[] cstr;

    return token;
}

//@author: A0083711L
//Performs operation "add" command
//returns an Action package containin user input and fields
Action Intellisense::addOperation(vector<string>& tokens)
{
    currentCommand = ADD;
    Action task;
    task.setCommand(getCommand(tokens,ADDCOMMAND));
    task.determineDate(getDate(tokens),getDate(tokens));
    task.setCategory(getCategory(tokens));
    task.setPriority(getPriority(tokens));
    task.setDateType(getDateType(tokens));
    task.setEventName(getEventName(tokens));
    setAllStatusFlag(task);
    checkAddReq();
    smartAutoFill(task,tokens);//auto fill some of the fields that are unentered

    return task;
}
//@author: A0083711L
//Performs operation "delete" command
//returns an Action package containin user input and fields
Action Intellisense::deleteOperation(vector<string>& tokens)
{
    currentCommand = DELETE;
    Action task;
    task.setCommand(getCommand(tokens,DELETECOMMAND));
    int ID = getID(tokens);
    if(ID == -1)
    {
        task.setEventName(getEventName(tokens));
    }else
    {
        task.setID(ID);
    }

    setAllStatusFlag(task);
    checkDelReq();

    return task;
}

//@author: A0083711L
//Performs operation "exit" command
//returns an Action package containin user input and fields
Action Intellisense::exitOperation(vector<string>& tokens)
{
    currentCommand = EXIT;
    Action task;
    task.setCommand(getCommand(tokens,EXITCOMMAND));
    setAllStatusFlag(task);
    checkExitReq();
    return task;
}

//@author: A0083711L
//Performs operation "display" command
//returns an Action package containin user input and fields
Action Intellisense::displayOperation(vector<string>& tokens)
{
    currentCommand = DISPLAY;
    Action task;
    task.setCommand(getCommand(tokens,DISPLAYCOMMAND));
    task.setStartDate(getDate(tokens));
    setAllStatusFlag(task);
    checkDspReq();

    return task;
}
//@author: A0083711L
//Performs operation "mark" command
//returns an Action package containin user input and fields
Action Intellisense::markOperation(vector<string>& tokens)
{
    currentCommand = MARK;
    Action task;
    task.setCommand(getCommand(tokens,MARKCOMMAND));
    task.setEventName(getEventName(tokens));
    setAllStatusFlag(task);
    checkMarkReq();

    return task;
}

//@author: A0083711L
//Performs quickadd operation
//returns an Action package containin user input and fields
Action Intellisense::quickAddOperation(vector<string>& tokens)
{
    currentCommand = ADD;
    Action task;
    task.setCommand(ADDCOMMAND);// we assume add if no command word is found
    task.determineDate(getDate(tokens),getDate(tokens));
    task.setCategory(getCategory(tokens));
    task.setPriority(getPriority(tokens));
    task.setDateType(getDateType(tokens));
    task.setEventName(getEventName(tokens));
    setAllStatusFlag(task);
    checkAddReq();
    smartAutoFill(task,tokens);//auto fill some of the fields that are unentered

    return task;
}

//@author: A0083711L
//Performs operation "undo" command
//returns an Action package containin user input and fields
Action Intellisense::undoOperation(vector<string>& tokens)
{
    currentCommand = UNDO;
    Action task;
    task.setCommand(getCommand(tokens,UNDOCOMMAND));
    setAllStatusFlag(task);
    return task;
}

//@author: U094659H
//returns int representative of the month entered
int Intellisense::checkDateString(string token)
{

    for(int i=0;i<=23;++i)
    {
        if(checkString(token,months[i]))
        {
            return i+1;
        }
    }

    return -1;
}

//@author: U094659H
//Performs operation "today" command
//returns an Action package containin user input and fields
Action Intellisense::todayOperation(vector<string>& tokens)
{
    currentCommand = TODAY;
    Action task;
    task.setCommand(TODAYCOMMAND);
    setAllStatusFlag(task);
    return task;
}

//@author: U094659H
//Performs operation "todo" command
//returns an Action package containin user input and fields
Action Intellisense::todoOperation(vector<string>& tokens)
{
    currentCommand = TODO;
    Action task;
    task.setCommand(TODOCOMMAND);
    task.setDateType(4);
    setAllStatusFlag(task);
    return task;
}

//@author: U094659H
//Performs operation "redo" command
//returns an Action package containin user input and fields
Action Intellisense::redoOperation(vector<string>& tokens)
{
    currentCommand = REDO;
    Action task;
    task.setCommand(getCommand(tokens,REDOCOMMAND));
    setAllStatusFlag(task);
    return task;
}

//@author: A0083711L
//Performs operation "sort" command
//returns an Action package containin user input and fields
Action Intellisense::sortOperation(vector<string>& tokens)
{
    currentCommand = SORT;
    Action task;
    task.setCommand(getCommand(tokens,SORTCOMMAND));
    setAllStatusFlag(task);
    return task;
}

//@author: A0083711L
//Performs operation "find" command
//returns an Action package containin user input and fields
Action Intellisense::findOperation(vector<string>& tokens)
{
    currentCommand = FIND;
    Action task;
    task.setCommand(getCommand(tokens,FINDCOMMAND));
    task.setPriority(getPriority(tokens));
    task.setCategory(getCategory(tokens));
    task.setStartDate(getDate(tokens));
    task.setEventName(getEventName(tokens));
    setAllStatusFlag(task);
    checkFindReq();

    return task;
}

//@author: U094659H
//Performs operation "displayarchive" command
//returns an Action package containin user input and fields
Action Intellisense::displayarchiveOperation(vector<string>& tokens)
{
    currentCommand = DISPLAYARCHIVE;
    Action task;
    task.setCommand(getCommand(tokens,DISPLAYARCHIVECOMMAND));
    setAllStatusFlag(task);
    smartAutoFill(task,tokens);//auto fill some of the fields that are unentered

    return task;
}

//@author: U094659H
//returns the maximum number of days in that month
int Intellisense::daysMonth(int year, int month)
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
//@author: U094659H
//returns true if date is valid, eg. number of days does not exist 32, there is no month with 32 days
bool Intellisense::isDateValid(Action task)
{
    int day=task.getStartDate().tm_mday;
    int month = task.getStartDate().tm_mon;
    int numberOfDaysInMonth = daysMonth(task.getStartDate().tm_year,month);
    int hour = task.getStartDate().tm_hour;
    int min = task.getStartDate().tm_min;


    if(day<=0 || day>numberOfDaysInMonth)
    {
        return false;
    }

    if(month<=0 || month >12)
    {return false;}

    if(hour<0 || hour>=24)
    {return false;}

    if(min<0 || min >=60)
    {return false;}


    return true;

}

//@author: U094659H
//returns true if date has pass, checks if startDate with today's date
bool Intellisense::isDateOver(Action _task)
{

    time_t t = time(0);
    struct tm * now = localtime( & t );
    now->tm_year += 1900;
    now->tm_mon +=1;
    tm toCompare = _task.getStartDate();

    if(now->tm_year>toCompare.tm_year )
    {return true;}

    if(now->tm_year == toCompare.tm_year && now->tm_mon > toCompare.tm_mon)
    {return true;}



    if(now->tm_year == toCompare.tm_year && now->tm_mon == toCompare.tm_mon && now->tm_mday > toCompare.tm_mday)
    {return true;}


    return false;
}



//@author: U094659H
//updates category field in task to be invalid if an invalid date is detected
void Intellisense::handleInvalidDate(Action &task)
{
    if(!isDateValid(task) && task.getCategory()== "#" && task.getDateType()!=4 && isTimeEmpty(task.getStartDate()))
    {
        task.setCategory("1NVAL1D");
    }
}

//@author: U094659H
//function marks the task as floating task if no date is entered
void Intellisense::handleNoDateEntered(Action &task)
{  tm emptyDate ={0,0,0,0,0,0,0,0,0};
    if (isDateNotentered(task) )
    {//we identify this task as a floating task since no date is stated

        task.setDateType(4);
        task.setStartDate(emptyDate);
        task.setEndDate(emptyDate);

    }
}
//@author: U094659H
//function marks the task as floating task if date has passed
void Intellisense::handleDateOver(Action &task)
{  tm emptyDate ={0,0,0,0,0,0,0,0,0};
    if (isDateOver(task) && isTimeEmpty(task.getStartDate()))
    {//we identify this task as a floating task since no date is stated

        task.setDateType(4);
        task.setStartDate(emptyDate);
        task.setEndDate(emptyDate);

    }
}

//@author: U094659H
//function sets the EndDate to expire at 23:59 if not enddate is specified
void Intellisense::handleNoEndDate(Action &task)
{
    if(task.getDateType()!=4)
    {
        task.setEndDate(getEndOfDay(task));
    }
}

//@author: A0083711L
//function ensures that date has got Enddate and classifies events into floating task
void Intellisense::smartAutoFill(Action &task,vector<string>& tokens)
{
    ASSERT(&task!=NULL,"ACTION OBJECT CANNOT BE reference to null");

    task.setStartDate( isTimeValid(task.getStartDate(),tokens ));

    handleNoDateEntered(task);
    handleInvalidDate(task);
    handleDateOver(task);
    handleNoEndDate(task);


}
//@author: U094659H
//returns true if startDate time is empty
bool Intellisense::isTimeEmpty(tm date)
{
    if(date.tm_hour == 0 && date.tm_min == 0)
    { return true;}

    return false;
}
//@author: U094659H
//returns tm struct autofill date input, time is left untouched
tm Intellisense::isTimeValid(tm date,vector<string>& tokens )
{
    tm now ={0,0,0,0,0,0,0,0,0};
    if(!isTimeEmpty(date) && date.tm_year == 0)
    {
        time_t t = time(0);   // get time now
        now = *localtime( & t );
        now.tm_year +=1900;
        now.tm_mon +=1;
        now.tm_hour = date.tm_hour;
        now.tm_min  = date.tm_min;
        return now;
    }
    else
    {return date;}


}

//@author: U094659H
//returns tm struct autofill EndDate to be same as startDate, time is 23:59
tm Intellisense::getEndOfDay(Action &task)
{
    tm  timeinfo;
    tm  endDate = task.getEndDate();
    if(endDate.tm_year == 0
            && endDate.tm_mon == 0
            && endDate.tm_mday == 0
            && endDate.tm_hour == 0
            && endDate.tm_min ==0 )
    {
        tm startDate = task.getStartDate();
        timeinfo.tm_year = startDate.tm_year;
        timeinfo.tm_mday = startDate.tm_mday;
        timeinfo.tm_mon= startDate.tm_mon;
        timeinfo.tm_hour=23;
        timeinfo.tm_min=59;
        timeinfo.tm_sec=0;
        return timeinfo;
    }else
    {return endDate;}

}


//@author: A0083711L
//Performs operation "edit" command
//returns an Action package containin user input and fields
Action Intellisense::editOperation(vector<string>& tokens)
{
    currentCommand = EDIT;
    Action task;
    task.setCommand(getCommand(tokens,"EDIT"));
    task.determineDate(getDate(tokens),getDate(tokens));
    task.setCategory(getCategory(tokens));
    task.setPriority(getPriority(tokens));
    task.setDateType(getDateType(tokens));
    task.setEventName(getEventName(tokens));
    setAllStatusFlag(task);
    checkEditReq();

    return task;
}

//@author: A0083711L
void Intellisense::setNameFlag(Action task)
{
    if(task.getEventName() == EMPTYEVENT )
        setStatusFlagAt(INAME,false);
    else
        setStatusFlagAt(INAME,true);
}
//@author: A0083711L
void Intellisense::setStartDateFlag(Action task)
{
    bool isDateNotSet;
    isDateNotSet = (task.getStartDate().tm_year == 0	&&
                    task.getStartDate().tm_mon	== 0   &&
                    task.getStartDate().tm_mday == 0);
    if(isDateNotSet)
        setStatusFlagAt(IDATE,false);
    else
        setStatusFlagAt(IDATE,true);
}

//@author: A0083711L
void Intellisense::setEndDateFlag(Action task)
{
    bool isDateEndNotSet = (task.getEndDate().tm_year == 0	&&
                            task.getEndDate().tm_mon	== 0   &&
                            task.getEndDate().tm_mday == 0);
    if(isDateEndNotSet)
        setStatusFlagAt(IDATEEND,false);
    else
        setStatusFlagAt(IDATEEND,true);

}
//@author: A0083711L
void Intellisense::setPriorityFlag(Action task)
{
    if(task.getPriority() == EMPTYPRIORITY )
        setStatusFlagAt(IPRIORITY,false);
    else
        setStatusFlagAt(IPRIORITY,true);
}
//@author: A0083711L
void Intellisense::setCategoryFlag(Action task)
{
    if(task.getCategory() == EMPTYCATEGORY)
        setStatusFlagAt(ICATEGORY,false);
    else
        setStatusFlagAt(ICATEGORY,true);
}
//@author: A0083711L
void Intellisense::setIDFlag(Action task)
{
    if(task.getID() == EMPTYID)
        setStatusFlagAt(IID,false);
    else
        setStatusFlagAt(IID,true);
}

//@author: A0083711L
void Intellisense::setAllStatusFlag(Action task)
{
    setNameFlag(task);
    setStartDateFlag(task);
    setEndDateFlag(task);
    setPriorityFlag(task);
    setCategoryFlag(task);
    setIDFlag(task);
}

//@author: A0083711L
void  Intellisense::getAllStatusFlag(bool *flags)
{
    ASSERT(flags!=NULL,"flags pointer cannot be NULL");
    for (int i=0;i<MAXNOOFPARAMETERS;i++)
    {
        flags[i] = statusFlags[i];;
    }
}
//@author: A0083711L
bool Intellisense::getStatusFlagAt(int index)
{
    ASSERT(index>=0,"flag index canot be less than 0");
    return statusFlags[index];
}
//@author: A0083711L
void Intellisense::setStatusFlagAt(int index,bool flag)
{
    ASSERT(index>=0,"flag index canot be less than 0");
    statusFlags[index] = flag;
}
//@author: A0083711L
bool Intellisense::getrequirementsMet()
{
    return requirementsMet;
}
//@author: A0083711L
void Intellisense::setRequirementsMet(bool req)
{
    requirementsMet = req;
}
//@author: A0083711L
void Intellisense::checkAddReq()
{
    bool addReqMet = false;
    if (statusFlags[INAME])
    {
        addReqMet = true;
    }
    requirementsMet = addReqMet;
}
//@author: A0083711L
void Intellisense::checkExitReq()
{
    bool exitReq = true;//no condition to quit
    requirementsMet = exitReq;
}
//@author: A0083711L
void Intellisense::checkDelReq()
{// need at least an ID to delete
    bool checkReqMet = false;
    if (statusFlags[IID] || statusFlags[INAME])
    {
        checkReqMet = true;
    }
    requirementsMet = checkReqMet;
}
//@author: A0083711L
void Intellisense::checkDspReq()
{
    bool dspReqMet = true;//removed the requirements for display command without any parameters
    requirementsMet = dspReqMet;

}
//@author: A0083711L
void Intellisense::checkMarkReq()
{
    bool markReqMet = false;
    if (statusFlags[INAME] || statusFlags[IDATE])
    {
        markReqMet = true;
    }
    requirementsMet = markReqMet;
}
//@author: A0083711L
void Intellisense::checkFindReq()
{
    bool findReqMet = false;
    if (statusFlags[IDATE] || statusFlags[ICATEGORY]  || statusFlags[INAME])
    {
        findReqMet = true;
    }
    requirementsMet = findReqMet;

}
//@author: A0083711L
void Intellisense::checkEditReq()
{
    bool editReqMet = false;
    if (statusFlags[INAME])
    {
        editReqMet = true;
    }
    requirementsMet = editReqMet;
}
//@author: A0083711L
string Intellisense::getAddFeedBack()
{
    string feedBack;
    if(getrequirementsMet())
    {
        feedBack = ADDFEEDBACK_1 ;
    }
    else
    {
        feedBack = ADDFEEDBACK_2 ;
    }

    return feedBack;
}
//@author: A0083711L
string Intellisense::getEditFeedBack()
{
    string feedBack;
    if(getrequirementsMet())
    {
        feedBack = EDITFEEDBACK_1 ;
    }
    else
    {
        feedBack = EDITFEEDBACK_2 ;
    }

    return feedBack;
}
//@author: A0083711L
string Intellisense::getDeleteFeedBack()
{
    string feedBack;
    if(getrequirementsMet())
    {
        feedBack = DELFEEDBACK_1 ;
    }
    else
    {
        feedBack = DELFEEDBACK_2;
    }

    return feedBack;
}
//@author: A0083711L
string Intellisense::getExitFeedBack()
{
    return EXITFEEDBACK_1;
}
//@author: A0083711L
string Intellisense::getDisplayFeedBack()
{
    string feedBack;
    if(getrequirementsMet())
    {
        feedBack = DISPLAYFEEDBACK_1;
    }
    else
    {
        feedBack = DISPLAYFEEDBACK_2;
    }

    return feedBack;

}
//@author: A0083711L
string Intellisense::getFindFeedBack()
{
    string feedBack;
    if(getrequirementsMet())
    {
        feedBack = FINDFEEDBACK_1;
    }
    else
    {
        feedBack = FINDFEEDBACK_2;
    }

    return feedBack;
}
//@author: A0083711L
string Intellisense::getSortFeedBack()
{
    string feedBack;
    if(getrequirementsMet())
    {
        feedBack =  SORTFEEDBACK_1;
    }
    else
    {
        feedBack = SORTFEEDBACK_2;
    }

    return feedBack;

}
//@author: A0083711L
string Intellisense::getRedoFeedBack()
{
    return REDOFEEDBACK_1;
}
//@author: A0083711L
string Intellisense::getUndoFeedBack()
{
    return UNDOFEEDBACK_1;
}
//@author: A0083711L
string Intellisense::getMarkFeedBack()
{
    string feedBack;
    if(getrequirementsMet())
    {
        feedBack = MARKFEEDBACK_1 ;
    }
    else
    {
        feedBack = MARKFEEDBACK_2 ;
    }

    return feedBack;
}
//@author: A0083711L
string Intellisense::getFeedback()
{//later refactor this into functions
    switch(currentCommand)
    {
    case ADD:
        _feedback = getAddFeedBack();
        break;
    case EDIT:
        _feedback = getEditFeedBack();
        break;
    case DELETE:
        _feedback = getDeleteFeedBack();
        break;
    case EXIT:
        _feedback = getExitFeedBack();
        break;
    case DISPLAY:
        _feedback = getDisplayFeedBack();
        break;
    case FIND:
        _feedback = getFindFeedBack();
        break;
    case SORT:
        _feedback = getSortFeedBack();
        break;
    case REDO:
        _feedback = getRedoFeedBack();
        break;
    case UNDO:
        _feedback = getUndoFeedBack();
        break;
    case MARK:
        _feedback = getMarkFeedBack();
        break;
    }


    return _feedback;
}
//@author: A0083711L
void Intellisense::setFeedback(string newFeedback)
{
    _feedback=newFeedback;
}
//@author: A0083711L
bool isValidAddPara(int parameter)
{
    bool valid = false;
    if (parameter == INAME || parameter ==  IDATE || parameter == IPRIORITY ||
            parameter == ICATEGORY || parameter == IDATEEND)
    {
        valid = true;
    }

    return valid;

}
//@author: A0083711L
bool isValidDelPara(int parameter)
{
    bool valid = false;
    if (parameter == INAME || parameter == IID)
        valid = true;

    return valid;

}
//@author: A0083711L
bool isValidDisplayPara(int parameter)
{
    bool valid = false;
    return valid;

}
//@author: A0083711L
bool isValidMarkPara(int parameter)
{
    bool valid = false;
    if (parameter == INAME  )
        valid =true;

    return valid;

}
//@author: A0083711L
bool isValidFindPara(int parameter)
{
    bool valid = false;
    if (parameter == INAME ||  parameter == ICATEGORY ||  parameter == IDATE)
        valid =true;

    return valid;

}
//@author: A0083711L
bool isValidEditPara(int parameter)
{
    bool valid = false;
    if (parameter == INAME || parameter ==  IDATE || parameter == IPRIORITY ||
            parameter == ICATEGORY || parameter == IDATEEND ||  parameter == IID)
        valid =true;

    return valid;
}
//@author: A0083711L
bool isValidExitPara(int parameter)
{
    bool valid = false;

    return valid;
}
//@author: A0083711L
bool isValidSortPara(int parameter)
{
    bool valid = false;

    return valid;
}
//@author: A0083711L
bool Intellisense::isValidParaForCmd(int cmd,int parameter)
{//this determines if the parameter is valid to work with the command
    ASSERT(cmd>=0,"COMMAND CODE CANNOT BE LESS THAN ZERO");
    ASSERT(cmd>=0,"PARAMETER CANNOT BE LESS ZERO");
    bool valid = false;

    switch(cmd)
    {
    case ADD:
    {
        valid = isValidAddPara(parameter);
        break;
    }
    case DELETE:
    {
        valid = isValidDelPara(parameter);
        break;
    }
    case DISPLAY:
    {
        valid = isValidDisplayPara(parameter);
        break;
    }
    case MARK:
    {
        valid = isValidMarkPara(parameter);
        break;
    }
    case FIND:
    {
        valid = isValidFindPara(parameter);
        break;
    }
    case EDIT:
    {
        valid = isValidEditPara(parameter);
        break;
    }
    case EXIT:
    {
        valid = isValidExitPara(parameter);
        break;
    }
    case SORT:
    {
        valid = isValidSortPara(parameter);
        break;
    }
    }

    return valid;
}
//@author: A0083711L
void Intellisense::clearPara()
{
    _parameter = "";//erase first
}
//@author: A0083711L
void Intellisense::updateNameInPara()
{
    if(isValidParaForCmd(currentCommand,INAME))
    {
        if(statusFlags[INAME])
        {
            _parameter =_parameter + GREENEVENTTEXT ;
        }
        else
        {
            _parameter =_parameter + REDEVENTTEXT ;
        }
    }
}
//@author: A0083711L
void Intellisense::updateDateInPara()
{
    if(isValidParaForCmd(currentCommand,IDATE))//
    {
        writeDateToPara();
    }
}
//@author: A0083711L
void Intellisense::writeDateToPara()
{
    if(statusFlags[IDATE])
    {
        _parameter =_parameter + GREENSTARTDATETEXT ;
    }
    else
    {
        _parameter =_parameter + REDSTARTDATETEXT ;
    }
}
//@author: A0083711L
void Intellisense::writeEndDateToPara()
{
    if(statusFlags[IDATEEND])
    {
        _parameter =_parameter + GREENENDDATETEXT;
    }
    else
    {
        _parameter =_parameter + REDENDDATETEXT;
    }
}
//@author: A0083711L
void Intellisense::updateEndDateInPara()
{
    if(isValidParaForCmd(currentCommand,IDATEEND))//
    {
        writeEndDateToPara();
    }
}
//@author: A0083711L
void Intellisense::writePriorityToPara()
{
    if(statusFlags[IPRIORITY])
    {
        _parameter =_parameter + GREENPRIORITYTEXT ;
    }
    else
    {
        _parameter =_parameter + REDPRIORITYTEXT ;
    }
}
//@author: A0083711L
void Intellisense::updatePriorityInPara()
{
    if(isValidParaForCmd(currentCommand,IPRIORITY))//
    {
        writePriorityToPara();
    }
}
//@author: A0083711L
void Intellisense::writeCategoryToPara()
{
    if(statusFlags[ICATEGORY])
    {
        _parameter =_parameter + GREENCATEGORYTEXT;
    }
    else
    {
        _parameter =_parameter + REDCATEGORYTEXT ;
    }
}

//@author: A0083711L
void Intellisense::updateCategoryInPara()
{
    if(isValidParaForCmd(currentCommand,ICATEGORY))//
    {
        writeCategoryToPara();
    }
}
//@author: A0083711L
void Intellisense::writeIDToPara()
{
    if(isValidParaForCmd(currentCommand,IID))//
    {
        if(statusFlags[IID])
        {
            _parameter =_parameter + GREENIDTEXT ;
        }
        else
        {
            _parameter =_parameter + REDIDTEXT ;
        }
    }
}

//@author: A0083711L
void Intellisense::updateIDInPara()
{
    writeIDToPara();
}

//@author: A0083711L
// output the string based on the flags set
string Intellisense::getParameter()
{
    clearPara();
    updateNameInPara();
    updateDateInPara();
    updateEndDateInPara();
    updatePriorityInPara();
    updateCategoryInPara();
    updateIDInPara();

    _parameter = _parameter + LINEBREAK + getFeedback();

    return _parameter;
}
//@author: A0083711L
void Intellisense::setParameter(string newParameter)
{
    _parameter = newParameter;
}
//@author: A0083711L
bool Intellisense::isDateNotentered(Action _task)
{
    return (_task.getStartDate().tm_year == 0 && _task.getStartDate().tm_mon == 0
            && _task.getStartDate().tm_mday ==0 && _task.getStartDate().tm_hour == 0
            && _task.getStartDate().tm_min == 0);
}



