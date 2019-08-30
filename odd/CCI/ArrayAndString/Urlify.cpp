#include <iostream>
#include <string>

using namespace std;

string Urlify(string str, int len)
{
   int space = 0;
   for (int i = 0; i < str.size(); i ++)
   {
      if (isspace(str[i]))
         space ++;
   }

   string result(str.size() + space * 2, 'x');
   int j = result.size();
   for (int i = str.size() - 1; i >= 0; i --)
   {
      if (isspace(str[i]))
      {
         string sp = "%20";
         j --;
         result[j] = sp[2];
         j --;
         result[j] = sp[1];
         j --;
         result[j] = sp[0];
      }
      else
      {
         j --;
         result[j] = str[i];
      }
   }
   return result;
}

int main()
{
   cout << Urlify("Mr John Smith", 13) << endl;
}
