#include <bits/stdc++.h>

using namespace std;

int main() {

    string password;

    int n;

    cin >> n >> password;

    int d[n];

    for (int i = 0; i < n; i++) {
        
        if (i < n -4 ) {
            if (password[i] == 'a') {
                if (password[i + 1] == 'b') {
                    if (password[i + 2] == 'a') {
                        if (password[i + 3] == 'a') {
                            d[n] = 1;
                        }
                    }
                }
            }

            if (password[i] == 'a') {
                if (password[i + 1] == 'b') {
                    if (password[i + 2] == 'a') {
                        if (password[i + 3] == 'b') {
                            d[n] = 0;
                        }
                    }
                }
            }
        }
        


    }








    return 0;
}