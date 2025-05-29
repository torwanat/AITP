#include <bits/stdc++.h>

using namespace std;

int bmoore(string s, string searched, int shift[], int M, int N) {
    if(M > N) return -1;

    int i = M - 1;
    int j = M - 1;

    while(j > 0) {
        while(searched[j] != s[i]) {
            int x = shift[s[i]];

            if(M - j > x) {
                i += M - j;
            } else {
                i += x;
            }

            if(i > N) {
                return -1;
            }

            j = M-1;
        }
        j--;
        i--;
    }

    return i;
}

int main() {

    const bool debug = true;

    fstream file("tekst.txt");

    int M, N;

    string s;
    string searched = "Tadeusz";

    s = "Tadeusz";

    //#region shift table

    M = searched.length();

    int shift[128];

    for(int i = 0; i < 128; i++) {
        shift[i] = M;
    }

    for(int i = M-1; i >= 0; i--) {
        if(shift[searched[i]] < M) {
            continue;
        } else {
            shift[searched[i]] = M-1-i;
        }
    }

    //#endregion

    int line = 0;
    int founds = 0;

    if(file) {
        while(getline(file, s)) {
            line++;
            N = s.length();

            int foundPos = bmoore(s, searched, shift, M, N);
            if(foundPos >= 0) {
               cout << line << ": " << foundPos << endl;
               founds++;
            }
        }
    }

    cout << founds;

    file.close();

    return 0;
}
