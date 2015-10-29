#include <bits/stdc++.h>
using namespace std;

#define s(n) scanf("%d", &n)
#define p(n) printf("%d \t", n)
#define pn(n) printf("%d\n", n)
#define newline printf("\n")

void PrintSol(int **s, int i, int j){
	if(i == j) {
		printf(" A%d ", i);
	}
	else {
		printf("(");
		PrintSol(s, i, s[i][j]);
		PrintSol(s, s[i][j] + 1, j);
		printf(")");
	}
}

int main(){
	int n;
	s(n);
	int t = n + 1;
	int p[t];
	for (int i = 0; i < t; ++i){
		s(p[i]);
	}
	int m[t][t];
	int **s;
	s = new int* [t];
	for(int i = 0; i <t; i++)
	    s[i] = new int[t];
	for (int i = 0; i < t; ++i){
		m[i][i] = 0;
	}
	for (int i = 1; i < t ; i++){
		for (int j = 1; j < t - i; ++j){
			int x = j, y = j + i;
			m[x][y] = m[x][x] + m[x + 1][y] + p[x-1]*p[x]*p[y];
			s[x][y] = x;
			for (int z = x; z < y; ++z){
				if(m[x][y] > (m[x][z] + m[z + 1][y] + p[x-1]*p[z]*p[y])) {
					m[x][y] = m[x][z] + m[z + 1][y] + p[x-1]*p[z]*p[y];
					s[x][y] = z;
				}
			}
		}
	}
	printf("M is : \n");
	for (int i = t - 1; i > 0 ; i--){
		for (int j = 1; j < t - i; ++j){
			int x = j, y = j + i;
			p(m[x][y]);
		}
		newline;
	}

	for (int i = 1; i < t; ++i){
		p(m[i][i]);
	}
	newline;
	printf("And S is : \n");
	for (int i = t - 1; i > 0 ; i--){
		for (int j = 1; j < t - i; ++j){
			int x = j, y = j + i;
			p(s[x][y]);
		}
		newline;
	}
	printf("Paranthesis ");
	printf("(");
	PrintSol(s, 1, n);
	printf(")");
	newline;
}