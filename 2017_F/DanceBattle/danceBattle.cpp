#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int rival[1005];

int danceBattle(int num, int energy)
{
   sort(rival, rival + num);
   int honor = 0;
   for (int r = 0, j = num - 1; r <= j; r ++)
   {
      if (energy > rival[r])
      {
         energy -= rival[r];
         honor ++;
      }
      else if (honor > 0 && r < j)
      {
         energy += rival[j] - rival[r];
         j --;
      }
   }

   return honor;
}

int main()
{
   int T, energy, num;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      cin >> energy >> num;
      memset(rival, 0, sizeof(rival));
      for (int k = 0; k < num; k ++)
      {
         cin >> rival[k];
      }
      int result = danceBattle(num, energy);
      cout << "Case #" << i << ": " << result << endl;
   }
   return 0;
}
