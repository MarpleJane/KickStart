#include <iostream>

using namespace std;

void merge(int array[], int l, int m, int r)
{
   int n1 = m - l + 1; // counts of [l, m];
   int n2 = r - m;  // counts of [m + 1, r];

   int L[n1], R[n2];
   for (int i = 0; i < n1; i ++)
      L[i] = array[l + i];
   for (int i = 0; i < n2; i ++)
      R[i] = array[m + 1 + i];

   int i, j, k;
   i = j = 0;
   k = l;
   while (i < n1 && j < n2)
   {
      if (L[i] < R[j])
      {
         array[k] = L[i];
         i ++;
      }
      else
      {
         array[k] = R[j];
         j ++;
      }
      k ++;
   }

   while (i < n1)
   {
      array[k] = L[i];
      i ++;
      k ++;
   }

   while (j < n2)
   {
      array[k] = R[j];
      j ++;
      k ++;
   }
}

void mergeSort(int array[], int l, int r)
{
   if (l < r)
   {
      int m = (l + r) / 2;
      mergeSort(array, l, m);
      mergeSort(array, m + 1, r);
      merge(array, l, m, r);
   }
}

int main()
{
   int array[] = {12, 11, 13, 5, 6, 7};
   int arrSize = sizeof(array) / sizeof(array[0]);
   mergeSort(array, 0, arrSize - 1);
   for (int i = 0; i < arrSize; i ++)
      cout << array[i] << " ";
   cout << endl;
}
