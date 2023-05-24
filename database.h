#ifndef database_h
#define database_h

/* Include custom Headers */

#include "vehicle.h"
#include "user.h"
#include "trip.h"
#include "table.cpp"
#include "error.cpp"

using namespace std;

/* 
    This is a Database class and acts as a middleware, so we can hide low-level details like file handling ( add, update records, etc. )
*/

class Database {
    private: 

        /* Database have multiple tables */

        /* Vehicle Table */
        Table<Vehicle> * vehicleTable;

        /* User Table */
        Table<User> * userTable;

        /* Trip Table */
        Table<Trip> * tripTable;

        /*
            Fetch all data from files
            can throw 'IOError' or 'MemoryError'
        */ 

       void fetchAllVehicles() throw (IOError, MemoryError);
       void fetchAllUsers() throw (IOError, MemoryError);
       void fetchAllTrips() throw (IOError, MemoryError);

       void cleanUp();

    public:
        /*
            Constructor can throw 'MemoryError' or 'IOError'
            if the system is out of memory, or I/O Operation cannot be performed, then this error will be thrown
        */

       Database() throw (MemoryError, IOError);
       ~Database();

       /* Get References to database tables */
       /* All are constant pointers to constant objects. So, user can neither change pointer nor the data */

       const Table<Vehicle> * const getVehicleRef() const;
       const Table<User> * const getUserRef() const;
       const Table<Trip> * const getTripRef() const;

       /* Query vehicle by 'registrationNo. */

       const Vehicle * const getVehicle (string registrationNo ) const throw (NoSuchRecordError);

       /* Query user by contactNo. */

       const User * const getUser (string contactNo) const throw (NoSuchRecordError);

       /* Find a vehicle of given type, which is availabe in a given duration */

       const vector<const Vehicle *> getVehicle (Date startDate, Date endDate, VehicleType type ) const;

       /* Add New record of Type T in database */

       template <class T> void addNewRecord (T*record) throw (IOError, MemoryError);

       /* Update record in Database */

       template <class T> void updateRecord (T * record ) throw (IOError, NoSuchRecordError);
};

#endif