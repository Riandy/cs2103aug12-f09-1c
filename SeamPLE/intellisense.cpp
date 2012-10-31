#include "Intellisense.h"





const string Intellisense::months[12] = {"JANURARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};


//important date events
imptDate imptDates[]= {  imptDate("CHRISTMAS","2512"),imptDate("NEWYEAR","0101")};
int imptDatesSize = 2;


//changed to array test
const string Intellisense::addCommandArray[] = { "add", "-a", "create" ,"new","++","-a"};
const string Intellisense::deleteCommandArray[] = { "delete","del","dd","cancel","-d" };
const string Intellisense::markCommandArray[] = { "mark", "done","-m"};
const string Intellisense::displayCommandArray[]= { "display" ,"show","-d","dsp"};
const string Intellisense::exitCommandArray[] = {"exit","quit","-q"};
const string Intellisense::sortCommandArray[] = {"sort","arrange","-s"};
const string Intellisense::findCommandArray[] = {"find","search","-f"};
const string Intellisense::editCommandArray[] = {"edit","change","-e"};
const string Intellisense::undoCommandArray[] = {"undo","revert","-u"};
const string Intellisense::redoCommandArray[] = {"redo","-r"};

const string Intellisense::EMPTYCATEGORY = "#";
const string Intellisense::EMPTYEVENT = "";
const string Intellisense::EMPTYPRIORITY = "LOW";
const int    Intellisense::EMPTYID = -1;
const string Intellisense::HIGHPRIORITY  = "HIGH";
const string Intellisense::HIGHPRIORITY_L = "high";
const string Intellisense::WEEKLY = "weekly";
const string Intellisense::MONTHLY = "monthly";
const string Intellisense::FORTNIGHTLY = "fortnightly";

const string Intellisense::ADDFEEDBACK_1 = "eg. add baby Birthday Preparation 24 Aug #family";
const string Intellisense::ADDFEEDBACK_2 = "eg. Add baby birthday 24 aug";
const string Intellisense::EDITFEEDBACK_1 = "eg. edit homework #HIGH";
const string Intellisense::EDITFEEDBACK_2= "eg. edit homework #HIGH";
const string Intellisense::DELFEEDBACK_1= "eg. del 3";
const string Intellisense::DELFEEDBACK_2= "eg. del 3";
const string Intellisense::EXITFEEDBACK_1= " Are you sure you want to exit?";
const string Intellisense::DISPLAYFEEDBACK_1= "eg. display #category";
const string Intellisense::DISPLAYFEEDBACK_2= "eg. display #category";
const string Intellisense::FINDFEEDBACK_1= "eg. find birthday";
const string Intellisense::FINDFEEDBACK_2="eg. find birthday";
const string Intellisense::SORTFEEDBACK_1="eg. The Events Will be Sorted By Date";
const string Intellisense::SORTFEEDBACK_2="eg. The Events Will be Sorted By Date";
const string Intellisense::REDOFEEDBACK_1="Press enter to redo your last operation";
const string Intellisense::UNDOFEEDBACK_1="Press enter to undo your last operation";
const string Intellisense::MARKFEEDBACK_1="eg. mark today";
const string Intellisense::MARKFEEDBACK_2="eg. mark today";

const  string Intellisense::GREENEVENTTEXT = "<font color=green>[EventNAME] </font>";
const  string Intellisense::REDEVENTTEXT  = "<font color=red>[EventNAME] </font>";

const  string Intellisense::GREENSTARTDATETEXT = "<font color=green>[StartDate] </font>" ;
const  string Intellisense::REDSTARTDATETEXT = "<font color=red>[StartDate] </font>";

const  string Intellisense::GREENENDDATETEXT = "<font color=green>[EndDate] </font>";
const  string Intellisense::REDENDDATETEXT = "<font color=red>[EndDate] </font>";

const  string Intellisense::GREENPRIORITYTEXT = "<font color=green>[PRIORITY] </font>";
const  string Intellisense::REDPRIORITYTEXT = "<font color=red>[PRIORITY] </font>";


const  string Intellisense::GREENCATEGORYTEXT = "<font color=green>[CATEGORY] </font>";
const  string Intellisense::REDCATEGORYTEXT = "<font color=red>[CATEGORY] </font>";

const  string Intellisense::GREENIDTEXT = "<font color=green>[ID] </font>";
const  string Intellisense::REDIDTEXT = "<font color=red>[ID] </font>";

const char Intellisense::CATEGORYRECOGNISER = '#' ;




bool Intellisense::instanceFlag = false;
Intellisense* Intellisense::intellisense = NULL;

//miscellaneous function
char toLower(char in){
    if(in<='Z' && in>='A')
        return in-('Z'-'z');
    return in;
}
//end of miscellaneous


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

Intellisense::Intellisense(void)
{
    initFlags();
}
void Intellisense::initFlags()
{
    for(int i=0; i<MAXNOOFPARAMETERS; i++)
    {
        statusFlags[i] = true;
    }
    requirementsMet = false;
}



Intellisense::~Intellisense(void)
{
    instanceFlag=false;
}

Action Intellisense::check(string query)
{
    Action task;

    trim(query);

    vector<string> buffer = tokenize(query);

    switch(determinOperation(buffer))
    {
    case ADD:
        task=addOperation(buffer);
        break;
    case DELETE:
        task=deleteOperation(buffer);
        break;
    case DISPLAY:
        task=displayOperation(buffer);
        break;
    case MARK:
        task=markOperation(buffer);
        break;
    case SORT:
        task=sortOperation(buffer);
        break;
    case FIND:
        task=findOperation(buffer);
        break;
    case EDIT:
        task=editOperation(buffer);
        break;
    case EXIT:
        task=exitOperation(buffer);
        break;
    case INVALID:
        task=quickAddOperation(buffer);
        break;
    case UNDO:
        task=undoOperation(buffer);
        break;
    case REDO:
        task=redoOperation(buffer);
        break;
    default:
        break;
    }


    return task;
}




operation Intellisense::determinOperation(vector<string>& tokens)
{
    if(tokens.size()==0)
    {
        return INVALID;
    }

    string commandword=tokens[0];
    if(checkCommandArray(commandword,addCommandArray, sizeof(addCommandArray)/sizeof(string) ))//the sizeof operator  have to work at this level of abstraction due to auto convertion of array to pointer and arraysize information loss
    {
        return ADD;
    }else if(checkCommandArray(commandword,deleteCommandArray,sizeof(deleteCommandArray)/sizeof(string)))
    {
        return DELETE;
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
    }
    else
    {
        return INVALID;
    }
}


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
string Intellisense::toLowerString(string input)
{
     transform(input.begin(), input.end(), input.begin(),toLower);
     return input;
}
bool Intellisense::checkCommandArray(const string& input, const string command[],int arraySize)
{
    bool isCommandFound = false;
    string inputBuffer;
    string commandBuffer;
    inputBuffer = toLowerString(input);
    for (int i = 0 ; i < arraySize; i++)
    {
        commandBuffer = toLowerString(command[i]);
        if(inputBuffer == commandBuffer)
            isCommandFound = true;
    }
    return isCommandFound;
}
string Intellisense::getfirst_Word(string command)
{
    return tokenize(command)[0];
}

string Intellisense::getCommand(vector<string>& tokens,string _command)
{
    vector<string>::iterator it=tokens.begin();
    string command = _command;
    it=tokens.erase(it);

    return command;
}

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


string Intellisense::getPriority(vector<string>& tokens)
{
    if(tokens.size()>0)
    {
        string checkHeadString =  tokens.front();
        string checkTailString =  tokens.back();



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
    }
    return string("LOW");
}

tm Intellisense::getTime(vector<string>& tokens,tm date)
{
    string time;
    date.tm_hour=0;
    date.tm_min=0;

    vector<string>::iterator it=tokens.begin();
    while (it!=tokens.end())
    {
        time=it->c_str();
        if(time.size()>=5)
        {if(time.at(2) == ':' )
            {
                if(time.size()==5)
                {
                    time=removeChar(time,":");
                    if(isAllInt(time))
                    {
                        it=tokens.erase(it);
                        date.tm_hour=atoi(time.substr(0,2).c_str());
                        date.tm_min=atoi(time.substr(2,2).c_str());
                        return date;
                    }

                }
            }
        }else if(time.size()==4)
        {
            if(checkString("PM",time.substr(2,2))|| checkString("AM",time.substr(2,2)))
            {
                if(isAllInt(time.substr(0,2)))
                {
                    it=tokens.erase(it);
                    if(checkString("PM",time.substr(2,2)))
                    {
                        date.tm_hour=atoi(time.substr(0,2).c_str())+12;
                        date.tm_min=atoi(time.substr(2,2).c_str());
                        return date;
                    }
                    else
                    {
                        date.tm_hour=atoi(time.substr(0,2).c_str());
                        date.tm_min=atoi(time.substr(2,2).c_str());
                        return date;
                    }

                }
            }
        }else if(time.size()==3)
        {
            if(checkString("PM",time.substr(1,2))|| checkString("AM",time.substr(1,2)))
            {
                if(isAllInt(string(1,time.at(0))))
                {
                    it=tokens.erase(it);
                    if(checkString("PM",time.substr(1,2)))
                    {
                        date.tm_hour=atoi(time.substr(0,2).c_str())+12;
                        date.tm_min=atoi(time.substr(2,2).c_str());
                        return date;
                    }
                    else
                    {
                        date.tm_hour=atoi(time.substr(0,2).c_str());
                        date.tm_min=atoi(time.substr(2,2).c_str());
                        return date;
                    }

                }
            }
        }




        if (it!=tokens.end())
            ++it;//only increment if it is not the last position
    }
    return date;
}


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
            return category;
        }

        if(it != tokens.end())
            it++;//only increment if it is not the last position
    }
    return category;


}

