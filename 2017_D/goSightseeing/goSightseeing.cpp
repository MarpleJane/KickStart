#include <iostream>
#include <algorithm>
#include <climits>

#define LL long long
using namespace std;

LL dp[2005][2005];
LL S[2005], F[2005], D[2005];
int N;
LL Ts, Tf;

LL nextTime(LL used, LL s, LL f, LL d)
{
   LL delta = used - s;
   int x = 0;
   if (delta > 0)
   {
      if (delta % f == 0)
         x = delta / f;
      else
         x = delta / f + 1;
   }
   return s + x * f + d;
}

int goSightseeing()
{
   for (int i = 0; i <= N; i ++)
      for (int j = 0; j <= N; j ++)
         dp[i][j] = INT_MAX;

   dp[0][0] = 0;
   for (int i = 1; i < N; i ++)
   {
      for (int j = 0; j <= i; j ++)
      {
         if (dp[i-1][j] < INT_MAX)
         {
            dp[i][j] = nextTime(dp[i-1][j], S[i-1], F[i-1], D[i-1]);
         }
         
         if (j && i != N && dp[i-1][j-1] < INT_MAX)
         {
            dp[i][j] = min(dp[i][j], nextTime(dp[i-1][j-1] + Ts, S[i-1], F[i-1], D[i-1]));
         }
      }
   }

//   for (int i = 0; i <= N; i ++)
//   {
//      for (int j = 0; j <= N; j ++)
//         cout << dp[i][j] << "   ";
//      cout << endl;
//   }

   for (int i = N-1; i >= 0; i --)
      if (dp[N-1][i] <= Tf)
      {
         return i;
      }
   return -1;
}

int main()
{
   int T;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      cin >> N >> Ts >> Tf;
      for (int j = 0; j < N-1; j ++)
         cin >> S[j] >> F[j] >> D[j];
      int result = goSightseeing();
      if (result != -1)
         cout << "Case #" << i << ": " << result << endl;
      else
         cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
   }

   return 0;
}
