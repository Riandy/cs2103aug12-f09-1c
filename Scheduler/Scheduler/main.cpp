#include "scheduler.h"
#include "Action.h"
#include "calender.h"
using namespace std;

int main()
{
	//dummy main for testing purpose
	Action newAction;
	tm startDate,endDate;
	startDate.tm_yday=12;
	startDate.tm_mon=03;
	startDate.tm_year=1993;
	startDate.tm_hour=19;
	startDate.tm_min=07;
	startDate.tm_sec=55;

	endDate=startDate;
	endDate.tm_year=2012;

	newAction.setEventName("is for testing purpose");
	newAction.setCategory("Test");
	newAction.setStartDate(startDate);
	newAction.setEndDate(endDate);
	newAction.setPriority("LOLOLO");
	newAction.setID(4);
	newAction.setCommand("DELETE");
	vector<string> result;


	for(int i=0;i< result.size();i++)
		cout<<result.at(i)<<endl;
	return 0;
}