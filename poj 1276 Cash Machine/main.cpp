#include<iostream>
using namespace std;
int nk[15];
int dk[15];
int dp[100005];
int cnt[100006];
int main() {
	int cash, n;
	while (cin >> cash >> n) {
		for (int a = 1; a <= n; ++a) {
			cin >> nk[a] >> dk[a];
		}
		fill_n(dp, cash + 2, 0);
		for (int i = 1; i <= n; ++i) {
			fill_n(cnt, cash + 5, 0);
			for (int j = dk[i]; j <=cash ; ++j) {
				if (dp[j] < dp[j - dk[i]] + dk[i] && cnt[j - dk[i]] < nk[i]) {
					dp[j] = dp[j - dk[i]] + dk[i];
					cnt[j] = cnt[j - dk[i]] + 1;
				}
			}
		}
		cout << dp[cash] << endl;


	}



	return 0;
}
