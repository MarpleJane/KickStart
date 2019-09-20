#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Point
{
   int x;
   int y;
   Point(int x, int y)
   {
      this->x = x;
      this->y = y;
   }

   bool operator <(const Point& p) const
   {
      return (x < p.x) || ((!(x < p.x)) && (y < p.y));
   }

   bool operator ==(const Point& p) const
   {
      return (x == p.x) && (y == p.y);
   }
};

bool getPath(vector<vector<bool> >& grid, vector<Point>& path, int row, int col, set<Point>& failedPoints)
{
   if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || !grid[row][col])
      return false;

   Point p(row, col);
   if (failedPoints.count(p))
      return false;

   bool isAtOrigin = (row == 0) && (col == 0);

   if (isAtOrigin || getPath(grid, path, row - 1, col, failedPoints) || getPath(grid, path, row, col - 1, failedPoints))
   {
      path.push_back(Point(row, col));
      return true;
   }

   failedPoints.insert(p);
   return false;
}

vector<Point> getPath(vector<vector<bool> >& grid)
{
   vector<Point> path;
   set<Point> failedPoints;
   getPath(grid, path, grid.size() - 1, grid[0].size() - 1, failedPoints);
   return path;
}

int main()
{
   vector<vector<bool> > grid = {
      {1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0},
      {1, 0, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1}
   };

   vector<Point> path = getPath(grid);
   if (path.size() == 0)
      cout << "IMPOSSIBLE" << endl;
   else
      cout << "POSSIBLE" << endl;
}
