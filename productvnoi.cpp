#include<bits/stdc++.h>
using namespace std;
const int Max=1e5;
void result(long long p)
{
	int x=1,y=1,product=1;
	while(y<=Max)
	{
		product*=y;
		while(product>p&&x<y)
		{
			product/=x;
			x++;
		}	
		if(product==p)
		{	
		printf("%d %d",x,y);
		break;
	    }
	  y++;
	}
	}
int main()
{
    long long p;
	scanf("%lld",&p);
	result(p);
	return 0;
}		
			
