#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

int e[55][55], n, m, p;
double dp[205][55];

void init()
{
   for (int i = 1; i <= n; i ++)
   {
      for (int j = 1;j <= n; j ++)
      {
         if (i == j)
            e[i][j] = 0;
         else
            e[i][j] = INT_MAX;
      }
   }

   int t1, t2, t3;
   for (int i = 1; i <= m; i ++)
   {
      cin >> t1 >> t2 >> t3;
      e[t1][t2] = t3;
      e[t2][t1] = t3;
   }
}

void floyd()
{
   for (int k = 1; k <= n; k ++)
   {
      for (int i = 1; i <= n; i ++)
      {
         for (int j = 1; j <= n; j ++)
         {
            if (e[i][k] < INT_MAX && e[k][j] < INT_MAX && e[i][j] > e[i][k] + e[k][j])
               e[i][j] = e[i][k] + e[k][j];
         }
      }
   }

   for (int k = 1; k <= p; k ++)
   {
      for (int i = 1; i <= n; i ++)
         dp[k][i] = 0;
   }
}

double caculate()
{
   for (int k = 0; k <= p; k ++)
   {
      for (int l = 1; l <= n; l ++)
      {
         if (k == 0)
            dp[k][l] = 0;
         else
         {
            double temp;
            temp = 0;
            for (int i = 1; i <= n; i ++)
            {
               if (i == l)
                  continue;
               temp += dp[k-1][i] + e[l][i];
            }
            dp[k][l] = temp / (n - 1);
         }
      }
   }
   return dp[p][1];
}

int main()
{
   int T;
   double result;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      cin >> n >> m >> p;
      init();
      floyd();
      result = caculate();
      cout << "Case #" << i << ": " << result << endl;
   }

   return 0;
}
