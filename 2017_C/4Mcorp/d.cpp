#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

ll mn,mx,me,md;

bool test(ll s) {
	if(s == 2) {
		return (me == md && me*2 == mn+mx);
	}
	if(s&1) {
		ll sm = me*s;
		ll t = (s-3)/2;
		ll A = mn*(t+1) + md*(t+1) + mx;
		ll B = mn + md*(t+1) + mx*(t+1);
		return (A <= sm && sm <= B);
	} else {
		ll sm = me*s;
		ll t = (s-4)/2;
		ll A = mn*(t+1) + md*(t+2) + mx;
		ll B = mn + md*(t+2) + mx*(t+1);
		return (A <= sm && sm <= B);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> mn >> mx >> me >> md;
		cout << "Case #" << t << ": ";

		if(mn==mx) {
			if(mn==me && mn==md) cout << "1\n";
			else cout << "IMPOSSIBLE\n";
			continue;
		}
		else if(me*2 <= (mn+md)) cout << "IMPOSSIBLE\n";
		else if(me*2 >= (mx+md)) cout << "IMPOSSIBLE\n";
		else if(md < mn || md > mx) cout << "IMPOSSIBLE\n";
		else {
			int s = 2;
			while(!test(s)) ++s;
			cout << s << "\n";
		}
	}
}