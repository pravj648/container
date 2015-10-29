#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

float dp[1005];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	float t,a[1005],n,l,r,m;
	double f,p;
	cin>>t;
	for(ll i=0;i<t;i++)
	{
		cin>>n>>m;
		dp[0]=1;
		dp[1]=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j-1];
			dp[j] = dp[j-1]*a[j-1];
		}
		cout<<"Case #"<<i+1<<":\n";
		for(int k=0;k<m;k++)
		{
			cin>>l>>r;
			p=1/(r-l+1);
			f=1;
			for(int x=l;x<=r;x++)
                f *= a[x];
			//cout<<p<<endl;
			f = pow((f),p);
			cout<<setprecision(10)<<f<<endl;
		}
	}
}
