#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
int board[100 + 1][100 + 1];
int visited[100 +1][100 + 1];

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

void input(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		string str;
		cin >> str;
		for(int j=0;j<str.size();j++){
			if(str[j] == '1') board[i][j+1] = 1;
			else board[i][j+1] = 0;
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= n && 1 <= x && x <= m);
}

int solution(){
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({1, 1});
	visited[1][1] = 1;

	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if(y == n && x == m) return visited[y][x];
		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(!board[ny][nx]) continue;
			if(isValid(ny, nx) && !visited[ny][nx]){
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ny, nx});
			}
		}
	}
	return -1;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;
	
	return 0;
}