#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
char board[50 + 1][50 + 1];
bool visited[50 + 1][50 + 1];
ll cache[50 + 1][50 + 1];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

void input(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> board[i][j];
		}
	}
}

bool isValid(int y, int x){
	if(board[y][x] == 'H') return false;
	int jump = board[y][x] - '0';
	for(int d = 0; d < 4; d++){
		int ny = y + dy[d] * jump;
		int nx = x + dx[d] * jump;
	
        if(ny < 1 || ny > n || nx < 1 || nx > m) continue;
        if(board[ny][nx] != 'H') return true;
	}
	return false;
}

ll func(int y, int x){
	if(visited[y][x]) return INF;
	visited[y][x] = true;
	if(!isValid(y, x)) return 0;
	ll &ret = cache[y][x];
	if(ret != -1) return ret;
	ret = 0;
	int jump = board[y][x] - '0';
	for(int i=0;i<4;i++){
        int ny = y + dy[i] * jump;
        int nx = x + dx[i] * jump;
        if(ny < 1 || ny > n || nx < 1 || nx > m || board[ny][nx] == 'H') continue;
		ret = max(ret, func(ny, nx) + 1);
		visited[ny][nx] = false;
	}
	return ret;
}

ll solution(){
	memset(cache, -1, sizeof(cache));
	int result = func(1, 1) + 1;
	return result > n*m ? -1 : result;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}