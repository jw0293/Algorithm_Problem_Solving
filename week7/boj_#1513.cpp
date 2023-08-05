#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, c;
ll answer[50 + 1];
int board[50 + 1][50 + 1];
ll cache[50 + 1][50 + 1][50 + 1][50 + 1];

void input(){
	cin >> n >> m >> c;
	for(int i=1;i<=c;i++){
		int y, x;
		cin >> y >> x;
		board[y][x] = i;
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= n && 1 <= x && x <= m);
}

ll path(int y, int x, int cnt, int prev){
	if(!isValid(y, x)) return 0;
	if(y == n && x == m) {
		if(cnt == 0 && board[y][x] == 0) return 1;
		if(cnt == 1 && board[y][x] > prev) return 1;
	}
	ll &ret = cache[y][x][cnt][prev];
	if(ret != -1) return ret % MOD;
	ret = 0;
	if(board[y][x] == 0){
		ret = (path(y+1, x, cnt, prev) + path(y, x+1, cnt, prev)) % MOD;
	} 
	else if(prev < board[y][x]){
		ret = (path(y+1, x, cnt-1, board[y][x]) + path(y, x+1, cnt-1, board[y][x])) % MOD;
	}
	return ret % MOD;
}

void solution(){
	memset(cache, -1, sizeof(cache));
	for(int i=0;i<=c;i++){
		cout << path(1, 1, i, 0) << " ";
	}
	cout << endl;
}

int main(){
	fastio;	
	input();
	solution();

	return 0;
}