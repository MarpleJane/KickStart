#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define MAX_V 51
using namespace std;

struct Edge {
    int to = -1;
    int length = -1;
};

void Update(int l, int x, int y, Edge edges[]) {
    if (edges[x].to == -1) {
        edges[x].to = y;
        edges[x].length = l;
    } else {
        if (edges[x].length > l) {
            edges[x].to = y;
            edges[x].length = l;
        }
    }
}

void dfs(int v, const vector<vector<int>>& G, vector<int>& visited) {
    if (visited[v]) {
        return;
    }
    visited[v] = 1;
    for(int i = 0; i < G[v].size(); i++) {
        dfs(G[v][i], G, visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tcase;
    cin >> tcase;
    for(int tc = 1; tc <= tcase; tc++) {
        int V, E;
        cin >> V >> E;
        Edge edges[MAX_V];
        unordered_set<int> zeros;
        for(int i = 0; i < E; i++) {
            int x, y, l;
            cin >> x >> y >> l;
            Update(l, x, y, edges);
            Update(l, y, x, edges);
            if (l == 0) {
                zeros.insert(x);
                zeros.insert(y);
            }
        }
        vector<vector<int>> G(MAX_V, vector<int>());
        for(int i = 1; i <= V; i++) {
            G[i].push_back(edges[i].to);
            G[edges[i].to].push_back(i);
        }
        int count = 0;
        vector<int> visited(V + 1);
        for(int i = 1; i <= V; i++) {
            if(!visited[i]) {
                dfs(i, G, visited);
                count++;
            }
        }
        // cout << count << endl;
        for(int i = 1; i <= V; i++) {
            if (zeros.find(edges[i].to) != zeros.end()) {
                // cout << edges[i].to << endl;
                count++;
            }
        }
        count -= zeros.size();
        cout << "Case #" << tc << ": " << (1L << count) << endl;
    }
}