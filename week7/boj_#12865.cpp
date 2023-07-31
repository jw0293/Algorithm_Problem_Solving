#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, K;
int cache[100 + 1][100000 + 1];
pair<int, int> info[100 + 1];

void input(){
	cin >> N >> K;
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=N;i++){
		cin >> info[i].first >> info[i].second;
	}
}

int func(int cur, int k){
	if(cur > N) return 0;
	int &ret = cache[cur][k];
	if(ret != -1) return ret;
	ret = 0;
	if(info[cur].first <= k) ret = max({ret, func(cur+1, k-info[cur].first) + info[cur].second, func(cur+1, k)});
	else ret = max(ret, func(cur+1, k));
	return ret;
}

int main(){
	fastio;	
	input();
	cout << func(1, K) << endl;

	return 0;
}