#ifndef DATE_TIME_H_INCLUDED
#define DATE_TIME_H_INCLUDED

using namespace std;

class date_time{private:
    int id;
    int day;
    int month;
    int year;
    int hours;
    int minutes;
    char am_pm;
public:
    date_time();
    date_time(int newID, int newDay, int newMonth, int newYear, int newHours, int newMinutes, char newAMPM);
    int getID();
    int getDay();
    int getMonth();
    int getYear();
    int getHours();
    int getMinutes();
    char getAM_PM();
    void setID(int newID);
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    void setHours(int newHours);
    void setMinutes(int newMinutes);
    void setAM_PM(char newAM_PM);};
void initializeDateTime(date_time dateTimeArr[]);
#endif // DATE_TIME_H_INCLUDED
