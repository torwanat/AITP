#include<iostream>
#include<math.h>
#include<vector>
#include<cstdlib>
#include <ctime>

using namespace std;

long long fast_power(long long base, long long exp){
    if(exp == 0) return 1;
    if(exp % 2 == 1){
        return fast_power(base, exp - 1) * base;
    } else {
        double a = fast_power(base, exp >> 1);
        return a * a;
    }
}

vector<int> sito(int n)
{
    vector<int> tab, result;
    for(int i=2; i<=n; i++){
		tab.push_back(0);
    }
	for (int i=2; i*i<=n; i++){
        if(!tab[i]){
            for (int j = i*i ; j<=n; j+=i){
                tab[j] = 1;
            }
        }
    }
    for(int i=2;i<=n;i++){
		if(!tab[i]){
			result.push_back(i);
		}
	}
    return result;
}

int main(){
    long long p, q, n, fn, e, d, rand1, rand2, prmLength;
    char t, s, r;
    prmLength = 1000;
    vector<int> primes;
    srand((unsigned) time(NULL));
    primes = sito(prmLength);
    rand1 = rand() % primes.size();
    rand2 = rand() % primes.size();
    if(rand1 == rand2){
        rand2++;
    }
    p = primes[rand1];
    q = primes[rand2];
    //nie mam pojecia co sie dzieje od tego miejsca
    e = 7;
    n = p * q;
    fn = (p - 1) * (q - 1);
    for(int i = 1; true; i++){
        if((i * fn + 1) % e == 0){
            d = (i * fn + 1) / e;
            break;
        }
    }
    t = 'A';
    cout << t << endl;
    s = fast_power(t, e) % n;
    cout << s << endl;
    r = fast_power(s, d) % n;
    cout << r << endl;
}
