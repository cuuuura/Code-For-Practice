#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    int shelfs;
    std::cin >> shelfs;
 
    for (int _ = 0; _ < shelfs; _++) {
        int n;
        int count = 0;
        std::cin >> n;
 
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
 
        int temp = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (a[j] > a[j+1]) {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    count++;
                }
            }
        }
 
        std::cout << count << '\n';
    }
    return 0;
}