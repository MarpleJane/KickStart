#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tp;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;
typedef pair<LL, pii> plpii;
typedef pair<LD, LD> pdd;
typedef pair<LD, int> pdi;
typedef pair<LD, LL> pdl;
typedef pair<int, LD> pid;
typedef pair<LL, LD> pld;
const int mod = 1e9 + 7;
const int hf = 999983;
const int N = 1e6;
int dp[105][105];
int v[105][105];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void solve(int tt){
	memset(dp, -1, sizeof(dp));
	int n, m, e, sr, sc, tr, tc;
	scanf("%d%d%d%d%d%d%d", &n, &m, &e, &sr, &sc, &tr, &tc);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d", &v[i][j]);
		}
	}
	queue<pii> q;
	dp[sr][sc] = e;
	q.push(pii(sr, sc));
	while(!q.empty()){
		int uy = q.front().first;
		int ux = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int vy = uy+dir[i][0];
			int vx = ux+dir[i][1];
			if(vy >= 1 && vy <= n && vx >= 1 && vx <= m && v[vy][vx] != -100000){
				if(dp[vy][vx] == -1 || dp[vy][vx] < dp[uy][ux] + v[vy][vx]){
					if(dp[uy][ux] + v[vy][vx] >= 0){
						dp[vy][vx] = dp[uy][ux] + v[vy][vx];
						q.push(pii(vy, vx));
					}
				}
			}
		}
	}
	printf("Case #%d: %d\n", tt, dp[tr][tc]);
}
int main(){
	int t;
	scanf("%d", &t);	
	for(int tt=1;tt<=t;tt++) solve(tt);
}