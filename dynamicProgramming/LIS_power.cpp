#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
   int dp[10];
   fill(dp, dp+10, 1);
   int n, data[10];
   cin >> n;
   for (int i = 1; i <= n; i ++)
      cin >> data[i];

   for (int i = 1; i <= n; i ++)
   {
      for (int j = 1; j < i; j ++)
      {
         if (data[j] < data[i] && dp[i] < dp[j] + 1)
            dp[i] = dp[j] + 1;
      }
   }

   cout << dp[n] << endl;
   return 0;
}