string Intellisense::removeChar(string s,char chars[])
{
    for (unsigned int i = 0; i < sizeof(chars); ++i)
    {
        s.erase (std::remove(s.begin(), s.end(), chars[i]), s.end());
    }
    return s;
}

string& Intellisense::trim_left_inplace( string& s,  const string& delimiters)
{
    return s.erase(  0, s.find_first_not_of( delimiters ) );
}

//removes blank spaces from back of string
string& Intellisense::trim_right_inplace( string& s, const string& delimiters)
{
    return s.erase( s.find_last_not_of( delimiters ) + 1 );
}

//removes blank spaces from front and back of string
string& Intellisense::trim(string& s ,const string& delimiters )
{
    return trim_left_inplace( trim_right_inplace( s, delimiters ), delimiters );
}


tm Intellisense::getImptDate(string _date)
{
    tm date;
    date.tm_hour=NULL;
    date.tm_min=NULL;
    date.tm_sec=NULL;
    date.tm_mday=NULL;
    date.tm_mon=NULL;
    date.tm_year=NULL;

    time_t timeNow;
    struct tm * timeinfo;
    time (&timeNow);
    timeinfo = localtime ( &timeNow );

    date.tm_mday=atoi(_date.substr(0,2).c_str());
    date.tm_mon=atoi(_date.substr(2,2).c_str());
    date.tm_year=timeinfo->tm_year+1900;


return date;
}


