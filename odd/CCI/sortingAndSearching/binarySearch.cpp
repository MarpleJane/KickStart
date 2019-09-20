#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& array, int x)
{
   int l, m, h;
   l = 0, h = array.size() - 1;
   while (l <= h)
   {
      m = (l + h) / 2;
      if (array[m] < x)
         l = m + 1;
      else if (array[m] > x)
         h = m - 1;
      else
         return m;
   }
   return -1;
}

int main()
{
   vector<int> array = {2, 3, 5, 7, 11, 13, 17};
   cout << binarySearch(array, 5) << endl;
}
