#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654321
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, ty, tx, len;
int board[200+1][200+1];
ll cache[200+1][200+1];

void input(){
	cin >> m >> n;
	cin >> tx >> ty;
	len = (ty-1) + (tx-1);
}

bool isValid(int y, int x){
	return (1 <= y && y <= n && 1 <= x && x <= m);
}

ll path(int y, int x, int py, int px, int cnt, int plen){
	if(!isValid(y, x)) return 0;
	if(y==py && x==px){
		if(cnt == plen) return 1;
		return 0;
	}
	ll &ret = cache[y][x];
	if(ret != -1) return ret % MOD;
	ret = 0;
	return ret += (path(y+1, x, py, px, cnt+1, plen) + path(y, x+1, py, px, cnt+1, plen)) % MOD;
}

ll solution(){
	memset(cache, -1, sizeof(cache));
	ll middle = path(1,1, ty, tx, 0, len) % MOD;
	if(n == ty || m == tx) return middle % MOD;
	memset(cache, -1, sizeof(cache));
	ll result = path(ty, tx, n, m, 0, (n-ty) + (m-tx)) % MOD;
	return middle * result % MOD;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;
 
	return 0;
}