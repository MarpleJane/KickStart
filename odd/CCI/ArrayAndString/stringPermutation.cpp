#include <iostream>
#include <string>

using namespace std;

void permutation(string str, string prefix)
{
   if (str.size() == 0)
      cout << prefix << endl;
   else
   {
      for (int i = 0; i < str.size(); i ++)
      {
         string rem = str.substr(0, i) + str.substr(i + 1, str.size() - i - 1);
         permutation(rem, prefix + str.substr(i, 1));
      }
   }
}

int main()
{
   permutation("abc", "");
}
