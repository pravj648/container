// Boyer Moore Algo
#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1;
  int t;
  cin >> t;
  while (t--) {
    cin >> s2;
    map <char, int> boyerTable;
    int len = s2.length();
    for(int i = 0; i < len -1; i++){
      map<char, int>::iterator it = boyerTable.find(s2[i]);
      if (it != boyerTable.end()){
          it->second = len - 1 - i;
        }
      else{
          boyerTable.insert(make_pair(s2[i], len - 1 - i));
      }
    }
    int start = 0;
    bool matched = false;
    while (start + len <= s1.length()){
      for(int i = start + len -1; i >= start; i--){
        if(s2[i - start] == s1[i] && i == start){
          matched = true;
          break;
        }
        else if(s2[i - start] != s1[i]){
          map<char, int>::iterator it = boyerTable.find(s1[i]);
          if (it != boyerTable.end()){
              start =  start + it->second;
              break;
            }
          else{
              start = start + len;
              break;
          }
        }
      }
      if(matched){
        break;
      }
    }
    if(matched)
      printf("Y\n");
    else
      printf("N\n");
  }
}
