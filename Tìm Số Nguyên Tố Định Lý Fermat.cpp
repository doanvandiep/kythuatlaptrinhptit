#include <bits/stdc++.h>
 
using namespace std;
 
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
 
long long Rand(long long l, long long h) {
    return l + rd() % (h - l + 1);
}
 
long long mul(long long a, long long b, long long mod) {
    long long res = 0;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return res;
}
 
long long Pow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = mul(res, a, mod);
        a = mul(a, a, mod);
        b /= 2;
    }
    return res;
}
 
bool isPrime(long long n) {
    for (int i = 1; i <= 100; i++) {
        long long x = Rand(2, n - 1);
        if (Pow(x, n - 1, n) != 1) return false;
    }
    return true;
}
 
int main() {
    long long n; cin >> n;
    if (isPrime(n)) cout << "n la so nguyen to";
    else cout << "n khong la so nguyen to";
}