#include <string>

string intToStr(int number)
{
   stringstream ss;
   ss << number;
   return ss.str();
}
