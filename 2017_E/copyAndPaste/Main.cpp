#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 300 + 10;

int N;
char S[MAXN];
int dp[MAXN];
int LCP[MAXN][MAXN];

void Work()
{
	scanf("%s", S);
	N = strlen(S);
	// naive LCP
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
		{
			int tmp = 0;
			while (i + tmp < N && j + tmp < N && S[i + tmp] == S[j + tmp])
				tmp ++;
			LCP[i][j] = tmp;
		}

	memset(dp, 1, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < N; i ++)
	{
		for (int j = i + 1; j < N; j ++)
			dp[j] = min(dp[j], dp[i] + j - i);
		for (int l = 0; l <= i; l ++)
			for (int r = l; r <= i; r ++)
			{
				// copy [l, r]
				int len = r - l + 1;
				int visited = 0, last = i;
				for (int j = i + 1; j < N; j ++)
				{
					int head = j - len + 1;
					if (LCP[head][l] >= len && head > last)
					{
						visited ++;
						last = j;
					}
					dp[j] = min(dp[j], dp[i] + 1 + j - i - (len - 1) * visited);
				}
			}
	}
	printf("%d\n", dp[N - 1]);
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
	{
		printf("Case #%d: ", Case);
		fprintf(stderr, "Case #%d: \n", Case);
		Work();
		fflush(stdout);
	}
	return 0;
}
