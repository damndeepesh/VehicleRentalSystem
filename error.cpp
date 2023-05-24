#ifndef error_cpp
#define error_cpp

/*Include standard cpp headers */
#include<string>
using namespace std;

class Error{
    private:
        string message;
    public:
        Error(string message) {this->message = message; }
        string getMessage () const {return this->message;}
};

class NoSuchRecordError : public Error{
    public:
        NoSuchRecordError() : Error ("No such error Found") {};
};

class IOError : public Error {
    public:
        IOError() : Error ("I/O error could not open or process file make sure 'Vehicles.txt', 'trips.txt' and 'users.txt' file exists in this directory"){}; 
};

class MemoryError : public Error{
    public: 
        MemoryError() : Error ("System out of memory") {};
};

#endif