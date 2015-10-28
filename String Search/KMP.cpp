#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  std::getline(std::cin, s1);
  cin >> s2;
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
      if (j != 0){
         j = a[j - 1];
      }
      else{
       a[i] = 0;
      }
    }
  }
  // for(int i = 0; i < len; i++){
  //   std::cout << i << " : " << a[i] << endl;
  // }
  int start = 0,checkFrom = 0;
  bool matched = false;
  while (start < s1.length()) {
    if(s1[start] == s2[checkFrom]){
      if(checkFrom == len - 1){
        std::cout << "at : " << start - len + 2 << std::endl;
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
  std::cout << "matched : " << matched << std::endl;
}
