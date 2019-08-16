#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int graph[105][105];
int energy[105][105];
int dir[4][2] = {
   {-1, 0}, // up
   {0, 1}, // right
   {1, 0}, // down
   {0, -1} // left
};
const int OBSTACLE = -100000;

int main()
{
   int T, N, M, E, Sr, Sc, Tr, Tc;
   cin >> T;
   for (int t = 1; t <= T; t ++)
   {
      cin >> N >> M >> E >> Sr >> Sc >> Tr >> Tc;
      memset(graph, 0, sizeof(graph));
      memset(energy, -1, sizeof(energy));
      for (int i = 1; i <= N; i ++)
         for (int j = 1; j <= M; j ++)
            cin >> graph[i][j];

      queue<pair<int, int> > q;
      energy[Sr][Sc] = E;
      q.push(pair<int, int>(Sr, Sc));
      while (!q.empty())
      {
         int ur = q.front().first;
         int uc = q.front().second;
         q.pop();
         for (int i = 0; i < 4; i ++)
         {
            int vr = ur + dir[i][0];
            int vc = uc + dir[i][1];
            if (vr >= 1 && vc >= 1 && vr <= N && vc <= M && graph[vr][vc] != OBSTACLE)
            {
               if (energy[vr][vc] == -1 || energy[vr][vc] < energy[ur][uc] + graph[vr][vc])
               {
                  if (energy[ur][uc] + graph[vr][vc] >= 0)
                  {
                     energy[vr][vc] = energy[ur][uc] + graph[vr][vc];
                     q.push(pair<int, int>(vr, vc));
                  }
               }
            }
         }
      }
      cout << "Case #" << t << ": " << energy[Tr][Tc] << endl;
   }

   return 0;
}
