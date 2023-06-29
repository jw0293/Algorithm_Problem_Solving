#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef struct Info{
	int a;
	int b;
	int c;
}Info;

int N, ret = INF;
queue<Info> q;
vector<int> scv;
vector<vector<int>> damage;
int visited[65][65][65];

void input(){
	cin >> N;
	scv = vector<int>(N, 0);
	for(int i=0;i<N;i++){
		cin >> scv[i];
	}
}

void initDamage(){
	vector<int> temp = {1, 3, 9};
	do{
		vector<int> ps;
		for(auto t : temp) ps.push_back(t);
		damage.push_back(ps);
	}while(next_permutation(temp.begin(), temp.end()));
}

int solution(){
	q.push({scv[0], scv[1], scv[2]});
	visited[scv[0]][scv[1]][scv[2]] = 1;

	while(!q.empty()){
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		if(visited[0][0][0]) break;
		for(auto &s : damage){
			int na = max(0, a - s[0]);
			int nb = max(0, b - s[1]);
			int nc = max(0, c - s[2]);

			if(visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({na, nb, nc});
		}
	}
	return visited[0][0][0] - 1;
}

int main(){
	fastio;	
	input();
	initDamage();
	cout << solution() << endl;

	return 0;
}