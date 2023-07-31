#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int hap[20 + 1], sad[20 + 1];
int cache[20 + 1][2000 + 1];

void input(){
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=n;i++) cin >> sad[i];
	for(int i=1;i<=n;i++) cin >> hap[i];
}

int func(int cur, int hp){
	if(cur > n) return 0;
	int &ret = cache[cur][hp];
	if(ret != -1) return ret;

	ret = 0;
	if(sad[cur] < hp) ret = max({ret, func(cur+1, hp-sad[cur]) + hap[cur], func(cur+1, hp)});
	else ret = max(ret, func(cur+1, hp));
	return ret;
}

int main(){
	fastio;	
	input();
	cout << func(1, 100) << endl;

	return 0;
}