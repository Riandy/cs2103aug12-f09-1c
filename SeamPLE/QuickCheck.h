#ifndef QUICKCHECK_H
#define QUICKCHECK_H

#include <string>

using namespace std;

//@LIU WEIYUAN: A0086030R

//This class is an alternative check for intellisense function. Since
//Intellisense checks the input before setting the flag to allow users
//to execute appropriate commands, there is a need to provide an
//alternative which are the shortcuts that needs to be executed at the
//start of the program but are also blocked since the flag has not
//been set by intellisense
class QuickCheck
{
private:
    const static string UNDO_COMMAND;
    const static string REDO_COMMAND;
    const static string DISPLAY_COMMAND;
    const static string TODAY_COMMAND;
    const static string FLOAT_COMMAND;

public:
    bool static shortcutCheck(string input);
};

#endif // QUICKCHECK_H
