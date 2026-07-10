#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
 
    sort(a.begin(), a.end());
 
    long long ans = 0;
    
    for (int i = 0; i < n - 2; ++i) {
        int p = i + 2; 
        for (int j = i + 1; j < n - 1; ++j) {
            if (p < j + 1) 
                p = j + 1;
            
            while (p < n && a[p] < a[i] + a[j]) {
                ++p;
            }
            ans += p - (j + 1);
        }
    }
 
    cout << ans << endl;
    return 0;
}