tm Intellisense::getDate(vector<string>& tokens)
{
    string checkString;
    tm date;
    date.tm_hour=NULL;
    date.tm_min=NULL;
    date.tm_sec=NULL;
    date.tm_mday=NULL;
    date.tm_mon=NULL;
    date.tm_year=NULL;

    vector<string>::iterator it1=tokens.begin();
    while (it1!=tokens.end())
    {
       checkString = it1->c_str();
       for(int i =0; i<=imptDatesSize;i++)
       {
           if(checkString.compare(imptDates[i].name)==0)
           {

               return getImptDate(imptDates[i].date);
           }
       }



        if (it1!=tokens.end())
            ++it1;//only increment if it is not the last position

    }

    vector<string>::iterator it=tokens.begin();
    while (it!=tokens.end())
    {
        checkString = it->c_str();
        if(checkString.size()==8)
        {
            if(isAllInt(checkString))
            {
                it=tokens.erase(it);
                date.tm_mday=atoi(checkString.substr(0,2).c_str());
                date.tm_mon=atoi(checkString.substr(2,2).c_str());
                date.tm_year=atoi(checkString.substr(4,4).c_str());
                return date=getTime(tokens,date);
            }
        }
        if(checkString.size()==10)
        {
            if(checkString.at(2) == '\\' && checkString.at(5)=='\\'  || checkString.at(2) == '/' && checkString.at(5)=='/'  )
            {
                checkString=removeChar(checkString,"/\\");
                if(isAllInt(checkString))
                {
                    it=tokens.erase(it);
                    date.tm_mday=atoi(checkString.substr(0,2).c_str());
                    date.tm_mon=atoi(checkString.substr(2,2).c_str());
                    date.tm_year=atoi(checkString.substr(4,4).c_str());
                    return date=getTime(tokens,date);
                }
            }
        }

        if(checkString.size()==8)
        {
            if(checkString.at(1) == '\\' && checkString.at(3)=='\\'  || checkString.at(1) == '/' && checkString.at(3)=='/'  )
            {
                checkString=removeChar(checkString,"/\\");
                if(isAllInt(checkString))
                {
                    it=tokens.erase(it);
                    date.tm_mday=atoi(checkString.substr(0,1).c_str());
                    date.tm_mon=atoi(checkString.substr(1,1).c_str());
                    date.tm_year=atoi(checkString.substr(2,4).c_str());
                    return date=getTime(tokens,date);
                }
            }
        }


        if(tokens.size()>=3)
        {
            int check=checkDateString(checkString);

            if(check !=-1)
            {
                it--;
                vector<string>::iterator it_day = it++;

                if(++it == tokens.end())
                {                // wenbin's own note, iterator unexplained
                    return date=getTime(tokens,date);
                }
                --it;
                vector<string>::iterator it_year = ++it;

                string day =it_day->c_str();
                if(day.size()>2 || day.size()<=0 || !isAllInt(day))
                {
                    return date=getTime(tokens,date);
                }
                string year = it_year->c_str();
                if(year.size()!=4 || !isAllInt(year))
                {
                    return date=getTime(tokens,date);
                }
                if(atoi(day.c_str())<=0 || atoi(year.c_str())<=0)
                {

                    return date=getTime(tokens,date);
                }
                int month = check;


                it_day=tokens.erase(it_day);
                it_day=tokens.erase(it_day);
                it_day=tokens.erase(it_day);

                it=it_day;

                date.tm_mday=atoi(day.c_str());
                date.tm_mon=month;
                date.tm_year=atoi(year.c_str());
                return date=getTime(tokens,date);


            }
        }



        if (it!=tokens.end())
            ++it;//only increment if it is not the last position
    }
    return date=getTime(tokens,date);

}



