#include<bits/stdc++.h>
using namespace std;
const int N=1000*1000+9;
int n,l,d,a[N];
	deque<int> ma,mi;
int main()
{
	cin>>n;
	cin>>l;
	cin>>d;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long res=0;
	int j=0;
	for(int i=0;i<n;i++)
	{
	while (!ma.empty() && a[ma.back()] <= a[i]) ma.pop_back();
        while (!mi.empty() && a[mi.back()] >= a[i]) mi.pop_back();
        ma.push_back(i); mi.push_back(i);
        while (a[ma.front()] - a[mi.front()] > d) {
            j++;
            if (ma.front() < j) ma.pop_front();
            if (mi.front() < j) mi.pop_front();
        }
        if (j <= (i - l ))
        {
            res += i - j - l+1;
    }
    }
    cout << res;
    return 0;
	}	
		
	
	

