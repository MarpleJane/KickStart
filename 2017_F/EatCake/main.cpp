#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

int cakedp[MAXN];

int main() {
	cakedp[0] = 0;
	for (int i = 1; i < MAXN; i++) {
		cakedp[i] = cakedp[i - 1] + 1;
		for (int j = 2; j <= i / j; j++) {
			cakedp[i] = min(cakedp[i], cakedp[i - j * j] + 1);
		}
	}
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int N;
		cin >> N;
		cout << "Case #" << cas << ": " << cakedp[N] << endl;
	}
}