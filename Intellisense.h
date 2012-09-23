#ifndef INTELLISENSE_H
#define INTELLISENSE_H
#include <sstream>
#include <string>
#include <iostream>// for debugging purpose
#include <algorithm>
using namespace std;

//MAYBE PUT IN ENUM AS STATUS CODE
#define INVALIDCOMAND	0
#define VALIDADD		1
#define	VALIDDEL		2
#define VALIDEDIT		3
#define VALIDFIND		4
#define	VALIDDISPLAY	5
#define	VALIDMARK		6
//ALL ADD ERROR CODE BEGIN WITH 1X EG 11,12,13
#define	ERR_ADD_D	11	//INVALID DATE OR NO DATE
#define ERR_ADD_P	12	//INVALID PRIORITY ASSUMING DATE IS K
//WE CAN EXPAND THIS FORMAT TO 1111 SOMETHING LIKE BITS WHERE EACH BIT REPRESENT A CERTAIN FIELD
//ALL DEL ERROR CODE BEGIN WITH 2X, EG 21,22,23...
#define ERR_DEL_T 21	//INVALID TASK NAME OR NOT FOUND

//ALL EDIT ERROR CODE BEGIN WITH 3X
#define ERR_EDIT_NT 30 // NO FIELDS ENTERED TO EDIT
#define ERR_EDIT_T 31 // TASK DOES NOT EXIST
#define ERR_EDIT_D 32 //DATE FORMAT WRONG
#define ERR_EDIT_P 33 //INVALID PRIORITY
//ALL FIND ERROR CODE BEGIN WITH 4X
#define ERR_FIND_D 41 //DATE FORMAT INCORRECT
#define ERR_FIND_P 42//PRIORITY IS INVALID

//ALL DISPLAY ERROR CODE BEGIN WITH 5X
#define ERR_DSP_D 51 //DATE FORMAT IS INVALID

//ALL MARK ERROR CODE BEGIN WITH 6X
#define ERR_MARK_T 61 //TASK NOT FOUND
#define ERR_MARK_D 62 // DATE FORMAT IS INVALID
//may have to extend to array of  acceptable status code, for all the conditions for the command to be accepted

// the one below is for magic number that we used in our intellisense
#define FORMATINVALIDDATE 99999999

struct action
{
	int status;
	string name;
	int date;//as discussed we store in an int DDMMYYYY
	//int day;
	//int month;
	//int year;
	char priority;
};

class Intellisense
{
private:
public:
	Intellisense(void);
	~Intellisense(void);
	action check(string query);
};

#endif;