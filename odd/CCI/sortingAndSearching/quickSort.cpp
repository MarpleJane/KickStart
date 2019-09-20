#include <iostream>

using namespace std;

int partition(int array[], int l, int r)
{
   int pivot = array[l];
   while (l < r)
   {
      while (l < r && array[r] >= pivot)
         r --;
      if (l < r)
         array[l] = array[r];

      while (l < r && array[l] <= pivot)
         l ++;
      if (l < r)
         array[r] = array[l];
   }
   array[l] = pivot;
   return l;
}

void quickSort(int array[], int l, int r)
{
   if (l < r)
   {
      int p = partition(array, l, r);
      quickSort(array, l, p - 1);
      quickSort(array, p + 1, r);
   }
}

int main()
{
   int array[] = {8, 7, 9, 10, 1, 5};
   int n = sizeof(array) / sizeof(array[0]);
   quickSort(array, 0, n - 1);
   for (int i = 0; i < n; i ++)
      cout << array[i] << " ";
   cout << endl;
}
