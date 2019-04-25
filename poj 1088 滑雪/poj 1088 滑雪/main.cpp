#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int g[105][105];
int dp[105][105];
int solve(int i, int j) {
	if (dp[i][j])return dp[i][j];
	int nowh = g[i][j];
	int ans = 1;
	for (int a = -1; a <= 1; ++a) {
		for (int b = -1; b <= 1; ++b) {
			if (abs(a) + abs(b) != 1)continue;
			if (g[i + a][j + b] >= 0 && g[i + a][j + b] < nowh)
				ans= max(ans, solve(i + a, j + b) + 1);
		}
	}
	dp[i][j] = max(ans, dp[i][j]);
	return dp[i][j];


}
int main() {
	int n, m;
	cin >> n >> m;
	for (int a = 0; a <= n + 1; ++a) {
		for (int b = 0; b <= m + 1; ++b) {
			if (a == 0 || b == 0 || a == n + 1 || b == m + 1) {
				g[a][b] = -1;
			}
			else
				cin >> g[a][b];
		}
	}
	int maxn = 0;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			maxn = max(solve(a, b), maxn);
		}
	}
	cout << maxn << endl;


	return 0;
}