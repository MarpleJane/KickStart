#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string stringCompression(string str)
{
   string result;
   int cnt = 0;
   for (int i = 0; i < str.size(); i ++)
   {
      cnt ++;
      if (i >= str.size() || str[i] != str[i + 1])
      {
         stringstream ss;
         ss << cnt;
         result.append(str[i] + ss.str());
         cnt = 0;
      }
   }
   
   if (str.size() == result.size())
   {
      return str;
   }
   return result;
}

int main()
{
   cout << stringCompression("aabcccccaaa") << endl;
}
