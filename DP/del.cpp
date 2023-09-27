#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1e8 + 7;

ll dp[100001][101];

ll countWays(int arr[], int n, int m, int i, int prev) {
    if (i == n) {
        return 1;
    }

    if (dp[i][prev] != -1) {
        return dp[i][prev];
    }

    ll ways = 0;

    if (arr[i] == 0) {
        for (int j = 1; j <= m; j++) {
            if (abs(j - prev) <= 1) {
                ways += countWays(arr, n, m, i + 1, j);
                ways %= MOD;
            }
        }
    } else {
        if (abs(arr[i] - prev) <= 1) {
            ways = countWays(arr, n, m, i + 1, arr[i]);
        }
    }

    dp[i][prev] = ways;
    return ways;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += countWays(arr, n, m, 1, i);
        ans %= MOD;
    }
    
    cout << ans;

    return 0;
}
