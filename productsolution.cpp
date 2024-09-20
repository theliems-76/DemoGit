#include<iostream>
#include<cmath>
#include<sstream>
#include<iomanip>
using namespace std;

const int MAX = 1e5;
const double EPS = 1e-9;
long double frt[MAX+1];

void init() {
    for(int i = 1; i <= MAX; ++i)
        frt[i] = frt[i-1] + log(i);
}

long double log(const string &p) {
    stringstream inp;
    if(p.size() < 14) {
        inp << p;
        long double d; inp >> d;
        return log(d);
    } else {
        inp << p.substr(0, 13);
        long double d; inp >> d;
        return log(d) + ((int) p.size() - 13) * log(10);
    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    string p; cin >> p;
    long double x = log(p);
    for(int i = 1, j = 1; i <= MAX; ++i) {
        while(j < MAX && frt[j] - frt[i-1] + EPS < x) ++j;
        if(abs(frt[j] - frt[i-1] - x) <= EPS) {
            cout << i << ' ' << j << endl;
            return 0;
        }
    }
    return 0;
}

