#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define MOD 1000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, h;
int board[1000 + 1][1000 + 1];
ll cache[1000 + 1][1000 + 1];

void input(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> board[i][j];
		}
	}
	cin >> h;
}

bool isValid(int y, int x){
	return (1 <= y && y <= n && 1 <= x && x <= m);
}

ll path(int y, int x){
	if(!isValid(y, x)) return INF;
	if(y == n && x == m) return 0;
	ll &ret = cache[y][x];
	if(ret != -1) return ret;
	ret = INF;
	if(y+1 <= n) ret = min(ret, path(y+1, x) + board[y+1][x]);
	if(x+1 <= m) ret = min(ret, path(y, x+1) + board[y][x+1]);
	return ret;
}

ll solution(){
	memset(cache, -1, sizeof(cache));
	return path(1, 1) + board[1][1];
} 

int main(){
	fastio;	
	input();
	ll answer = solution();
	if(answer > h) cout << "NO" << endl;
	else cout << "YES" << endl << answer << endl;
 
	return 0;
}