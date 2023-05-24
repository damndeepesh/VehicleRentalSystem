#ifndef string_helper_h
#define string_helper_h

/* include standard cpp Headers */

#include<vector>
#include<sstream>
#include<iterator>

using namespace std;

/* split given string with given delimeter */

extern vector<std::string> split(const string & s, char delimeter);

#endif
