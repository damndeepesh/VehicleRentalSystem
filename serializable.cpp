/* Include Standard cpp headers */

#include<string>
using namespace std;

/*
    This is Serializable class and it is an abstract class
    Any class derieved from this calss must implement 'toString' method
*/

class Serializable{
    public:
    /*Pure virtual function*/
    /*'Serializabele' class does not know what 'toString' method will do */
    /* it is the responsibility of derieved class to implement this method */
    /* Each derieved class has its own 'toString' implementation */

    virtual string toString() const = 0;
};
