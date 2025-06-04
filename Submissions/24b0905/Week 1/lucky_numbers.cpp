#include <iostream>
#include <string>
using namespace std;

int getLuckiness(int x) {
    int min_d = 9, max_d = 0;
    while (x) {
        int d = x % 10;
        min_d = min(min_d, d);
        max_d = max(max_d, d);
        x /= 10;
    }
    return max_d - min_d;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int best_num = l, best_luck = -1;

        for (int i = l; i <= r; ++i) {
            int luck = getLuckiness(i);
            if (luck > best_luck) {
                best_luck = luck;
                best_num = i;
            }
            if (best_luck == 9) break; // early exit
        }

        cout << best_num << endl;
    }
    return 0;
}
