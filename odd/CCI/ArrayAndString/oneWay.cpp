#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

bool oneReplace(string a, string b)
{
   bool foundDifference = false;
   for (int i = 0; i < a.size(); i ++)
   {
      if (a[i] != b[i])
      {
         if (foundDifference)
            return false;
         foundDifference = true;
      }
   }
   return true;
}

bool oneInsert(string a, string b)
{
   int indexa = 0, indexb = 0;
   while (indexa < a.size() && indexb < b.size())
   {
      if (a[indexa] != b[indexb])
      {
         if (indexa != indexb)
            return false;
         indexb ++;
      }
      else
      {
         indexa ++;
         indexb ++;
      }
   }
   return true;
}

bool oneEdit(string a, string b)
{
   int sizea = a.size(), sizeb = b.size();
   if (sizea == sizeb)
      return oneReplace(a, b);
   else if (sizea + 1 == sizeb)
      return oneInsert(a, b);
   else if (sizeb + 1 == sizea)
      return oneInsert(b, a);
   else
      return false;
}

int main()
{
   bool result;
   result = oneEdit("pale", "ple");
   assert(result == true);
   result = oneEdit("pales", "pale");
   assert(result == true);
   result = oneEdit("pale", "bale");
   assert(result == true);
   result = oneEdit("pale", "bake");
   assert(result == false);
}
