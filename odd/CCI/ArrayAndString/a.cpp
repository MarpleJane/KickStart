#include <iostream>
#include <vector>

using namespace std;

#define MAX_V 100005

void dfs(int v, const vector<vector<int> >& G, vector<int>& visited, int& node)
{
   if (visited[v])
      return;
   visited[v] = 1;
   node ++;
   for (int i = 0; i < G[v].size(); i ++)
   {
      dfs(G[v][i], G, visited, node);
   }
}

int main()
{
   int T, N, M;
   cin >> T;
   for (int t = 1; t <= T; t ++)
   {
      cin >> N >> M;
      vector<vector<int> > G(N + 1, vector<int>());
      for (int i = 1; i <= M; i ++)
      {
         int c, d;
         cin >> c >> d;
         G[c].push_back(d);
         G[d].push_back(c);
      }
      int cnt = 0, linkSum = 0;
      vector<int> visited(N + 1);
      for (int i = 1; i <= N; i ++)
      {
         if (visited[i])
            continue;
         int node = 0;
         dfs(i, G, visited, node);
         cnt ++;
         if (node != 0)
            linkSum += node - 1;
      }
      int result = linkSum + 2 * (cnt - 1);
      cout << "Case #" << t << ": " << result << endl;
   }
}
