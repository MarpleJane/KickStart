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
LL res;

int fa[maxn];
struct len_node {
    int l, r, a;
}len[maxn * maxn];

bool operator < (const len_node &a, const len_node &b)
{
    return a.a < b.a;
}

int getfa(int p)
{
    if (fa[p] == -1)
        return p;
    fa[p] = getfa(fa[p]);
    return fa[p];
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
        res = 0;
        int tot = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                len[tot++] = (len_node){i, j, min(r[i] ^ b[j], r[j] ^ b[i])};
            }
        sort(len, len + tot);
        memset(fa, -1, sizeof(fa));
        for (int i = 0; i < tot; i++) {
            int t1 = getfa(len[i].l);
            int t2 = getfa(len[i].r);
            if (t1 != t2) {
                fa[t1] = t2;
                res += (LL)len[i].a;
            }
        }
        printf("Case #%d: %lld\n", ++caseT, res);
    }
    return 0;
}

