#include <iostream>
#include <algorithm>

using namespace std;

// distinct
int magicIndexDistinct(int array[], int left, int right)
{
   if (right < left)
      return -1;

   int mid = (left + right) / 2;
   if (mid == array[mid])
      return mid;
   else if (array[mid] < mid)
      return magicIndexDistinct(array, mid + 1, right);
   else
      return magicIndexDistinct(array, left, mid - 1);
}

// not distinct
int magicIndexNotDistinct(int array[], int left, int right)
{
   if (right < left)
      return -1;

   int mid = (left + right) / 2;
   if (mid == array[mid])
      return mid;

   int minn = min(mid - 1, array[mid]);
   if (minn >= 0)
      return magicIndexNotDistinct(array, left, minn);

   int maxx = max(array[mid], mid + 1);
   return magicIndexNotDistinct(array, maxx, right);
}

int main()
{
   int array[11] = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
   cout << magicIndexDistinct(array, 0, 11) << endl;

   int array2[11] = {-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};
   cout << magicIndexNotDistinct(array2, 0, 11) << endl;
   return 0;
}
