#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
   int temp = a;
   a = b;
   b = temp;
}

// O(lgn)
void build(int array[], int i, int n)
{
   int left = 2 * i;
   int right = 2 * i + 1;
   int index = i;

   if (left < n && array[left] > array[i])
      index = left;
   if (right < n && array[right] > array[i])
      index = right;

   if (index != i)
   {
      swap(array[i], array[index]);

      build(array, index, n);
   }
}

// O(nlgn)
void heapSort(int array[], int n)
{
   for (int i = (n / 2 - 1); i >= 0; i --)
      build(array, i, n);

   for (int i = n - 1; i >= 0; i --)
   {
      swap(array[0], array[i]);

      build(array, 0, i);
   }
}

int main()
{
//   int array[] = {4, 10, 3, 5, 1};
   int array[] = {12, 11, 13, 5, 6, 7};
   heapSort(array, sizeof(array) / sizeof(array[0]));
   for (int i = 0; i < sizeof(array) / sizeof(array[0]); i ++)
      cout << array[i] << " ";
   cout << endl;
   return 0;
}
