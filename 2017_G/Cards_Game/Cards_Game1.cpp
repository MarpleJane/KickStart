#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory.h>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int rb[2][5];
int book[5] = {0, 0, 0, 0, 0};
long minn, ans;
int cards;

void dfs(int step)
{
   if (step >= cards - 1)
   {
      if (ans < minn)
         minn = ans;
      cout << "result: " << minn << endl;
      return;
   }

   for (int i = 0; i < cards; i ++)
   {
      cout << "Step: " << step << ", " << "i: " << i << endl;
      if (book[i] == 0)
      {
         int temp = INT_MAX;
         book[i] = 1;
         for (int j = 0; j < cards; j ++)
         {
            if (book[j] == 0)
            {
               temp = min(temp, rb[0][i] ^ rb[1][j]);
               temp = min(temp, rb[0][j] ^ rb[1][i]);
            }
         }
         cout << "Temp: " << temp << endl;
         ans += temp;
         dfs(step + 1);
         book[i] = 0;
         ans -= temp;
      }
   }

   return;
}

void execute()
{
   ifstream inobj;
   ofstream outobj;
   inobj.open("B-large-practice.in");
   outobj.open("B-large-practice.out");
   if (!inobj.is_open())
   {
      cout << "Error to open input file" << endl;
      exit(1);
   }
   if (!outobj.is_open())
   {
      cout << "Error to open output file" << endl;
      exit(1);
   }

   int cases;
   inobj >> cases;
   for (int i = 0; i < cases; i ++)
   {
      inobj >> cards;
      minn = INT_MAX;
      ans = 0;
      for (int j = 0; j < cards; j ++)
      {
         inobj >> rb[0][j];
      }
      for (int j = 0; j < cards; j ++)
      {
         inobj >> rb[1][j];
      }
      dfs(0);
      outobj << "Case #" << i + 1 << ": " << minn << endl;
   }
   inobj.close();
   outobj.close();
}

int main()
{
   execute();

   return 0;
}
