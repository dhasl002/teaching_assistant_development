#ifndef DATE_H
#define DATE_H


class date
{
    public:
        date();
        int Getyear() { return year; }
        void Setyear(int val) { year = val; }
        int Getmonth() { return month; }
        void Setmonth(int val) { month = val; }
        int Getday() { return day; }
        void Setday(int val) { day = val; }
        int Gethour() { return hour; }
        void Sethour(int val) { hour = val; }
        int Getminutes() { return minutes; }
        void Setminutes(int val) { minutes = val; }
    protected:
    private:
        int year;
        int month;
        int day;
        int hour;
        int minutes;
};

#endif // DATE_H
