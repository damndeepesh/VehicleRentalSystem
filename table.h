#ifndef table_h
#define table_h

/* Include custom Headers */

#include "storable.cpp"
#include "error.cpp"

/* Include standard cpp headers */

#include<vector>
#include<string>
#include<fstream>

using namespace std;

/*
    This is templatedd (generic) class. It  represents in-memory database table.
    Table can be of type 'Vehicle', 'User', 'Trip'.
*/

template <class T> class Table {
    private:
        /* Name of database file */
        string fileName;

        /* File stream used to read and write data from database file. */

        fstream fileStream;

        /* Original data is stored here */
        /* 'Vector' is a container type and behaves like dynamic array */

        vector<Storable *> * records = NULL;

        /* This is a private method */
        /* We Will Share pointer of Record with recordID ='recordId' */
        /* This is intentional, hence it is kept as private method */

        T * getReferenceOfRecordForId (long recordId) const throw (NoSuchRecordError);

        /* This is a private function. it is called after inserting new record or updating data */

        /* This function writes data to file */

        void writeTofile ( ) throw ( IOError );

        /* 
        Add new record to database
        input : fileName of Database 
        This method can throw 'MemoryError' or 'IOError'
        */

       const T * const addNewRecord ( T data ) throw ( MemoryError, IOError );

       /* 
       Update record in databse
       input : new Record of Generic type 'T'
       This method can throw 'IOError'
       */

      void updateRecord ( T updateRecord ) throw ( IOError, NoSuchRecordError );

      public:
        /*
        Constructor
        input : fileName of Database
        */

       Table (string fileName) throw (MemoryError);
       ~Table ( );

       /* 
       Get 'recordId' for next record
       */

      long getNextRecordId ( ) const;

      /* 
      Get Record for Particular 'recordId'
      input : recordId of record

      we will return T* const ( constant pointer to constant record)
      So user cannot modify that record accidently.
      This method can throw 'NoSuchRecord' Exception
      */

     const T * const getRecordForId ( long recordId ) const throw ( NoSuchRecordError);

     /* Class database can use this class 'Private methods and variables */
     /* We will use 'getReferenceRecordId' to get actual record reference */

     friend class Database;
};

#endif