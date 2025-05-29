#include<iostream>
#include<math.h>

using namespace std;

long long fast_recursive(long long base, long long exp){
    if(exp == 0) return 1;
    if(exp & 1){
        return fast_recursive(base, exp-1)*base;
    }else{
        long long a = fast_recursive(base, exp>>1);
        return a * a;
    }
}

int main(){
    long long a, n, r = 1;
    cin >> a >> n;

    cout << fast_recursive(a, n) << endl;

    while(n > 0){
        if(n & 1){ //n % 2
            r *= a;
        }
        a *= a;
        n >>= 1; //n /= 2
    }

    cout << r << endl;
}
