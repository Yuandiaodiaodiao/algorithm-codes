#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
using ull=unsigned long long;
ull valuek[30][105][105];
ull dp[30][105][105];

int main() {
    int n, m;
    while (cin >> n >> m) {
        memset(valuek, 0, sizeof(valuek));
        memset(dp, 0, sizeof(dp));
        for (int a = 1; a <= m; ++a)
            for (int b = 1; b <= m; ++b)
                cin >> valuek[0][a][b];
        for (int a = 1; a <= 20; ++a)
            for (int b = 1; b <= m; ++b)
                for (int c = 1; c <= m; ++c)
                    for (int d = 1; d <= m; ++d)
                        valuek[a][b][c] = max(valuek[a][b][c],
                                              valuek[a - 1][b][d] + valuek[a - 1][d][c]);
        n--;
        for (int a = 20; a >= 0; --a) {
            for (int b = 1; b <= m; ++b)
                for (int c = 1; c <= m; ++c)
                    for (int d = 1; d <= m; ++d)
                        if (n > (1 << a)) {
                            dp[a][b][c] = max(dp[a][b][c],
                                              dp[a + 1][b][d] + valuek[a][d][c]);
                        } else {
                            dp[a][b][c] = dp[a + 1][b][c];
                        }
            if (n > (1 << a)) { n -= (1 << a); }
        }
        for (int b = 1; b <= m; ++b)
            for (int c = 1; c <= m; ++c)
                for (int d = 1; d <= m; ++d)
                    dp[25][b][c] = max(dp[25][b][c],
                                       dp[0][b][d] + valuek[0][d][c]);
        ull ans = 0;
        for (int a = 1; a <= m; ++a)
            for (int b = 1; b <= m; ++b)
                ans = max(ans, dp[25][a][b]);
        cout << ans << endl;
    }
    return 0;
}