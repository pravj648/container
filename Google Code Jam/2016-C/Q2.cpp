#include <bits/stdc++.h>
using namespace std;
#define ll long long
int hun =0;
int main() {
    ios_base::sync_with_stdio(0);

        freopen("input.in","r",stdin);
        freopen("output.txt","w",stdout);
    cin.tie(NULL);
	ll t,n,p,k,check;
	double temp,low,high;
	cin>>t;
	ll f=t;
	while(t--)
	{
		cin>>n;
        low=0,high=LLONG_MAX;

        hun=0;
		while(n--)
		{

			cin>>p>>k;
			 if(p==100)
			{
		     temp = k;
		      if(temp>low)
			 low = temp;
			 if(temp<high)
			 high =temp;
			 hun = low;
			}
			else if(p==0)
			{
			 temp = (100) * k;
			 if(temp>low)
			 low = temp;
			}

			else
			{
				temp = (100.0/p) * k;

			    if(temp<high)
			     high = temp;

				temp = (100.0/(p+1)) * k;

				if(temp>low)
                    low = temp;

			}

		}
        ll tl,th;
	    if(ceil(low)==low && hun!=low)
	    {
	        tl=low+1;
	    }else
	    tl =ceil(low);

	    th = floor(high);

		if(th==tl)
		{
			cout<<"Case #"<<f-t<<": "<<tl<<endl;
		}
		else
			cout<<"Case #"<<f-t<<": "<<"-1"<<endl;
	}
	return 0;
}
