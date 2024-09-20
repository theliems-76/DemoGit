#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
int a[maxn];
int n, i, l, r, sl, sr, res;

int main() {
    // Ð?c vào giá tr? n và các ph?n t? c?a m?ng
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // X? l? logic
    for (i = 1; i <= n; i++) {
        sl = 0;
        sr = 0;
        r = i + 1;

        for (l = i; l >= 1; l--) {
            sl += a[l];
            while (r <= n && (sr < sl || a[r] == 0)) {
                sr += a[r];
                r++;
            }
            if (sl == sr) {
                res = max(res, r - l);
            }
        }
    }

    // In k?t qu?
    cout << res << endl;
    return 0;
}

