#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int board[16 + 1][16 + 1];
int cache[16 + 1][16 + 1][16 + 1][16 + 1];

void input(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> board[i][j];
		}
	}
}

bool isValid(int y1, int x1, int y2, int x2){
	return (1 <= y1 && y1 <= n && 1 <= x1 && x1 <= n && 1 <= y2 && y2 <= n && 1 <= x2 && x2 <= n);
}

bool isCanLeft(int y, int x){
	if(board[y][x+1] == 1) return false;
	return true;
}

bool isCanDown(int y, int x){
	if(board[y+1][x] == 1) return false;
	return true;
}

bool isCanEdge(int y, int x){
	if(board[y][x+1] == 1 || board[y+1][x] == 1 || board[y+1][x+1] == 1) return false;
	return true;
}

int go(int y1, int x1, int y2, int x2){
	if(!isValid(y1, x1, y2, x2)) return 0;
	if(y2 == n && x2 == n) return 1;
	int &ret = cache[y1][x1][y2][x2];
	if(ret != -1) return ret;
	ret = 0;
	if(y1+1 == y2 && x1 == x2) {
		if(isCanDown(y2, x2)) ret += go(y2, x2, y2+1, x2);
		if(isCanEdge(y2, x2)) ret += go(y2, x2, y2+1, x2+1);
	}
	if(y1 == y2) {
		if(isCanLeft(y2, x2)) ret += go(y2, x2, y2, x2+1);
		if(isCanEdge(y2, x2)) ret += go(y2, x2, y2+1, x2+1);
	}
	if(y1+1 == y2 && x1+1 == x2) {
		if(isCanDown(y2, x2)) ret += go(y2, x2, y2+1, x2);
		if(isCanLeft(y2, x2)) ret += go(y2, x2, y2, x2+1);
		if(isCanEdge(y2, x2)) ret += go(y2, x2, y2+1, x2+1);
	}
	return ret;
}

int solution(){
	memset(cache, -1, sizeof(cache));
	return go(1, 1, 1, 2);
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}