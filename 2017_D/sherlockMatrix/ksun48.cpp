#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL x[110000];
LL y[110000];
LL r[110000];
LL s[110000];
LL a[110000];
LL b[110000];

LL N, K, A1, B1, C, D, E1, E2, F;

LL sum[2][110000]; // prefix sums of a, b

vector<LL> sums;
vector<LL> top5; // 500000 lowest numbers

void findless(LL k, int NEED){ // find top 500000 and put into top5
	top5.clear();
	multiset<LL> sofar;
	for(int i = sums.size()-1; i >= 0; i--){
		for(multiset<LL>::iterator it = sofar.begin(); it != sofar.end(); it++){
			if(*it - sums[i] > k) break;
			top5.push_back(*it-sums[i]);
			if(top5.size() > NEED){
				return;
			}
		}	
		sofar.insert(sums[i]);	
	}
}

void solve(int NEED){
	//find lowest 500000;
	LL s = -1e15; // <= 500000
	LL e = 1e15; // >= 500000
	while(s+1 < e){
		LL m = (s+e)/2;
		findless(m, NEED);
		if(top5.size() <= NEED){
			s = m;
		} else {
			e = m;
		}
	}
	findless(s, NEED);
	LL f = sums.size() * (sums.size()-1) / 2;
	while(top5.size() < f && top5.size() < NEED){
		top5.push_back(s);
	}
	sort(top5.begin(), top5.end());
	/*for(int i = 0; i < top5.size(); i++){
		cout << top5[i] << " ";
	}
	cout << endl;*/
	return;
}

main() {
	FILE *fin = freopen("B-large.in", "r", stdin);
	FILE *fout = freopen("B-large.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		cin >> N >> K >> A1 >> B1 >> C >> D >> E1 >> E2 >> F;
		x[1] = A1;
		y[1] = B1;
		r[1] = s[1] = 0;
		for(int i = 2; i <= N; i++){
			x[i] = (C*x[i-1]+D*y[i-1]+E1) % F;
			y[i] = (D*x[i-1]+C*y[i-1]+E2) % F;
			r[i] = (C*r[i-1]+D*s[i-1]+E1) % 2;
			s[i] = (D*r[i-1]+C*s[i-1]+E2) % 2;
		}
		for(int i = 1; i <= N; i++){
			a[i] = x[i];
			if(r[i] % 2) a[i] = -a[i];
			b[i] = y[i];
			if(s[i] % 2) b[i] = -b[i];
		}
		sum[0][0] = sum[1][0] = 0;
		for(int i = 1; i <= N; i++){
			sum[0][i] = sum[0][i-1] + a[i];
			sum[1][i] = sum[1][i-1] + b[i];
		}
		LL total = N*(N+1)/2;
		vector<LL> newrow, newcol;

		if(total <= 400000){
			sums.clear();
			for(int i = 0; i <= N; i++){
				sums.push_back(sum[0][i]);
			}
			solve(400000);
			newrow = top5;

			sums.clear();
			for(int i = 0; i <= N; i++){
				sums.push_back(sum[1][i]);
			}
			solve(400000);
			newcol = top5;
		} else {
			sums.clear();
			for(int i = 0; i <= N; i++){
				sums.push_back(sum[0][i]);
			}
			solve(200000);
			newrow = top5;

			sums.clear();
			for(int i = 0; i <= N; i++){
				sums.push_back(sum[1][i]);
			}
			solve(200000);
			newcol = top5;

			sums.clear();
			for(int i = 0; i <= N; i++){
				sums.push_back(-sum[0][i]);
			}
			solve(200000);
			for(int i = 0; i < top5.size(); i++){
				newrow.push_back(-top5[i]);
			}

			sums.clear();
			for(int i = 0; i <= N; i++){
				sums.push_back(-sum[1][i]);
			}
			solve(200000);
			for(int i = 0; i < top5.size(); i++){
				newcol.push_back(-top5[i]);
			}


		}

		sort(newrow.begin(), newrow.end());
		sort(newcol.begin(), newcol.end());
		/*for(int i = 0; i < newrow.size(); i++){
			cout << newrow[i] << " ";
		}

		for(int i = 0; i < newcol.size(); i++){
			cout << newcol[i] << " ";
		}
		cout << endl;*/

		LL s = -5e17; 
		LL e = 5e17; // ans, need <= K-1 > than this
		while(s + 1 < e){
			LL m = (s+e)/2;
			LL cnt = 0;
			for(int i = 0; i < newrow.size(); i++){
				if(cnt > (K-1)) break;
				if(newrow[i] <= 0){
					for(int j = 0; j < newcol.size(); j++){
						if(cnt > (K-1)) break;
						if(newcol[j] * newrow[i] <= m) break;
						cnt++;
					}
				} else {
					for(int j = newcol.size() - 1; j >= 0; j--){
						if(cnt > (K-1)) break;
						if(newcol[j] * newrow[i] <= m) break;
						cnt++;
					}
				}
			}
			if(cnt <= K-1){
				e = m;
			} else {
				s = m;
			}
		}
		cout << e << endl;
	}
	exit(0);
}