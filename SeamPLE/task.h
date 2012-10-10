#include <string>
#include <ctime>

using namespace std;


class task
{
private:
    string _description;
    tm _startDate;
    tm _endDate;
    string _priority;
    string _category;
    int _id;


public:
    task(void);
    ~task(void);

    string getEventName();
    void setEventName(string);


    tm getStartDate();
    void setStartDate( tm);
    void setStartDateWithoutTime(tm);

    tm getEndDate();
    void setEndDate( tm);

    string getPriority();
    void setPriority(string);

    string getCategory();
    void setCategory(string);

    int getID();
    void setID(int);


};

