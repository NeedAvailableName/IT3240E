#include<bits/stdc++.h>
using namespace std;
int N, T, D;
int S[1001][1001];
int main() {
	cin >> N >> T >> D;
	int a[N];
	for(int i = 1; i <= N; i++) cin >> a[i];
	int t[N];
	for(int i = 1; i <= N; i++) cin >> t[i];
	int ans = 0;
	for(int k = 0; k <= T; k++) {
		if(k == t[1]) S[1][k] = a[1];
		else S[1][k] = 0;
	}
	ans = S[1][t[1]];
	for(int i = 2; i <= N; i++) {
		for(int k = 0; k <= T; k++) {
			if(k == t[i]) S[i][k] = a[i];
			else S[i][k] = 0;
			for(int d = 1; d <= D; d++) {
				int j = i-d;
				if(j >= 1 && k - t[i] >= 0) S[i][k] = max(S[i][k], S[j][k-t[i]] + a[i]);
			}
			ans = max(ans, S[i][k]);
		}
	}
	cout << ans;
	return 0;
}