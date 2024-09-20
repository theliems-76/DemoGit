#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	string a;
	cin>>t;
	for(int i=0;i<t;i++)
	{   string s[2];
		cin>>a;
		for(auto x:a)
		{
			s[int(x-'0')&1]+=x;
	}
		reverse(s[0].begin(),s[0].end());
		reverse(s[1].begin(),s[1].end());
		string re="";
		while(!(s[0].empty()&&s[1].empty()))
		{
			if(s[0].empty())
			{
			 re+=s[1].back();
			 s[1].pop_back();
			 continue;	
			}
			if(s[1].empty())
			{
				re+=s[0].back();
				s[0].pop_back();
				continue;
			}
			if(s[1].back()<s[0].back())
			{
				re+=s[1].back();
				s[1].pop_back();
			}
			else
			{
				re+=s[0].back();
				s[0].pop_back();
			}
			}
		cout<<re<<endl;
	}
	return 0;
}
