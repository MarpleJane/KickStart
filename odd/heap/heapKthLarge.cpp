#include <iostream>

using namespace std;

const int k = 6;

int heap[100];
int n;

/* build minimum heap */

void swap(int x, int y)
{
   heap[x] = heap[x] + heap[y];
   heap[y] = heap[x] - heap[y];
   heap[x] = heap[x] - heap[y];
}

void shiftDown(int i)
{
   int t, flag = 0;
   while (i * 2 <= k && flag == 0)
   {
      t = i;
      if (heap[i] > heap[i * 2])
         t = i * 2;
      if (i * 2 + 1 <= n)
      {
         if (heap[t] > heap[i * 2 + 1])
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

void adjust()
{
   for (int i = k / 2; i >= 1; i --)
      shiftDown(i);
}

void removeAndAdjust()
{
   for (int i = k + 1; i <= n; i ++)
   {
      if (heap[i] > heap[1])
      {
         heap[1] = heap[i];
         adjust();
      }
   }
}

int main()
{
   int num;
   cin >> num;
   n = num;
   for (int i = 1; i <= num; i ++)
      cin >> heap[i];
   adjust();
   removeAndAdjust();
   cout << heap[1] << endl;
   return 0;
}
