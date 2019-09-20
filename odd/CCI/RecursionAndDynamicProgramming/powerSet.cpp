#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<vector<int> > getSubSets(vector<int> mySet, int step)
{
   vector<vector<int> > allSubSets;
   if (mySet.size() == step)
   {
      allSubSets.push_back(vector<int>());
   }
   else
   {
      allSubSets = getSubSets(mySet, step + 1);
      int item = mySet[step];
      vector<vector<int> > moreSets;
      for (int i = 0; i < allSubSets.size(); i ++)
      {
         vector<int> newsubset(allSubSets[i]);
         newsubset.push_back(item);
         moreSets.push_back(newsubset);
      }
      allSubSets.insert(allSubSets.end(), moreSets.begin(), moreSets.end());
   }
   return allSubSets;
}

// Combinatorics
void getSubSets2(vector<int> mySet)
{
   int setSize = mySet.size();
   int total = pow(2, setSize);
   for (int i = 0; i < total; i ++)
   {
      for (int j = 0; j < setSize; j ++)
      {
         if (i & (1 << j))
            cout << mySet[j] << " ";
      }
      cout << endl;
   }
}

int main()
{
  // vector<int> mySet = {1, 2, 3};
  // vector<vector<int> > result = getSubSets(mySet, 0);
  // for (int i = 0; i < result.size(); i ++)
  // {
  //    for (int j = 0; j < result[i].size(); j ++)
  //       cout << result[i][j];
  //    cout << endl;
  // }

   vector<int> mySet = {3, 4, 5};
   getSubSets2(mySet);
}
