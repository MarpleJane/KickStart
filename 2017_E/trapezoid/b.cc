#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll C(ll n, ll m) {
  ll x = 1, y = 1;
  for (ll i = n, j = m; j > 0; i--, j--) {
    x *= i;
    y *= j;
  }
  return x / y;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int n;
    cin >> n;
    map<ll, ll> mp;
    vector<ll> a;
    for (int i = 0, t; i < n; i++) {
      cin >> t;
      mp[t]++;
      a.push_back(t);
    }
    ll ans = 0;
    for (auto e : mp) {
      if (e.second >= 2) {
        ll cc = C(e.second, 2);
        vector<pair<ll, ll>> b;
        for (auto x : mp) {
          if (x.first != e.first) {
            b.push_back(x);
          }
        }
        ll sum = 0;
        sort(b.begin(), b.end());
        for (int i = 0, j = 0; i < (int)b.size(); i++) {
          sum -= b[i].second;
          while (j < (int)b.size() && b[j].first < b[i].first + (ll)e.first * 2) sum += b[j++].second;
          ans += sum * cc * b[i].second;
        }
      }
      if (e.second >= 3) {
        ll cc = C(e.second, 3);
        for (auto x : a) {
          if (x != e.first && x < 3 * e.first) {
            ans += cc;
          }
        }
      }
    }
    printf("Case #%d: %lld\n", cas, ans);
  }
  return 0;
}
