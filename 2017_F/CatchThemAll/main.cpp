#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

double prob[205][105];
double dst[105][105];
double dp[205][105];
int n, m, p;

double solve()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) dst[i][j] = 10000000;
	for (int i = 0;i < n;i++) dst[i][i] = 0;
	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		dst[a][b] = min(dst[a][b], (double)c);
		dst[b][a] = min(dst[b][a], (double)c);
	}
	for (int k = 0;k < n;k++) for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)
		dst[i][j] = min(dst[i][j], dst[i][k]+dst[k][j]);
	for (int i = 0;i < n;i++) prob[0][i] = 0;
	prob[0][0] = 1;
	for (int j = 1;j <= p;j++)
	{
		for (int i = 0;i < n;i++) dp[j][i] = prob[j][i] = 0;
		for (int i = 0;i < n;i++) for (int k = 0;k < n;k++) if (k != i)
		{
			dp[j][i] += (dp[j-1][k]+dst[k][i])*prob[j-1][k];
			prob[j][i] += prob[j-1][k];
		}
		for (int i = 0;i < n;i++) if (prob[j][i] > 1e-15)
		{
			dp[j][i] /= prob[j][i];
			prob[j][i] /= (n-1);
		}
	}
	double ans = 0;
	for (int i = 0;i < n;i++)
		ans += dp[p][i]*prob[p][i];
	return ans;
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d: %.8lf\n", _, solve());

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}
