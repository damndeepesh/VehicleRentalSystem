#ifndef vehicle_h
#define vehicle_h

/* Include custom Headers */
#include "date.h"
#include "storable.cpp"

/* include standard cpp headers */

#include<string>
using namespace std;

/* support for different kinds of vehicles for different purposes */

typedef enum {bike = 1, car = 2, towera = 3} VehicleType;

/* Vehicle class which helps to manage vehicle related data */

class Vehicle: public Storable{
    private:
        /* Registration number given by RTO */
        string registrationNumber;

        /* Type of vehicle give by 'VehicleType' enum */
        VehicleType type;

        /* No. of seats this vehicle has */
        int seats;

        /* Name of the vehicle manufacturer */
        string companyName;

        /* Each vehicle has different price per km */
        /* This will be required to calculate fare when trip ends */

        double pricePerKm;

        /* This is the date when PUC wull expire */
        Date PUCExpirationDate;

    public:

        /* 
         Constructor
         input : Registration number of vehicle
         input : Vehicle Type 
         input : No. of Seats
         input : Company Name
         input : Price Per Km
         input : PUC Expiration date
         input : recordId (defaults to 0)    
        */

       Vehicle (string registrationNumber, VehicleType type, int seats, string companyName, double pricePerKm, Date PUCExpirationDate, long recordId = 0);

       /*
        Getter methods with const attribute i.e.  this method is not changingg any data of the current object.
        if this method is not marked as constant, then it cannot be called from constant object of this class.
        Following snippet will give an error if 'getRegistrationNumber' is not marked with const keyword.

        const Vehicle * object - new Vehicle ( ... );
        auto registrationNo = object->getRegistrationNumber();
       */       

      string getRegistrationNumber ( ) const;
      VehicleType getVehicleType ( ) const;
      string getVehicleTypeName ( ) const;
      int getSeats ( ) const;
      string getCompanyName ( ) const;
      double getPricePerKm ( ) const;
      Date getPUCExpirationDate ( ) const;

      /* 
        Function which sets new price of the vehicle
        input : New Price of Vehicle
      */

     void setPricePerKm ( double newPrice );

     /* Display record on screen */
     void display ( ) const;

     /* Overridden virtual method */
     string toString ( ) const;

     void setDataFrom ( Storable * s); 
};

#endif