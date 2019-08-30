#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

bool isSubstring(string str1, string str2)
{
   string str3 = str2 + str2;
   string::size_type index = str3.find(str1);
   if (index != string::npos)
      return true;
   else
      return false;
}

int main()
{
   bool result = isSubstring("waterbottle", "erbottlewat");
   assert(result == true);
   result = isSubstring("waterbottle", "rebottlewat");
   assert(result == false);
}
