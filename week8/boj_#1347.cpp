#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define MOD 1000000009
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, -1, 0, 1};

int n, dir; 
string order;
int board[210 + 1][210 + 1];
bool visited[210 + 1][210 + 1];

void input(){
	cin >> n;
	cin >> order;
}

int getDir(int cur, char order){
	if(order == 'R'){
		if(cur == 0) return 1;
		if(cur == 1) return 2;
		if(cur == 2) return 3;
		if(cur == 3) return 0;
	} else{
		if(cur == 0) return 3;
		if(cur == 1) return 0;
		if(cur == 2) return 1;
		if(cur == 3) return 2;
	}
	return -1;
}

void printResult(int my, int MY, int mx, int MX){
	for(int i=my;i<=MY;i++){
		for(int j=mx;j<=MX;j++){
			if(board[i][j] == 0) cout << '.';
			else cout << '#';
		}
		cout << endl;
	}
}

void solution(){
	memset(board, -1, sizeof(board));

	int y = 51, x = 51, dir = 0;
	int my = y, MY = y, mx = x, MX = x;
	visited[y][x] = true;
	board[y][x] = 0;
	for(auto &o : order){
		if(o == 'R' || o == 'L') dir = getDir(dir, o);
		else {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			visited[ny][nx] = true;
			board[ny][nx] = 0;

			my = min(my, ny);
			mx = min(mx, nx);

			MY = max(MY, ny);
			MX = max(MX, nx);

			y = ny;
			x = nx;
		}
	}
	printResult(my, MY, mx, MX);
}

int main(){
	fastio;	
	input();
	solution();
 
	return 0;
}