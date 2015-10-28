#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void dfsTraversal(std::vector<int> v[], int visited[], stack<int> s){
	int x = v[0][0];
	while (s.size() != 0){
		bool thereExists = false;
		for (std::vector<int>::iterator i = v[x].begin(); i < v[x].end(); i++){
			if(visited[*i] == 0){
				cout << *i + 1 << " ";
				x = *i;
				visited [*i] = 1;
				s.push(*i);
				thereExists = true;
				//cout << "if size++ : " << s.size() << endl;
				break;
			}
		}
		if (!thereExists){
			s.pop();
			if(s.size() > 0)
				x = s.top();
			//cout << "size-- : " << s.size() << endl;
		}
	}
}
void bfsTraversal(std::vector<int> v[], int visited[], queue<int> q, int l[]){
	int x = v[0][0];
	while (q.size() != 0){
		for (std::vector<int>::iterator i = v[x].begin(); i < v[x].end(); i++){
			if(visited[*i] == 0){
				cout << *i + 1 << " ";
				visited [*i] = 1;
				q.push(*i);
				l[*i] = l[x] + 1;
			}
		}
		q.pop();
		if(q.size() > 0)
			x = q.front();
	}
}
int main(){
	int node, edge;
	cin >> node >> edge;
	int a[edge][2];
	std::vector<int> v[node];
	for (int i = 0; i < node; ++i)
	{
		v[i].push_back(i);
	}
	for (int i = 0; i < edge; ++i){
		cin >> a[i][0] >> a[i][1];
		v[a[i][0] - 1].push_back(a[i][1] - 1);
		//if unDirected Graph
		v[a[i][1] - 1].push_back(a[i][0] - 1);
	}
	// print the graph
	for (int i = 0; i < node; ++i){
		for (std::vector<int>::iterator j = v[i].begin(); j < v[i].end(); ++j){
			cout << *j + 1;
			if(j != v[i].end() - 1)
				cout << "->";
		}
		cout << endl;
	}
	int visited[node];
	for (int i = 0; i < node; ++i){
		visited[i] = 0;
	}
	stack<int> s;
	s.push(v[0][0]);
	visited[0] = 1;
	cout << "DFS - Traversal : \n";
	cout << v[0][0] + 1 << " ";
	dfsTraversal(v, visited, s);
	//bfs traversal
	cout << "\nBFS - Traversal : \n";
	int level[node];
	for (int i = 0; i < node; ++i){
		visited[i] = 0;
		level[i] = 0;
	}
	queue<int> q;
	q.push(v[0][0]);
	visited[0] = 1;
	level[0] = 0;
	cout << v[0][0] + 1 << " ";
	bfsTraversal(v, visited, q, level);
	for (int i = 0; i < node; ++i){
		cout <<"\nLevel : " << i + 1 << " " << level[i];
	}
}