int Intellisense::checkDateString(string token)
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


string Intellisense::getEventName(vector<string>& tokens)
{
    stringstream ss;
    for(vector<string>::iterator it=tokens.begin();it!=tokens.end();++it)
    {
        ss<<it->c_str()<<string(" ");
    }

    return ss.str();
}
int Intellisense::getDateType(vector<string>& tokens)
{
    int dType = task::DATENORMAL;//default normal if cant find other date types
    vector<string>::iterator it=tokens.begin();
    while(it!=tokens.end())
    {
        string lowerString = toLowerString(*it);
        if( lowerString == WEEKLY )
        {//may have to add more checks if weekly is used in event name
            dType = task::DATEWEEKLY;
            it = tokens.erase(it);
        }
        else if(lowerString == FORTNIGHTLY)
        {
            dType = task::DATEFORTNIGHTLY;
            it = tokens.erase(it);
        }
        else if( lowerString == MONTHLY)
        {
            dType = task::DATEMONTHLY;
            it = tokens.erase(it);
        }

        if(it!= tokens.end())
            it++;//increment if it is not the last iterator

    }
    return dType;

}
void Intellisense::itTest(vector<string> tokens)
{


    for(vector<string>::iterator it=tokens.begin();it!=tokens.end();++it)
    {
        cout<<it->c_str();


    }


    cout<<endl;
}

bool Intellisense::isAllInt(const string& s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(! (s[i] >= '0' && s[i] <= '9' || s[i] == ' ') ) return false;
    }
    return true;
}

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

