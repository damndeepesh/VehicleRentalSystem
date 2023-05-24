#ifndef trip_h
#define trip_h

/* Include custom Headers */

#include "date.h"
#include "storable.cpp"
#include "user.h"
#include "vehicle.h"

/* Include standard cpp Headers */

#include<string>

using namespace std;

/* trip class which helps to manage trip-related data */

class Trip : public Storable{
    private:

        /* const pointer to constant vehicle in memory */
        /* We Will create vehicle in memory and assign address of that vehicle to 'Vehicle' */
        /* This is a constant pointer so it cannot point to other vehicle object */

        const Vehicle * vehicle;

        /* const pointer to constant user in memory */
        /* we will create user in memory and assign address of that user to 'user' */
        /* This is a constant pointer so it cannot point to ither user object */

        const User * user;

        /* we need to track record of start and end date of the trip so that at the time of booking a trip we can find vehicle that are free in that specific duration */

        /* start date of trip */

        Date startDate;

        /* End date of trip */
        Date endDate;

        /* We also need to keep track of reading of Odometer so that fare can be calculated */

        long startReading;
        long endReading;

        /* Fare of this trip */
        double fare;

        /* Trip is completed or not */

        bool completed;

    public: 

        /* 
        Constructor
        input : Pointer to vehicle in memory
        input : pointer to user in memory
        input : Start date of trip
        input : End date of Trip
        input : Record id ( defaults set to 0 )
        input :  PUC Expiration date
        input : recordId ( defaults set to 0 )
        */

       Trip ( const Vehicle * vehicle, const User * user, Date startDate, Date endDate, long recordId = 0, long startReading = 0, long endReading = 0, double fare = 0.0, bool isComplete = false );

       /* Getter methods with const attribute i.e this method is not changing any data of the current object
        If this method is not marked as constant, then it cannot be called from constant object of this class.

        The following snippet will give an error if 'getUser' is not marked with const keyword.

        const Trip * object = new Trip (...);
        auto user = object->getUser();
        */

       const User & getUser ( ) const;
       const Vehicle & getVehicle ( ) const;
       Date getStartDate ( ) const;
       Date getEndDate ( ) const;
       long getStartReading ( ) const;
       long getEndReading ( ) const;
       long getFare ( ) const;
       bool isCompleted ( ) const;

        /* 
        Start Trip
        input : Start reading of Vehicle's Odometer
        */

       void startTrip ( long startReading );

       /* 
       Complete Trip
       input : End Reading of Vehicle's Odometer
       output : calculate and return fare of trip 
       */

      double completeTrip ( long endReading );

      /* Display record on screen */

      void display ( ) const;

      /* Overridden virtual method */

      string toString ( ) const;

      void setDataFrom ( Storable * s );
};

#endif