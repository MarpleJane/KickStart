#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long

const int MAXR = 4e5;
const int MAXQ = 1e5;
int x[MAXR + 5], y[MAXR + 5], z[MAXR + 5];
int l[MAXR + 5], r[MAXR + 5], k[MAXQ + 5];
int a[4], b[4], c[4], m[4];

int main()
{
   int T, N, Q;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      cin >> N >> Q;
      cin >> x[1] >> x[2] >> a[1] >> b[1] >> c[1] >> m[1];
      cin >> y[1] >> y[2] >> a[2] >> b[2] >> c[2] >> m[2];
      cin >> z[1] >> z[2] >> a[3] >> b[3] >> c[3] >> m[3];
      l[1] = min(x[1], y[1]) + 1, l[2] = min(x[2], y[2]) + 1;
      r[1] = max(x[1], y[1]) + 1, r[2] = max(x[2], y[2]) + 1;
      k[1] = z[1] + 1, k[2] = z[2] + 1;
      for (int j = 3; j <= N)
      {
         x[j] = (a[1] * x[j - 1] + b[1] * x[j - 2] + c[1]) % m[1];
         y[j] = (a[2] * y[j - 1] + b[2] * y[j - 2] + c[2]) % m[2];
         l[j] = min(x[j], y[j]) + 1;
         r[j] = max(x[j], y[j]) + 1;
      }
      for (int j = 3; j <= Q)
      {
         z[j] = (a[3] * z[j - 1] + b[3] * z[j - 2] + c[3]) % m[3];
         k[j] = z[j] + 1;
      }
   }
}
