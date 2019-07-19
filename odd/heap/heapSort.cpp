#include <iostream>

using namespace std;

int heap[101];
int n;

void swap(int x, int y)
{
   heap[x] = heap[x] + heap[y];
   heap[y] = heap[x] - heap[y];
   heap[x] = heap[x] - heap[y];
}

void shiftdown(int i)
{
   int t, flag = 0;
   while (i * 2 <= n && flag == 0)
   {
      t = i;
      if (heap[i] < heap[i * 2])
         t = i * 2;
      if (i * 2 + 1 <= n)
      {
         if (heap[t] < heap[i * 2 + 1])
            t = i * 2 + 1;
      }
      if (t != i)
      {
         swap(t, i);
         i = t;
      }
      else
         flag = 1;
   }
}

void create()
{
   for (int i = n / 2; i >= 1; i --)
      shiftdown(i);
}

void heapSort()
{
   while (n > 1)
   {
      swap(1, n);
      n --;
      shiftdown(1);
   }
}

int main()
{
   int num;
   cin >> num;
   n = num;
   for (int i = 1; i <= num; i++)
      cin >> heap[i];
   create();
   heapSort();
   for (int i = 1; i <= num; i ++)
      cout << heap[i] << " ";
   cout << endl;
   return 0;
}
