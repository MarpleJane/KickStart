#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int V;
int graph[11][11];
int product[11];

void floyd()
{
   for (int k = 1; k <= V; k ++)
   {
      for (int i = 1; i <= V; i ++)
      {
         for (int j = 1; j <= V; j ++)
         {
            if (graph[i][j] > graph[i][k] + graph[k][j])
               graph[i][j] = graph[i][k] + graph[k][j];
         }
      }
   }
}

void bfs()
{
}

int main()
{}
