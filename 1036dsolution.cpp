#include <bits/stdc++.h>

using namespace std;

const int N = 300 * 1000 + 9;

int n, m;
int a[N], b[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", a + i);
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) scanf("%d", b + i);
    
    long long sum = 0;
    for(int i = 0; i < n; ++i) sum += a[i];
    for(int i = 0; i < m; ++i) sum -= b[i];
    if(sum != 0){
        puts("-1");
        return 0;
    }
    
    int posa = 0, posb = 0;
    int res = 0;
    while(posa < n){
        ++res;
        long long suma = a[posa++], sumb = b[posb++];
                
        while(suma != sumb){
            if(suma < sumb) suma += a[posa++];
            else sumb += b[posb++];
        }
    }
    
    printf("%d\n", res);
    return 0;
}
