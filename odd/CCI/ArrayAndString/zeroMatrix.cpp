#include <iostream>
#include <vector>
#include <set>

using namespace std;

void zeroRow(int i, vector<vector<int> >& matrix)
{
   for (int j = 0; j < matrix[i].size(); j ++)
      matrix[i][j] = 0;
}

void zeroColumn(int i, vector<vector<int> >& matrix)
{
   for (int j = 0; j < matrix.size(); j ++)
      matrix[j][i] = 0;
}

void zeroMatrix(vector<vector<int> >& matrix)
{
   set<int> row, column;
   for (int i = 0; i < matrix.size(); i ++)
   {
      for (int j = 0; j < matrix[i].size(); j ++)
      {
         if (matrix[i][j] == 0)
         {
            row.insert(i);
            column.insert(j);
         }
      }
   }

   set<int>::iterator it;

   for (it = row.begin(); it != row.end(); it ++)
      zeroRow(*it, matrix);

   for (it = column.begin(); it != column.end(); it ++)
      zeroColumn(*it, matrix);
}

int main()
{
   vector<vector<int> > matrix = {
      {1, 2, 0},
      {3, 0, 4},
      {5, 6, 7}
   };

   zeroMatrix(matrix);

   for (int i = 0; i < matrix.size(); i ++)
   {
      for (int j = 0; j < matrix[i].size(); j ++)
         cout << matrix[i][j] << " ";
      cout << endl;
   }
}
