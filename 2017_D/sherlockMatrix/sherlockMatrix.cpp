#include <iostream>

#define LL long long

using namespace std;

int N, K, A1, B1, C, D, E1, E2, F;
LL m[100005][100005];
LL a[100005], b[100005];
LL x[100005], y[100005];
LL r[100005], s[100005];

void createXY()
{
   x[1] = A1;
   y[1] = B1;
   for (int i = 2; i <= N; i ++)
   {
      x[i] = (C * x[i - 1] + D * y[i - 1] + E1) % F;
      y[i] = (D * x[i - 1] + C * y[i - 1] + E2) % F;
   }
}

void createRS()
{
   r[1] = s[1] = 0;
   for (int i = 2; i <= N; i ++)
   {
      r[i] = (C * r[i - 1] + D * s[i - 1] + E1) % 2;
      s[i] = (D * r[i - 1] + C * s[i - 1] + E2) % 2;
   }
}

void createAB()
{
   a[1] = A1;
   b[1] = B1;
   for (int i = 2; i <= N; i ++)
   {
      a[i] = (-1) * r[i] * x[i];
      b[i] = (-1) * s[i] * y[i];
   }
}

void createMatrix()
{
   for (int i = 1; i <= N; i ++)
   {
      for (int j = 1; j <= N; j ++)
      {
         m[i][j] = a[i] * b[j];
      }
   }
}

int main()
{
   int T;
   cin >> T;
   for (int i = 1; i <= T; T ++)
   {
      cin >> N >> K >> A1 >> B1 >> C >> D >> E1 >> E2 >> F;
    //  memset(m, 0, sizeof(m));
    //  memset(a, 0, sizeof(a));
    //  memset(b, 0, sizeof(b));
    //  memset(x, 0, sizeof(x));
    //  memset(y, 0, sizeof(y));
    //  memset(r, 0, sizeof(r));
    //  memset(s, 0, sizeof(s));
      createXY();
      createRS();
      createAB();
      createMatrix();
   }
   for (int i = 1; i <= N; i ++)
   {
      for (int j = 1; j <= N; j ++)
         cout << m[i][j] << "  ";
      cout << endl;
   }

   return 0;
}
