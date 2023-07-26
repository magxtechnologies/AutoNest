#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H
#include <Wire.h>
#include <Adafruit_BusIO_Register.h>
#include "RTClib.h"

/*
 * Class responsible for Time Related Issues, like getting current time from RTC 
 * Manual Time and Date Adjustment
 * converting time and Date obj. into String
 */
class TimeManager{
    private:
    RTC_DS1307 RTC;

    public:
    typedef struct
    {
        int Hour;
        int Minute;
        int Second;
    }Time;
    typedef struct
    {
        int day;
        int month;
        int year;
    }Date;
    
    void init()
    {
        RTC.begin();
        if (! RTC.isrunning())
        {
            Serial.println("RTC is NOT running!");
            RTC.adjust(DateTime(__DATE__, __TIME__));
        }


    }
    Time getCurrentTime()
    {
        DateTime now=RTC.now();
        Time currentTime;
        currentTime.Hour=now.hour();
        currentTime.Minute=now.minute();
        currentTime.Second=now.second();
        return currentTime;
    }
    Date getDate()
    {
        DateTime now=RTC.now();
        Date currentDate;
        currentDate.day=now.day();
        currentDate.month=now.month();
        currentDate.year=now.year();
        return currentDate;

    }
    void SetTime(int hour,int minute,int second)
    {
        DateTime curr=RTC.now();
        DateTime newTime(curr.year(),curr.month(),curr.day(),hour,minute,second);
        RTC.adjust(newTime);
    }
    /*
    *This Method accept integer datatype
    *SetDate( int year , int month , int day)
    */
    void SetDate(int year,int month,int day)
    {
        DateTime curr=RTC.now();
        DateTime newTime(year,month,day,curr.hour(),curr.minute(),curr.second());
        RTC.adjust(newTime);

    }

    String dateFormatter(Date dt,char c)
    {
        return String(dt.day) + c + String(dt.month) + c + String(dt.year);
    }

    String timeString(Time t,char c)
    {
        return String(t.Hour) +c+ String(t.Minute) + c + String(t.Second);
    }



};
#endif //TIME_MANAGER_H

