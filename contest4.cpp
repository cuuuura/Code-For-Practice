#include <bits/stdc++.h>
using namespace std;
using LL = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
 
    vector<int> pg(n, -1), ng(n, n);
    vector<int> st;
 
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] <= a[i]) 
            st.pop_back();
        if (!st.empty()) 
            pg[i] = st.back();
        st.push_back(i);
    }
 
    st.clear();
 
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] < a[i]) 
            st.pop_back();
        if (!st.empty()) 
            ng[i] = st.back();
        st.push_back(i);
    }
 
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        LL l = i - pg[i];
        LL r = ng[i] - i;
        ans += a[i] * l * r;
    }
 
    cout << ans << '\n';
    return 0;
}