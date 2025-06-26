#include <iostream>
using namespace std;

int getLuckyNumber(long long num) {
    int minDigit = 9;
    int maxDigit = 0;
    
    while (num > 0) {
        int digit = num % 10;
        minDigit = min(minDigit, digit);
        maxDigit = max(maxDigit, digit);
        num /= 10;
    }
    return maxDigit - minDigit;
}

long long findLuckyNumber(long long l, long long r) {
    long long luckiestNum = l;
    int maxLuckiness = getLuckyNumber(l);
    
    for (long long i = l; i <= r; i++) {
        int currentLuckiness = getLuckyNumber(i);
        if (currentLuckiness > maxLuckiness) {
            maxLuckiness = currentLuckiness;
            luckiestNum = i;
        }
        
        if (maxLuckiness == 9) {
            break;
        }
    }
    
    return luckiestNum;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long l, r;
        cin >> l >> r;
        cout << findLuckyNumber(l, r) << endl;
    }
    return 0;
}