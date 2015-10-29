#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair

int main()
{
	ios_base::sync_with_stdio(0);
	int t,m;
	long double p,a,b,init;
	cin>>t;
	while(t--)
	{
		init = 1000000000.000;

		cin>>m>>p;
		if(p==0.0)
        {
            cout<<setprecision(3)<<fixed<<init<<" "<<0.0<<endl;
            continue;
        }
        a=init*(1-(pow(-1*p,m)));
        a/=(1+p);
        b = init - a;
		cout << setprecision (3) << fixed <<a<<" "<<b<<endl;
	}
}
