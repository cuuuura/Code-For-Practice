#include <iostream>
#include <vector>
 
using namespace std;
 
const int MOD = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int l, r;
    cin >> l >> r;
 
    vector<int> dp(r + 1, 0);
    dp[1] = 1;
 
    for (int i = 1; i <= r; ++i) {
        if (dp[i] == 0) continue;
        for (int j = 2*i; j <= r; j += i) {
            dp[j] += dp[i];
        }
    }
 
    long long ans = 0;
    for (int x = l; x <= r; ++x) {
        ans += dp[x];
    }
 
    cout << ans % MOD << '\n';
    return 0;
}