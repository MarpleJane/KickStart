#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float median(vector<int>& x, vector<int>& y, int start, int end) // start & end are for smallest array
{
   int maxLeft = -1, minRight = -1;
   int partitionx = (start + end) / 2;
   int partitiony = (x.size() + y.size() + 1) / 2 - partitionx;
   if (partitionx < 0)
      maxLeft = y[partitiony - 1];
   else if (partitionx > x.size())
      minRight = y[partitiony];
   else
   {
      if (x[partitionx - 1] <= y[partitiony] && y[partitiony - 1] <= x[partitionx])
      {
         maxLeft = max(x[partitionx - 1], y[partitiony - 1]);
         minRight = min(x[partitionx], y[partitiony]);
         if ((x.size() + y.size()) & 1)
         {
            if ((partitionx + partitiony) * 2 > x.size() + y.size())
               return maxLeft;
            else
               return minRight;
         }
         else
            return (maxLeft + minRight) * 1.0 / 2.0;
      }
      else if (x[partitionx - 1] > y[partitiony])
         end --;
      else
         start ++;
      median(x, y, start, end);
   }
}

int main()
{
   vector<int> x = {23, 26, 31, 35};
   vector<int> y = {3, 5, 7, 9, 11, 16};
   float result = median(x, y, 0, x.size() - 1);
   cout << result << endl;
   x = {1, 3};
   y = {7, 11, 18, 19, 21, 25, 26, 30, 35};
   result = median(x, y, 0, x.size() - 1);
   cout << result << endl;
} 
