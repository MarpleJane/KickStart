#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

//bool checkPermutation(string a, string b)
//{
//   int lenA = a.size();
//   int lenB = b.size();
//   if (lenB < lenA)
//   {
//      string tmp = b;
//      b = a;
//      a = tmp;
//   }
//
//   sort(a.begin(), a.end());
//   set<string> setB;
//   for(int i = 0; i < b.size(); i ++)
//   {
//      string subB = b.substr(i, a.size());
//      sort(subB.begin(), subB.end());
//      setB.insert(subB);
//   }
//
//   if (setB.count(a))
//      return true;
//   else
//      return false;
//}

bool checkPermutation(string a, string b)
{
   int lenA = a.size();
   int lenB = b.size();
   if (lenA != lenB)
      return false;
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   if (a != b)
      return false;
   return true;
}


int main()
{
   cout << checkPermutation("abc", "cdebacs") << endl;
   cout << checkPermutation("abc", "dab") << endl;
   cout << checkPermutation("dog", "god") << endl;
}
