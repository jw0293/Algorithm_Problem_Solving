#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int T, W;
int pos[1000 + 1];
int cache[1000 + 1][30 + 1];

void input(){
	cin >> T >> W;
	for(int i=1;i<=T;i++){
		int x;
		cin >> x;
		pos[i] = x-1;
	}
}

int go(int cnt, int cur, int rest){
	if(cnt == T) {
		if(cur == pos[cnt] || rest > 0) return 1;
		return 0;
	}
	int &ret = cache[cnt][rest];
	if(ret != -1) return ret;

	ret = 0;
	if(cur == pos[cnt]) ret = max(ret, go(cnt+1, cur, rest)+1);
	else{
		if(rest > 0) ret = max({ret, go(cnt+1, cur, rest), go(cnt+1, (cur+1)%2, rest-1)+1});
		else ret = max(ret, go(cnt+1, cur, 0));
	}
	return ret;
}

int solution(){
	memset(cache, -1, sizeof(cache));
	return go(1, 0, W);
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}