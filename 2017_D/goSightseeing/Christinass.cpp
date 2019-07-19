#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
using namespace std;

#define N 2010

int n;
long long Ts, Tf;
long long S[N], F[N], D[N];
long long dp[N][N];

long long getTime(long long t, long long s, long long f) {
	long long d = (t - s);
	long long x = 0;
	if (d > 0) {
		if (d % f == 0) x = d / f;
		else x = d / f + 1;
	}
	return s + x * f;
}

int main() {
	int ncas;
	scanf("%d", &ncas);
	for (int tcas = 1; tcas <= ncas; tcas++) {
		scanf("%d %lld %lld", &n, &Ts, &Tf);
		for (int i = 1; i < n; i++) {
			scanf("%lld %lld %lld", &S[i], &F[i], &D[i]);
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = INT_MAX;
			}
		}
		dp[0][0] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (dp[i - 1][j] < INT_MAX) {
					dp[i][j] = getTime(dp[i - 1][j], S[i], F[i]) + D[i];
					// printf("%d %d %lld\n", i, j, dp[i][j]);
				}

				if (j && dp[i - 1][j - 1] < INT_MAX) {
					dp[i][j] = min(dp[i][j], getTime(dp[i - 1][j - 1] + Ts, S[i], F[i]) + D[i]);
					// printf("%d %d %lld\n", i, j, dp[i][j]);
				}
				// printf("%d %d %lld\n", i, j, dp[i][j]);
			}
		}
		int max_ans = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (dp[n - 1][i] <= Tf) {
				max_ans = i;
				break;
			}
		}
		printf("Case #%d: ", tcas);
		if (max_ans < 0) puts("IMPOSSIBLE");
		else printf("%d\n", max_ans);
	}
	return 0;
}
