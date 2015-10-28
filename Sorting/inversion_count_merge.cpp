#include <iostream>
using namespace std;
long long inverse = 0;
void Merge(long long a[], long long s, long long m, long long e){
  long long l = m - s,r = e - m;
  long long temp[ e - s ];
  long long i = 0, j = s, k = m;
  while (j < s + l && k < m + r) {
    if(a[ j ] <= a[ k ]){
      temp[ i ] = a[ j ];
      j++;
      }
    else{
      temp[ i ] = a[ k ];
      k++;
      /*
      How to get number of inversions in merge()?
        In merge process, let j is used for indexing left sub-array and k for right sub-array.
        At any step in merge(), if a[j] is greater than a[k], then there are (mid – j) inversions.
        because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[j+1], a[j+2] … a[mid]) will be greater than a[k].
        for example : in 3 1 2, there are 2 inversions.
          so in merging 1 and 2 no inversions will be made.
          and in merging 3 and 1, 2 there will be two inversions.
          1 will be during merge of 3 and 1 and other one will during 3 and 2.
      */
      inverse += m - j;
    }
    i++;
  }
  while (j < s + l){
    temp[ i ] = a[ j ];
    j++;
    i++;
  }
  while (k < m + r){
    temp[ i ] = a[ k ];
    k++;
    i++;
  }
  for (long long i = s; i < e; i++){
    a[i] = temp [ i - s ];
  }
}
void mergeSort(long long a[], long long s, long long e) {
  if(e-s > 1){
    long long m = (s + e) / 2;
    mergeSort(a, s, m);
    mergeSort(a, m, e);
    Merge(a, s, m, e);
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for(long long i = 0; i < n; i++){
      cin >> a[i];
    }
    mergeSort(a, 0, n);
    // for(int i = 0; i < n; i++){
    //   std::cout << a[i] << " ";
    // }
    std::cout << inverse << std::endl;
    inverse = 0;
  }
}
