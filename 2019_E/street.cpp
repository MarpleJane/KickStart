#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

#define LL long long

const int MAX = 1e9;
LL f[MAX + 5];
LL interest[MAX + 5];

void findAllDivisor(int x)
{
   LL odd = 0, even = 0;
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

   if (labs(odd - even) <= 2)
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
