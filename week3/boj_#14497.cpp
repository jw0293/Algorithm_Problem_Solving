#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 300 + 1;

int N, M;
bool isEnd;
int sy, sx, y2, x2;
int board[MX][MX];
bool visited[MX][MX];

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

void input(){
	cin >> N >> M;
	cin >> sy >> sx >> y2 >> x2;
	for(int i=1;i<=N;i++){
		string temp;
		cin >> temp;
		for(int j=0;j<temp.size();j++){
			if(temp[j] == '0') board[i][j+1] = 0;
			else if(temp[j] == '1') board[i][j+1] = 1;
			else if(temp[j] == '#') board[i][j+1] = 7;
			else board[i][j+1] = -1; 
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= M);
}

void go(int y, int x){
	if(board[y][x] == 1) {
		board[y][x] = 0;
		return;
	}
	if(y == y2 && x == x2){
		isEnd = true;
		return;
	}

	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(!isValid(ny, nx)) continue;
		if(!visited[ny][nx]) {
			visited[ny][nx] = true;
			go(ny, nx);
		}
	}
}

int solution(){
	int ret = 0;
	queue<pair<int, int>> q;
	while(1){
		if(isEnd) return ret;
		memset(visited, false, sizeof(visited));
		visited[sy][sx] = true;
		q.push({sy, sx});

		while(!q.empty()){
			pair<int, int> cur = q.front();
			q.pop();

			for(int i=0;i<4;i++){
				int ny = cur.first + dy[i];
				int nx = cur.second + dx[i];

				if(!isValid(ny, nx)) continue;
				if(!visited[ny][nx]) {
					visited[ny][nx] = true;
					go(ny, nx);
				}
			}
		}
		ret++;
	}
	return -1;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}