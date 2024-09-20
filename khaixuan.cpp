#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 20) + 10;
int a[N];
int n;

long long calc(int x) {
    if (x == 0) return 0;
    map<int, int> mp;
    long long res = 0; int cnt = 0;
    for (int r = 1, l = 1; r <= n; r++) {
        cnt += ++mp[a[r]] == 1;
        while (l < r && cnt > x)
            cnt -= --mp[a[l++]] == 0;
        res += r - l + 1;
    }
    return res;
}

int main() {
    int l, u;
    cin >> n >> l >> u;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << calc(u) - calc(l - 1);
    return 0;
}
