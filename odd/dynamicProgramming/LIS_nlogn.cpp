#include <iostream>

using namespace std;

int main()
{
   int n, a[10], f[10];
   cin >> n;
   for (int i = 1; i <= n; i ++)
   {
      cin >> a[i];
      f[i] = 0x7fffffff;
   }

   f[1] = a[1];
   int len = 1;
   for(int i = 2; i <= n; i ++)
   {
      int l = 0, r = len, mid;
      if (a[i] > f[len])
         f[++len] = a[i];
      else
      {
         while (l < r)
         {
            mid = (l + r) / 2;
            if (f[mid] > a[i])
               r = mid;
            else
               l = mid + 1;
         }
         f[l] = min(a[i], f[l]);
      }
   }
   cout << len << endl;
   return 0;
}
