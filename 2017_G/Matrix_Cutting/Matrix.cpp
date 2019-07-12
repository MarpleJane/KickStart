#include <iostream>
#include <algorithm>
#include <limits.h>
#include <fstream>
#include <cstdlib>

using namespace std;

int a[11];

int dp(int l, int r)
{
   int ans = 0;
   int minn = INT_MAX;
   if (l == r)
      minn = 0;
   for (int i = l; i < r; i ++)
   {
      ans = max(ans, dp(l, i) + dp(i+1, r));
   }

   for (int i = l; i <= r; i ++)
      minn = min(minn, a[i]);
   //cout << l << " " << r << " " << minn << " " << ans << endl;

   return minn + ans;
}

void execute()
{
   ifstream inobj;
   ofstream outobj;
   inobj.open("C-small-practice.in");
   //inobj.open("test.in");
   outobj.open("C-small-practice.out");
   if (!inobj.is_open())
   {
      cout << "Fail to open input" << endl;
      exit(1);
   }
   if (!outobj.is_open())
   {
      cout << "Fail to open output" << endl;
      exit(1);
   }

   int t, n, m;
   inobj >> t;
   for (int i = 0; i < t; i ++)
   {
      inobj >> n >> m;
      for (int j = 0; j < m; j ++)
         inobj >> a[j];
      int result = dp(0, m-1);
      outobj << "Case #" << i + 1 << ": " << result << endl;
   }
   inobj.close();
   outobj.close();
}

int main()
{
   execute();
   return 0;
}
