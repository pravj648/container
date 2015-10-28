#include <iostream>
using namespace std;
long long largestPower(long long n){
	long long t = n&(n-1);
	while (t){
		t = n & (n-1);
		if(t == 0)
			break;
		else
			n = t;
	}
	return n;
}
int main(){
	long long t;
	cin >> t;
	for(long long i = 0; i < t; i++){
		long long n;
		cin >> n;
		long long temp = n & (n - 1);
		if(temp == 0){
			cout << "Case #" << i + 1 << ": 0" << endl;
		}
		else{
			bool invert = false;
			while(1){
				long long temp = n&(n-1);
				if(temp == 0){
					if(invert)
						cout << "Case #" << i + 1 << ": 1" << endl;
					else
						cout << "Case #" << i + 1 << ": 0" << endl;
					break;
				}
				else if(n < 4){
					if(n == 3 && invert){
						cout << "Case #" << i + 1 << ": 0" << endl;
					}
					else if(n == 3){
						cout << "Case #" << i + 1 << ": 1" << endl;						
					}
					else{
						if(invert)
							cout << "Case #" << i + 1 << ": 1" << endl;
						else
							cout << "Case #" << i + 1 << ": 0" << endl;
					}
					break;
				}
				else{
					invert = !invert;
					long long largestPow = largestPower(n);
					n = n - largestPow;
					n= largestPow - n;
				}
			}
		}
	}
}