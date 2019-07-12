/*************************************************************************
    > File Name: B.cpp
    > Author: wmg_1007
    > Mail: wmg_1007@163.com
    > Created Time: 2017年10月22日 星期日 12时38分50秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 105;

int n;
int r[maxn], b[maxn];
bool vis[maxn];
LL sum, res;

void dfs(int deep) {
    if (deep >= n - 1) {
        res = min(res, sum);
        cout << "result: " << res << endl;
        return ;
    }
    for (int i = 0; i < n; i++) {
       cout << "Deep: " << deep << ", " << "i: " << i << endl;
        if (!vis[i]) {
            vis[i] = true;
            int minn = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (!vis[j]) {
                    minn = min(minn, r[i] ^ b[j]);
                    minn = min(minn, r[j] ^ b[i]);
                }
            }
            cout << "Minn: " << minn << endl;
            sum += minn;
            dfs(deep + 1);
            sum -= minn;
            vis[i] = false;
        }
    }
}

int main()
{
    int T, caseT = 0;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> r[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sum = 0;
        res = INT_MAX;
        dfs(0);
        printf("Case #%d: %lld\n", ++caseT, res);
        break;
    }
    return 0;
}

