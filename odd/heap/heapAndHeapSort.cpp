#include <iostream>

using namespace std;

int heap[101];
int n;

void swap(int x, int y)
{
   int t;
   t = heap[x];
   heap[x] = heap[y];
   heap[y] = t;
}

void shiftdown(int i)
{
   int t, flag = 0;
   while (i * 2 <= n && flag == 0)
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
         swap(i, t);
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

int deleteMin()
{
   int t;
   t = heap[1];
   heap[1] = heap[n];
   n --;
   shiftdown(1);
   return t;
}

int main()
{
   int num;
   cin >> num;
   n = num;
   for (int i = 1; i <= n; i ++)
      cin >> heap[i];
   create();
   for (int i = 1; i <= num; i ++)
      cout << deleteMin() << " ";
   cout << endl;

   return 0;
}
