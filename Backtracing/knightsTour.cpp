#include <bits/stdc++.h>
using namespace std;
#define n 5
#define s(n) scanf("%d", &n)
#define p(n) printf("%d ", n)
bool isOkay(int x, int y, int sol[n][n]){
	if(x >= 0 && y >= 0 && x < n && y < n && sol[x][y] == -1){
		return true;
	}
	else 
		return false;
}
bool Solve(int sol[n][n], int xMove[], int yMove[], int abtak, int x, int y){
	if(n * n == abtak){
		return true;
	}
	int xNext, yNext;
	for (int i = 0; i < 8; ++i) {
		xNext = x + xMove[i];
		yNext = y + yMove[i];
		if(isOkay(xNext, yNext, sol)){
			sol[xNext][yNext] = abtak;
			if(Solve(sol, xMove, yMove, abtak + 1, xNext, yNext)){
				return true;
			}
			else{
				sol[xNext][yNext] = -1;
			}
		}
	}
	return false;
}

int main(){
	int sol[n][n];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			sol[i][j] = -1;
		}
	}
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	sol[0][0] = 0;
	bool possible = Solve(sol, xMove, yMove, 1, 0, 0);
	if(!possible){
		cout << "Oh. Go fuck urself.\n";
	}
	else{
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				p(sol[i][j]);
			}
			cout << endl;
		}
	}
}