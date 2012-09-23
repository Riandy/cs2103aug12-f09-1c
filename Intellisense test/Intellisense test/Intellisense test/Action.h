#ifndef  ACTION_H
#define ACTION_H
#include <string>

using namespace std;

#define MAXNOOFPARAMETERS 4 // NAME,DATE,PRIORITY,CATEGORY,
#define INAME 0	//INDEX OF NAME IN THE FLAG ARRAY
#define IDATE 1
#define IPRIORITY 2
#define ICATEGORY 3

struct Event
{
	string EventName;
	int Date;
	bool Priority;	
	string command;
	string category;
};
class Action
{
private :
	Event eventDetails;
	int statusCode;
	bool statusFlags[MAXNOOFPARAMETERS];

	//not sure what other details you need for version 0.0 prototype
	//if theres any other fields that you wish to include, do tell me so i can add them in

public:
	Action(void);
	~Action(void);

	string getCommand();
	void setCommand(string);

	string getEventName();
	void setEventName(string);

	int getDate();
	void setDate(int );

	bool getPriority();
	void setPriority(bool);

	string getCategory();
	void setCategory(string);

	int getStatusCode();
	void setStatusCode(int); 

	bool getStatusFlagAt(int);
	void setStatusFlagAt(int,bool);
	
	void setAllStatusFlag();
};



// STATUS CODE
#define INVALIDCOMAND	0
#define VALIDADD		1
#define	VALIDDEL		2
#define VALIDEDIT		3
#define VALIDFIND		4
#define	VALIDDISPLAY	5
#define	VALIDMARK		6

//THIS METHOD IS NOT SCALABLE , might have to use arrays of flag
//ALL ADD ERROR CODE BEGIN WITH 1X 
// NAME DATE PRIORITY CATEGORY
// 1	1    1		  1	
#define ERR_ADD_		10000	//ENTERED FIELDS: NONE	MISSING FIELDS:  NAME, DATE,PRIORITY, CATEGORY
#define ERR_ADD_C		10001	//ENTERED FIELDS: CATEGORY MISSING FIELDS:  NAME, DATE,PRIORITY
#define ERR_ADD_P		10010	//ENTERED FIELDS: PRIORITY  MISSING FIELDS:  NAME,DATE, CATEGORY
#define	ERR_ADD_PC		10011	//ENTERED FIELDS: PRIORITY, CATEGORY	MISSING FIELDS:  NAME, DATE
#define	ERR_ADD_D		10100	//ENTERED FIELDS: DATE	MISSING FIELDS:  NAME, PRIORITY, CATEGORY
#define	ERR_ADD_DC		10101	//ENTERED FIELDS: DATE , CATEGORY MISSING FIELDS: NAME PRIORITY
#define	ERR_ADD_DP		10110	//ENTERED FIELDS:D, P  MISSING FIELDS: N , C 
#define	ERR_ADD_DPC		10111	//ENTERED FIELDS:D,P,C  MISSING FIELDS: N
#define	ERR_ADD_N		11000	//ENTERED FIELDS:N  MISSING FIELDS: DPC
#define	ERR_ADD_NC		11001	//ENTERED FIELDS:N,C  MISSING FIELDS:D,P 
#define ERR_ADD_NP		11010	//ENTERED FIELDS: N P	MISSING FIELDS:D C
#define ERR_ADD_NPC		11011	//ENTERED FIELDS: N,P,C	MISSING FIELDS:D  
#define ERR_ADD_ND		11100	//ENTERED FIELDS:N,D MISSING FIELDS:P C 
#define ERR_ADD_NDC		11101	//ENTERED FIELDS:N D C MISSING FIELDS:P 
#define ERR_ADD_NDP		11110	//ENTERED FIELDS:N D P MISSING FIELDS:C
#define ERR_ADD_NDPC	11111	//ENTERED FIELDS:NDPC  MISSING FIELDS: 


//ALL DEL ERROR CODE BEGIN WITH 2X, .
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

// the one below is for magic number that we used in our intellisense
#define FORMATINVALIDDATE 99999999



#endif;