#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

int mural(int num, vector<int>& scores)
{
   int painted = (num + 1) / 2;
   int result = accumulate(scores.begin(), scores.begin()+painted, 0);
   int sum = result;
   for (int i = painted; i < scores.size(); i ++)
   {
      sum = sum + scores[i] - scores[i-painted];
      result = max(result, sum);
   }
   return result;
}

int main()
{
   int T, temp;
   int N;
   string line;
   stringstream ss;
   cin >> T;
   for (int i = 1; i <= T; i ++)
   {
      cin >> N >> line;
      vector<int> scores;
      for (int j = 0; j < line.size(); j ++)
      {
         ss << line[j];
         ss >> temp;
         scores.push_back(temp);
         ss.clear();
      }
      int result = mural(N, scores);
      cout << "Case #" << i << ": " << result << endl;
   }
   return 0;
}
