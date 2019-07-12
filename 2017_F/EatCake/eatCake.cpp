#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   int cakedp[10002];
   cakedp[0] = 0;
   for (int i = 1; i <= 10000; i ++)
   {
      cakedp[i] = cakedp[i - 1] + 1;
      for (int j = 2; j * j <= i; j ++)
         cakedp[i] = min(cakedp[i], cakedp[i - j * j] + 1);
   }

   int T, N;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      cin >> N;
      cout << "Case #" << i << ": " << cakedp[N] << endl;
   }

   return 0;
}
