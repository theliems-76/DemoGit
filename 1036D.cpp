#include<bits/stdc++.h>
using namespace std;
 const int N = 300 * 1000 + 9;
 int n,m;
 int a[N],b[N];
int main()
{
	int res=0;
	long long sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", a + i);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
	    scanf("%d", b + i);
}
   for(int i=0;i<n;i++)
   sum+=a[i];
   for(int i=0;i<m;i++)
   sum-=b[i];
   if(sum!=0)
    {
    	printf("-1");
    	return 0;
	}
	
		int i=0,j=0;
	while(i<n)
	{   res++;
		long long sumA=a[i++],sumB=b[j++];
		while(sumA!=sumB)
		{
			if(sumA<sumB)
			{
				sumA+=a[i++];
			}
			else
			sumB+=b[j++];
		}
		}	
 printf("%d\n", res);
   return 0;
}
    
