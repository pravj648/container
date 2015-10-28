#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int s[101];
map<string, priority_queue<int> > mp;
vector<pair<string, int> > res;
bool compare(const pair<string, int> &a,const pair<string, int> &b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    }
    else
        return a.second>b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,p,n,w,m;
	string nm;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    mp.clear();
	    res.clear();
        cin>>p;
        for(int j=0;j<p;j++)
            cin>>s[j];
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>w;
            for(int k=0;k<p;k++)
            {
                cin>>nm;
                mp[nm].push(s[k]*w);

            }

        }
        cin>>m;
        map<string, priority_queue<int> >::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            int score=0;
            for(int z=0;z<m;z++)
            {
                if(!it->second.empty())
                {
                    score+=it->second.top();
                    it->second.pop();

                }
            }
            res.push_back(make_pair(it->first,score));
        }

        sort(res.begin(),res.end(),compare);
        cout<<"Case #"<<i+1<<":\n";
        int scr=INT_MAX,rnk=0,cnt=1;
        for(int x=0;x<res.size();x++)
        {
            if(res[x].second<scr) {
                    scr=res[x].second;
                    rnk+=cnt;
                    cnt=1;
            }
            else
                cnt++;
            cout<<rnk<<": "<<res[x].first<<endl;
        }
	}
}
