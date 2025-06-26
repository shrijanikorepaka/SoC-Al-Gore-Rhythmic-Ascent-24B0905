#include <bits/stdc++.h>
using namespace std;

int solve(int N, int* arr)
{
    int XOR = 0;
    for (int i = 0; i < N - 1; i++) {
        XOR ^= arr[i];
        XOR ^= (i + 1);
    }
    XOR ^= N;
    return XOR;
}

int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    cout << solve(N, arr) << endl;
    return 0;
}