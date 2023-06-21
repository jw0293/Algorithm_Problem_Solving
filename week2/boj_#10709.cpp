#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 100 + 1;

int n, m;
int board[MX][MX];
int cache[MX][MX];

void input(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		string op; cin >> op;
		for(int j=0;j<op.size();j++){
			if(op[j] == '.') board[i][j+1] = 0;
			else board[i][j+1] = 1;
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= n && 1 <= x && x <= m);
}

void spreadCloud(queue<pair<int, int>> &q){
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if(!isValid(y, x+1)) continue;
		if(cache[y][x+1] == -1 || (cache[y][x+1] != -1 && cache[y][x] + 1 < cache[y][x+1])){
			cache[y][x+1] = cache[y][x]+1;
			q.push({y, x+1});
		}
	}
}

void solution(){
	queue<pair<int, int>> q;
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(board[i][j] == 1){
				q.push({i, j});
				cache[i][j] = 0;

				spreadCloud(q);
			}
		}
	}
}

void output(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << cache[i][j] << " ";
		}
		cout << '\n';
	}
}

int main(){
	fastio;	
	input();
	solution();
	output();

	return 0;
}