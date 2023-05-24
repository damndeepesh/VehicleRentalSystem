#ifndef users_h
#define users_h

/* Include custom Headers */

#include "storable.cpp"

/* Include standard cpp headers */

#include<string>
using namespace std;

/* User class which helps in managing user-related data */
class User : public Storable {
    private:
        /* Name of User */
        string name;
        
        /* Contact Number of User */
        string contact;

        /* Email-id of user */
        string email;
    public: 
        /*
        Constructor
        input : Name of User
        input : Contact Number of user
        input : Email id of user
        input : recordId ( defaults to 0 )
        */

       User ( string name, string contact, string email, long recordId = 0 );

       /*
       Getter method with const attribute i.e. this method is not changing any data of the current object,
       If this method is not marked constant, then it cannot be called from constant object of this class.

       The following snippet will give an error if 'getName' is not marked with const keyword.

       const User * object = new User (...);
       auto name = object->getName();
       */

      string getName () const;
      string getContact () const;
      string getEmail () const;

      /*
      set name of user
      input : New Name of user
      */

     void setName ( string newName );

     /* 
     set contact Numbre of user
     input : new contact number of user
     */

     void setContact ( string newContact );

     /*
     set email-id of user
     input : New Email-id of user
     */

    void setEmail ( string newEmail );

    /* 
    Display record on Screen
    */

   void display () const;

   /*
   Overriden virtual method
   */

  string toString () const;
  void setDataFrom(Storable * s);
};

#endif
