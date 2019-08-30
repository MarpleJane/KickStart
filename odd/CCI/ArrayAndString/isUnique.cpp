#include <iostream>
#include <string>

using namespace std;

bool isUnique(string str)
{
   int check = 0;
   for (int i = 0; i < str.size(); i ++)
   {
      int value = str[i] - 'a';
      if (check & (1 << value))
         return false;
      check |= (1 << value);
   }
   return true;
}

int main()
{
   cout << isUnique("AAbcd") << endl;
   cout << isUnique("abcd") << endl;
   cout << isUnique("aabcd") << endl;
   return 0;
}
