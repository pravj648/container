#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  string s1, s2;
  while (cin >> t) {
    cin >> s2 >> s1;
    int len = s2.length();
    int a[len];
    a[0] = 0;
    int j = 0;
    for(int i = 1; i < len; i++){
      if(s2[i] == s2[j]){
        a[i] = j + 1;
        j++;
      }
      else{
        while (1) {
          if(j == 0 || s2[j] == s2[i])
            break;
          else
            j = a[j-1];
        }
        if(s2[j] == s2[i]){
          a[i] = j + 1;
          j++;
        }
        else{
          a[i] = 0;
        }
      }
    }
    int start = 0,checkFrom = 0;
    bool matched = false;
    while (start < s1.length()) {
      if(s1[start] == s2[checkFrom]){
        if(checkFrom == len - 1){
          matched = true;
          break;
        }
        else{
          start++;
          checkFrom++;
        }
      }
      else{
        if(checkFrom == 0){
          start++;
        }
        else{
          checkFrom = a[checkFrom - 1];
        }
      }
    }
    if(matched)
      printf("Y\n");
    else
      printf("N\n");
  }
}
