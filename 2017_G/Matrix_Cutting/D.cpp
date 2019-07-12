/*************************************************************************
    > File Name: D.cpp
    > Author: wmg_1007
    > Mail: wmg_1007@163.com
    > Created Time: 2017年10月22日 星期日 12时38分50秒
 ************************************************************************/
#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <vector>
using namespace std;

long long arr[45][45];
long long dp[41][41][41][41];
long long MIN[41][41][41][41];
int x1, x2, y1, y2;
int t, n, m;

long long dfs(int x1, int x2, int y1, int y2)
{
	if (dp[x1][y1][x2][y2] != 0) 
        return dp[x1][y1][x2][y2];
	if (x1 == x2 && y1 == y2) 
        return dp[x1][y1][x2][y2] = 0;
	for (int t = x1; t < x2; t++) {
		dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dfs(x1,t,y1,y2) + dfs(t+1,x2,y1,y2) + MIN[x1][y1][x2][y2]);
	}
	for (int t=y1;t<y2;t++) {
		dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dfs(x1,x2,y1,t) + dfs(x1,x2,t+1,y2) + MIN[x1][y1][x2][y2]);
	}
	return dp[x1][y1][x2][y2];
}
int main()
{
	int T, caseT = 0;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> arr[i][j];
		memset(MIN, -1 , sizeof(MIN));
		for (int x1= 1; x1 <= n; x1++)
		for (int y1= 1; y1 <= m; y1++)
		for (int x2 = x1; x2 <= n; x2++)
		for (int y2 = y1; y2 <= m; y2++) {
			if (x2 != x1) MIN[x1][y1][x2][y2] = MIN[x1][y1][x2-1][y2];
			else MIN[x1][y1][x2][y2] = 99999999;
			for (int t = y1; t <= y2; t++)
				MIN[x1][y1][x2][y2] = min(MIN[x1][y1][x2][y2], arr[x2][t]);
		}
		dfs(1, n, 1, m);
		printf("Case #%d: ", ++caseT);
		cout << dp[1][1][n][m] << endl;
	}
}

