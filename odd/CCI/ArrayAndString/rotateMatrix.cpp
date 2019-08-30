#include <iostream>
#include <vector>

using namespace std;

bool rotateMatrix(vector<vector<int> >& matrix)
{
   if (matrix.size() != matrix[0].size())
      return false;

   int n = matrix.size();
   for (int layer = 0; layer < n / 2; layer ++)
   {
      int first = layer;
      int last = n - 1 - layer;
      for (int i = first; i < last; i ++)
      {
         int offset = i - first;
         int temp = matrix[first][i];
         matrix[first][i] = matrix[last - offset][first];
         matrix[last - offset][first] = matrix[last][last - offset];
         matrix[last][last - offset] = matrix[i][last];
         matrix[i][last] = temp;
      }
   }
   return true;
}

int main()
{
   vector<vector<int> > matrix = {
      {1,  2,  3,  10, 17},
      {4,  5,  6,  11, 18},
      {7,  8,  9,  12, 19},
      {13, 14, 15, 16, 20},
      {21, 22, 23, 24, 25}
   };

   for (int i = 0; i < matrix.size(); i ++)
   {
      for (int j = 0; j < matrix[i].size(); j ++)
         cout << matrix[i][j] << " ";
      cout << endl;
   }

   cout << endl;

   rotateMatrix(matrix);

   for (int i = 0; i < matrix.size(); i ++)
   {
      for (int j = 0; j < matrix[i].size(); j ++)
         cout << matrix[i][j] << " ";
      cout << endl;
   }
}
