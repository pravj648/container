using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
#define ll long long

const int MN = 20000000;
int arr[400500],forward[400500],backward[400500];
struct trie {
  int n;
  int nodes[MN][2];

  void clear() {
    n = 1;
    nodes[0][0] = nodes[0][1] = -1;
  }

  void insert(int x) {
    int node = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (x & (1 << i)) != 0;
      if (nodes[node][next] == -1) {
        nodes[node][next] = n;
        nodes[n][0] = nodes[n][1] = -1;
        n++;
      }
      node = nodes[node][next];
    }
  }

  int query(int x) {
    int node = 0;
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (x & (1 << i)) != 0;
      int cool = 1;
      if (nodes[node][next ^ 1] == -1) {
        next ^= 1;
        cool = 0;
      }
      if (cool)
        ans += (1 << i);

      if (nodes[node][next ^ 1] == -1) while (true) {}
      node = nodes[node][next ^ 1];
    }
    return ans;
  }
};

trie tree;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);


    int n;cin >> n;
    tree.clear();
    tree.insert(0);
    int best = 0, accum = 0, t;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      accum ^= arr[i];
      best = max(best, tree.query(accum));
      forward[i]=max(best,tree.query(0));
      tree.insert(accum);
    }
    tree.clear();
    tree.insert(0);
    best = 0;
    accum=0;
    for(int i=n-1;i>=0;i--)
    {
      accum ^= arr[i];
      best = max(best,tree.query(accum));
      backward[i]=max(best,tree.query(0));
      tree.insert(accum);
    }
    best = max(best, tree.query(0));
    ll sum=0;
    for(int i=1;i<n;i++)
    {
      if(forward[i-1]+backward[i]>sum)
        sum=forward[i-1]+backward[i];
    }
    cout<<sum<<endl;

  return 0;
}
