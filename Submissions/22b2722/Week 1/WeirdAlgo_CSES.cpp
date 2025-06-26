#include <bits/stdc++.h>
using namespace std;

int main()
{
    ll N = 13;
    while (N != 1) {
        cout << N << " ";
        if (N & 1LL)
            N = N * 3 + 1;
        else
            N /= 2;
    }
    cout << 1;
}