Action Intellisense::addOperation(vector<string>& tokens)
{
    currentCommand = ADD;
    Action task;
    task.setCommand(getCommand(tokens,"ADD"));
    task.determineDate(getDate(tokens),getDate(tokens));
    task.setCategory(getCategory(tokens));
    task.setPriority(getPriority(tokens));
    task.setEventName(getEventName(tokens));
    setAllStatusFlag(task);
    checkAddReq();
    smartAutoFill(task);//auto fill some of the fields that are unentered
    return task;
}
Action Intellisense::deleteOperation(vector<string>& tokens)
{
    currentCommand = DELETE;
    Action task;
    task.setCommand(getCommand(tokens,"DELETE"));
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
Action Intellisense::exitOperation(vector<string>& tokens)
{
    currentCommand = EXIT;
    Action task;
    task.setCommand(getCommand(tokens,"EXIT"));
    setAllStatusFlag(task);
    checkExitReq();
    return task;

}
Action Intellisense::displayOperation(vector<string>& tokens)
{
    currentCommand = DISPLAY;
    Action task;
    task.setCommand(getCommand(tokens,"DISPLAY"));
    task.setStartDate(getDate(tokens));
    setAllStatusFlag(task);
    checkDspReq();

    return task;
}
Action Intellisense::markOperation(vector<string>& tokens)
{
    currentCommand = MARK;
    Action task;
    task.setCommand(getCommand(tokens,"MARK"));
    task.setStartDate(getDate(tokens));
    task.setEventName(getEventName(tokens));
    setAllStatusFlag(task);
    checkMarkReq();

    return task;
}
Action Intellisense::quickAddOperation(vector<string>& tokens)
{
    currentCommand = ADD;
    Action task;
    task.setCommand("ADD");// we assume add if no command word is found
    task.determineDate(getDate(tokens),getDate(tokens));
    task.setCategory(getCategory(tokens));
    task.setPriority(getPriority(tokens));
    task.setDateType(getDateType(tokens));
    task.setEventName(getEventName(tokens));
    setAllStatusFlag(task);
    checkAddReq();
    smartAutoFill(task);//auto fill some of the fields that are unentered
    return task;
}
Action Intellisense::undoOperation(vector<string>& tokens)
{
    currentCommand = UNDO;
    Action task;
    task.setCommand(getCommand(tokens,"UNDO"));
    setAllStatusFlag(task);
    return task;
}
Action Intellisense::redoOperation(vector<string>& tokens)
{
    currentCommand = REDO;
    Action task;
    task.setCommand(getCommand(tokens,"REDO"));
    setAllStatusFlag(task);
    return task;
}

Action Intellisense::sortOperation(vector<string>& tokens)
{
    currentCommand = SORT;
    Action task;
    task.setCommand(getCommand(tokens,"SORT"));
    setAllStatusFlag(task);
    return task;
}
Action Intellisense::findOperation(vector<string>& tokens)
{
    currentCommand = FIND;
    Action task;
    task.setCommand(getCommand(tokens,"FIND"));
    task.setPriority(getPriority(tokens));
    task.setCategory(getCategory(tokens));
    task.setStartDate(getDate(tokens));
    task.setEventName(getEventName(tokens));
    setAllStatusFlag(task);
    checkFindReq();

    return task;
}

Action Intellisense::editOperation(vector<string>& tokens)
{
    currentCommand = EDIT;
    Action task;
    task.setCommand(getCommand(tokens,"EDIT"));
    task.setPriority(getPriority(tokens));
    task.setCategory(getCategory(tokens));
    task.setStartDate(getDate(tokens));
    task.setDateType(getDateType(tokens));
    task.setEventName(getEventName(tokens));
    setAllStatusFlag(task);
    checkEditReq();

    return task;
}



void Intellisense::setAllStatusFlag(Action task)
{

    if(task.getEventName() == EMPTYEVENT )
        setStatusFlagAt(INAME,false);
    else
        setStatusFlagAt(INAME,true);

    bool isDateNotSet;
    isDateNotSet = (task.getStartDate().tm_year == 0	&&
                    task.getStartDate().tm_mon	== 0   &&
                    task.getStartDate().tm_mday == 0);
    if(isDateNotSet)
        setStatusFlagAt(IDATE,false);
    else
        setStatusFlagAt(IDATE,true);

    bool isDateEndNotSet;
    isDateEndNotSet = (task.getEndDate().tm_year == 0	&&
                       task.getEndDate().tm_mon	== 0   &&
                       task.getEndDate().tm_mday == 0);
    if(isDateEndNotSet)
        setStatusFlagAt(IDATEEND,false);
    else
        setStatusFlagAt(IDATEEND,true);

    if(task.getPriority() == EMPTYPRIORITY )
        setStatusFlagAt(IPRIORITY,false);
    else
        setStatusFlagAt(IPRIORITY,true);


    if(task.getCategory() == EMPTYCATEGORY)
        setStatusFlagAt(ICATEGORY,false);
    else
        setStatusFlagAt(ICATEGORY,true);

    if(task.getID() == EMPTYID)
        setStatusFlagAt(IID,false);
    else
        setStatusFlagAt(IID,true);
}
void  Intellisense::getAllStatusFlag(bool *flags)
{
    for (int i=0;i<MAXNOOFPARAMETERS;i++)
    {
        flags[i] = statusFlags[i];;
    }
}

bool Intellisense::getStatusFlagAt(int index)
{
    return statusFlags[index];
}
void Intellisense::setStatusFlagAt(int index,bool flag)
{
    statusFlags[index] = flag;
}
bool Intellisense::getrequirementsMet()
{
    return requirementsMet;
}
void Intellisense::setRequirementsMet(bool req)
{
    requirementsMet = req;
}

void Intellisense::checkAddReq()
{
    bool addReqMet = false;
    if (statusFlags[INAME])
    {
        addReqMet = true;
    }
    requirementsMet = addReqMet;
}
void Intellisense::checkExitReq()
{
    bool exitReq = true;//no condition to quit
    requirementsMet = exitReq;
}
void Intellisense::checkDelReq()
{// need at least an ID to delete
    bool checkReqMet = false;
    if (statusFlags[IID])
    {
        checkReqMet = true;
    }
    if (statusFlags[INAME])
    {
        checkReqMet = true;
    }
    requirementsMet = checkReqMet;
}
void Intellisense::checkDspReq()
{
    bool dspReqMet = false;

    /*if (statusFlags[ICATEGORY] )
    {
        dspReqMet = true;
    }
    if (statusFlags[IDATE] )
    {
        dspReqMet = true;
    }
    */
    dspReqMet = true;//removed the requirements for display command without any parameters
    requirementsMet = dspReqMet;

}
void Intellisense::checkMarkReq()
{
    bool markReqMet = false;
    if (statusFlags[INAME])
    {
        markReqMet = true;
    }
    if (statusFlags[IDATE] )
    {
        markReqMet = true;
    }
    requirementsMet = markReqMet;
}
void Intellisense::checkFindReq()
{
    bool findReqMet = false;
    if (statusFlags[IDATE] )
    {
        findReqMet = true;
    }
    if (statusFlags[ICATEGORY] )
    {
        findReqMet = true;
    }
    if (statusFlags[INAME])
    {
        findReqMet = true;
    }
    requirementsMet = findReqMet;

}
void Intellisense::checkEditReq()
{
    bool editReqMet = false;
    if (statusFlags[INAME])
    {
        editReqMet = true;
    }
    requirementsMet = editReqMet;
}
string Intellisense::getAddFeedBack()
{
    string feedback;
    if(getrequirementsMet())
    {
            feedback = ADDFEEDBACK_1 ;
    }
    else
    {
            feedback = ADDFEEDBACK_2 ;
    }
    return feedback;
}
string Intellisense::getEditFeedBack()
{
    string feedback;
    if(getrequirementsMet())
    {
            feedback = EDITFEEDBACK_1 ;
    }
    else
    {
            feedback = EDITFEEDBACK_2 ;
    }
    return feedback;
}
string Intellisense::getDeleteFeedBack()
{
    string feedback;
    if(getrequirementsMet())
    {
            feedback = DELFEEDBACK_1 ;
    }
    else
    {
            feedback = DELFEEDBACK_2;
    }
    return feedback;
}
string Intellisense::getExitFeedBack()
{
    string feedback;
    feedback = EXITFEEDBACK_1;
    return feedback;
}
string Intellisense::getDisplayFeedBack()
{
    string feedback;
    if(getrequirementsMet())
    {
        feedback = DISPLAYFEEDBACK_1;
    }
    else
    {
        feedback = DISPLAYFEEDBACK_2;
    }
    return feedback;
}

string Intellisense::getFindFeedBack()
{
    string feedback;
    if(getrequirementsMet())
    {
        feedback = FINDFEEDBACK_1;
    }
    else
    {
        feedback = FINDFEEDBACK_2;
    }
    return feedback;
}
string Intellisense::getSortFeedBack()
{
    string feedback;
    if(getrequirementsMet())
    {
        feedback = SORTFEEDBACK_1;
    }
    else
    {
        feedback = SORTFEEDBACK_2;
    }
    return feedback;
}
string Intellisense::getRedoFeedBack()
{
    string feedback;
    feedback = REDOFEEDBACK_1 ;
    return feedback;
}
string Intellisense::getUndoFeedBack()
{
    string feedback;
    feedback = UNDOFEEDBACK_1 ;
    return feedback;
}
string Intellisense::getMarkFeedBack()
{
    string feedback;
    if(getrequirementsMet())
    {
            feedback = MARKFEEDBACK_1 ;
    }
    else
    {
            feedback =MARKFEEDBACK_2 ;
    }
    return feedback;
}
string Intellisense::getFeedback()
{//later refactor this into functions
    if(currentCommand == ADD)
    {
        _feedback = getAddFeedBack();
    }
    else if(currentCommand == EDIT)
    {
        _feedback = getEditFeedBack();
    }
    else if(currentCommand == DELETE )
    {
        _feedback = getDeleteFeedBack();
    }
    else if(currentCommand == EXIT )
    {
        _feedback = getExitFeedBack();
    }
    else if(currentCommand == DISPLAY )
    {
        _feedback = getDisplayFeedBack();
    }
    else if(currentCommand == FIND )
    {
        _feedback = getFindFeedBack();
    }
    else if(currentCommand == SORT )
    {
        _feedback = getSortFeedBack();
    }
    else if(currentCommand == REDO )
    {
        _feedback = getRedoFeedBack();
    }

    else if(currentCommand == UNDO )
    {
        _feedback = getUndoFeedBack();
    }

    else if(currentCommand == MARK )
    {
        _feedback = getMarkFeedBack();
    }

    return _feedback;
}
void Intellisense::setFeedback(string newFeedback)
{
    _feedback=newFeedback;
}
bool Intellisense::isValidParaForCmd(int cmd,int parameter)
{//this determines if the parameter is valid to work with the command
    bool valid=false;
    if (cmd == ADD)
    {
        if (parameter == INAME || parameter ==  IDATE || parameter == IPRIORITY ||
            parameter == ICATEGORY || parameter == IDATEEND)
            valid =true;
    }
    if (cmd == DELETE)
    {//delete command only valid with 2 parameter
        if (parameter == INAME || parameter == IID)
            valid =true;
    }
    if (cmd == DISPLAY)
    {
        if (parameter == INAME ||  parameter == ICATEGORY )
            valid =true;
    }
    if (cmd == MARK)
    {
        if (parameter == INAME  )
            valid =true;
    }
    if (cmd == FIND)
    {
        if (parameter == INAME ||  parameter == ICATEGORY )
            valid =true;
    }
    if (cmd == EDIT)
    {
        if (parameter == INAME || parameter ==  IDATE || parameter == IPRIORITY ||
            parameter == ICATEGORY || parameter == IDATEEND ||  parameter == IID)
            valid =true;
    }
    if (cmd == EXIT)
    {
            valid =false;
    }
    if (cmd == SORT)
    {
            valid =false;
    }
    return valid;
}
string Intellisense::getParameter()
{// output the string based on the flags set
    //refactor into many small functions
    _parameter ="";//erase first
    if(isValidParaForCmd(currentCommand,INAME))//
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
    if(isValidParaForCmd(currentCommand,IDATE))//
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

    if(isValidParaForCmd(currentCommand,IDATEEND))//
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

    if(isValidParaForCmd(currentCommand,IPRIORITY))//
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

    if(isValidParaForCmd(currentCommand,ICATEGORY))//
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
    //this is for the example feedback string
    _parameter = _parameter + "<br>" + getFeedback();
    return _parameter;
}
void Intellisense::setParameter(string newParameter)
{
    _parameter = newParameter;
}

void Intellisense::smartAutoFill(Action &task)
{
    bool isDateNotentered = (task.getStartDate().tm_year == 0 && task.getStartDate().tm_mon == 0
                             && task.getStartDate().tm_mday ==0);
    if (isDateNotentered)
    {//we auto fill in todays day if date is unentered
        //
        time_t timeNow;
        struct tm * timeinfo;
        time (&timeNow);
        timeinfo = localtime ( &timeNow );
        timeinfo->tm_year+=1900;//add 1900 years to fit our format
        timeinfo->tm_mon+=1; //to fit our format
        if(task.getStartDate().tm_hour==0 && task.getStartDate().tm_min==00)
        {
            task.setStartDate(*timeinfo);
        }
        else
        {
            task.setStartDateWithoutTime(*timeinfo);
        }

    }
}

