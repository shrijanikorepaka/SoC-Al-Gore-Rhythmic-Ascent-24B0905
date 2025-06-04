#include<iostream>
#include<string>
using namespace std;

int main() {
    string dna;
    cin >> dna;

    int max_len = 1;
    int curr_len = 1;

    for (int i = 1; i < dna.length(); ++i) {
        if (dna[i] == dna[i - 1]) {
            curr_len++;

            if (curr_len > max_len) {
                max_len = curr_len;
            }
        }
        else {
            curr_len = 1; 
        }
    } 

    cout << max_len << "\n";
    return 0;
}