#ifndef Date_h
#define Date_h

/* Include custom Header */

#include"storable.cpp"

/* Include standard cpp headers */

#include<ctime>
#include<string>

using namespace std;
typedef struct Date: Serializable {
    private:
        /* Struture holding date & time info */
        struct tm date;

        bool empty;
    public:
        /* Constructor, create date from string */
        Date (string date );

        /* Create date from current time */
        Date ( );

        /* Add given number of days in this date */
        Date operator + (int days);

        /* if this date is greater than given date */
        bool operator > (Date date) const;

        /* If this date is greater than or equal to given date  */
        bool operator >= (Date date) const;

        /* If this date is less than given date */
        bool operator < (Date date) const;

        /* if this date is less than or equal to given date */
        bool operator <= (Date date) const;

        bool isEmpty ( ) const;
        string toString ( ) const;
} Date;

#endif