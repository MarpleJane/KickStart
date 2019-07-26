#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N, Q, S;

int magicalThinking(string frnd, string my)
{
   int agree = 0;
   for (int i = 0; i < frnd.size(); i ++)
   {
      if (frnd[i] == my[i])
         agree ++;
   }
   int delta = abs(S - agree);
   return Q - delta;
}

int main()
{
   int T;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      cin >> N >> Q;
      string frnd, my;
      cin >> frnd >> my;
      cin >> S;
      cout << "Case #" << i << ": " << magicalThinking(frnd, my) << endl;
   }

   return 0;
}
