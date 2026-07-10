#include <iostream>
using namespace std;
 
const long long MOD = 1000000007LL;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    cin >> N;
 
    long long fact = 1;
    for (int i = 2; i <= N - 1; ++i) {
        fact = (fact * i) % MOD;
    }
 
    long long inv2 = (MOD + 1) / 2;
    long long ans = (fact * inv2) % MOD;
 
    cout << ans << '\n';
    return 0;
}