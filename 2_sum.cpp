#include<bits/stdc++.h>
using namespace std;
const int N= 5000+9;
int n;
int main()
{ int a[N];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		int sumleft=0,sumright=0;
		int r=i+1;
		for(int l=i;l>=0;l--)
		{
			sumleft+=a[l];
			while(r<=n&&sumright<sumleft)
			{
				sumright+=a[r++];
			}
			if(sumleft==sumright)
			res=max(res,r-l);
		}
	}
	cout<<res<<endl;
    return 0;
}
