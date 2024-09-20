#include<bits/stdc++.h>
using namespace std;
const int N=500*1000+9;
int main()
{
	int n,m;
	int a[N];
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int sum=-1;
	for(int i=0;i<n;i++)
	{
		int lo=0,hi=n-1;
		while(lo<hi)
		{
			if(lo==i)
			lo++;
			else if(hi==i)
			hi--;
			else if(a[lo]+a[hi]+a[i]<=m)
			{
				sum=max(sum,a[lo]+a[hi]+a[i]);
				lo++;
			}
			else hi--;
		}
	}
	cout<<sum<<endl;
	return 0;
}				
			
		
