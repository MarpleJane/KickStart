#include <iostream>
#include <iomanip>
#include <algorithm>
#include <memory.h>

using namespace std;

double a[3][3] = {0.0};

double blackhole()
{
   double x1 = a[0][0];
   double x2 = a[1][0];
   double x3 = a[2][0];
   double maxx = max(x1, max(x2, x3));
   double minn = min(x1, min(x2, x3));
   return (maxx - minn) / 6.0;
}

int main()
{
   int T;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      for (int j = 0; j < 3; j ++)
      {
         for (int k = 0; k < 3; k ++)
            cin >> a[j][k];
      }
      double result = blackhole();
      cout << "Case #" << i << ": " << setprecision(10) << result << endl;
   }
   return 0;
}
