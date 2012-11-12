#include "QuickCheck.h"

//@author: A0086030R

const string QuickCheck::UNDO_COMMAND = "undo";
const string QuickCheck::REDO_COMMAND = "redo";
const string QuickCheck::DISPLAY_COMMAND = "display";
const string QuickCheck::TODAY_COMMAND = "today";
const string QuickCheck::FLOAT_COMMAND = "todo";

//Following function will be the only function of quickcheck. It will
//check if the input corresponds to the shortcut for the GUIs
bool QuickCheck::shortcutCheck(string input)
{
    bool commandAppropriate =
            input == UNDO_COMMAND    ||
            input == REDO_COMMAND    ||
            input == DISPLAY_COMMAND ||
            input == TODAY_COMMAND   ||
            input == FLOAT_COMMAND;

    return commandAppropriate;
}
