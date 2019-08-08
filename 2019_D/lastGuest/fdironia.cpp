#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++) {
        int n, g, m;
        scanf("%d %d %d", &n, &g, &m);
        int h[g], d[g];
        bool fc[2*n], fa[2*n];
        memset(fc, false, sizeof(fc));
        memset(fa, false, sizeof(fa));
        for (int i = 0; i < g; i++) {
            char c;
            scanf("%d %c", &h[i], &c);
            d[i] = c == 'C';
            if (d[i]) {
                h[i] = (h[i] - 1 + m) % n;
                fc[h[i]] = fc[h[i]+n] = true;
            } else {
                h[i] = ((h[i] - 1 - m) % n + n) % n;
                fa[h[i]] = fa[h[i]+n] = true;
            }
        }

        if (m >= n) {
            m = n - 1;
        }

        int vc[n];
        int j = n - 1;
        while (j < 2 * n && !fc[j]) {
            j++;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (fc[i]) {
                j = i;
            }
            vc[i] = j - i <= m ? j % n : -1;
        }

        int va[n];
        j = n;
        while (j >= 0 && !fa[j]) {
            j--;
        }
        for (int i = 0; i < n; i++) {
            if (fa[i+n]) {
                j = i + n;
            }
            va[i] = i + n - j <= m ? j % n : -1;
        }

        int v[n][2];
        memset(v, 0, sizeof(v));
        for (int i = 0; i < n; i++) {
            if (va[i] == -1) {
                if (vc[i] != -1) {
                    v[vc[i]][1]++;
                }
            } else {
                if (vc[i] == -1) {
                    v[va[i]][0]++;
                } else {
                    int dc = (vc[i] - i + n) % n;
                    int da = (i - va[i] + n) % n;
                    if (da <= dc) {
                        v[va[i]][0]++;
                    }
                    if (da >= dc) {
                        v[vc[i]][1]++;
                    }
                }
            }
        }

        printf("Case #%d:", cs);
        for (int i = 0; i < g; i++) {
            printf(" %d", v[h[i]][d[i]]);
        }
        printf("\n");
    }

    return 0;
}
