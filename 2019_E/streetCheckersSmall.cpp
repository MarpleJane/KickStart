#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

const int MAX = 1000000;
int f[MAX + 5];
int interest[MAX + 5];

void findAllDivisor(int x)
{
   int odd = 0, even = 0;
   for (int i = 1; i <= sqrt(x); i ++)
   {
      if (x % i == 0)
      {
         if (i & 1)
            odd ++;
         else
            even ++;
         
         if ((x / i) != i)
         {
            if ((x / i) & 1)
               odd ++;
            else
               even ++;
         }
      }
   }

   if (abs(odd - even) <= 2)
      interest[x] = 1;
}

void preSum()
{
   for (int i = 1; i <= MAX; i ++)
      findAllDivisor(i);

   for(int i = 1; i <= MAX; i ++)
      f[i] = f[i - 1] + interest[i];
}

int main()
{
   int T, L, R;
   cin >> T;
   preSum();
   for (int t = 1; t <= T; t ++)
   {
      cin >> L >> R;
      cout << "Case #" << t << ": " << (f[R] - f[L - 1]) << endl;
   }
}
