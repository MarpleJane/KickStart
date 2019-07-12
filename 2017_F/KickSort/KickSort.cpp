#include <iostream>
#include <memory.h>

using namespace std;

int a[100000];

bool kickSort(int p[], int n)
{
   int pivot = (n - 1) / 2;
   int temp = n;
   int flag = 1, sum = 1;
   if (n % 2 == 0)
      flag = 1;
   else
      flag = -1;
   bool result = true;
   while (temp > 1)
   {
      if (p[pivot] != temp && p[pivot] != 1)
      {
         result = false;
         break;
      }
      sum ++;
      pivot += flag * (sum / 2);
      temp --;
      if (temp % 2 == 0)
         flag = 1;
      else
         flag = -1;
   }

   return result;
}

void execute()
{
   int T, N;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      cin >> N;
      memset(a, 0, sizeof(a));
      for (int j = 0; j < N; j ++)
         cin >> a[j];
      bool result = kickSort(a, N);
      cout << "Case #" << i << ": " << (result ? "YES" : "NO") << endl;
   }

   return;
}

int main()
{
   execute();
   return 0;
}
