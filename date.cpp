/* include custom headers */

#include "date.h"
#include "string_helper.h"

const char DELIMETER = '/' ;

Date :: Date () {
    /* create date from current time */
    time_t now = time(NULL);
    /* 'localtime' returns pointer to statically allocated memory, and we want value pointed by it. */
    this->empty = false;
    this->date = *localtime(&now);
}
Date :: Date ( string date /* Must be in d/m/yyyy */) {
    if(date.length() < 8){
        this->empty = true;
        return;
    }
    this->empty = false;

    /* Split string with given delimeter */
    vector<string> dateComponents = split(date, DELIMETER);

    /* seperate out components */

    int day = stoi(dateComponents[0]);
    int month = stoi(dateComponents[1]);
    int year = stoi(dateComponents[2]);

    time_t now = time(NULL);
    this->date = *localtime(&now);

    this->date.tm_year = year - 1900;
    this->date.tm_mon = month - 1;
    this->date.tm_mday = day;

    mktime(&this->date);
}

bool Date :: isEmpty ( ) const{
    return this->empty;
}

string Date :: toString ( ) const{
    if(this->empty){
        return "";
    }
    stringstream ss;
    ss << this->date.tm_mday << "/" << this->date.tm_mon + 1 << "/" << this->date.tm_year + 1900;
    return ss.str();
}

Date Date :: operator + (int days) { 
    /* Create a new Date */
    Date newDate = *this;

    if(newDate.isEmpty()){
        return newDate;
    }
    /* modify days */
    newDate.date.tm_mday += days;

    /* Create modified Date */
    time_t adjustedDate = mktime(&newDate.date);

    /*Convert time to struct */
    newDate.date = *localtime(&adjustedDate);
    return newDate;
}

bool Date::operator > (Date date) const{
    if(this->isEmpty() || date.isEmpty()){
        return false;
    }
    int yearDiff = this->date.tm_year - date.date.tm_year;
    int monthDiff = this->date.tm_mon - date.date.tm_mon;
    int dayDiff = this->date.tm_mday - date.date.tm_mday;

    if(yearDiff != 0 ){
        return yearDiff > 0;
    }else if(monthDiff != 0){
        return monthDiff > 0;
    }else{
        return dayDiff > 0;
    }
}

bool Date :: operator >= (Date date) const{
    return !(*this < date);
}

bool Date :: operator < ( Date date ) const{
    if(this->isEmpty() || date.isEmpty()){
        return false;
    }

    int yearDiff = this->date.tm_year - date.date.tm_year;
    int monthDiff = this->date.tm_mon - date.date.tm_mon;
    int dayDiff = this->date.tm_mday - date.date.tm_mday;

    if(yearDiff != 0){
        return yearDiff < 0;
    }else if (monthDiff != 0){
        return monthDiff < 0;
    }else{
        return dayDiff < 0;
    }
}

bool Date :: operator <= (Date date) const{
    return !(*this > date);
}