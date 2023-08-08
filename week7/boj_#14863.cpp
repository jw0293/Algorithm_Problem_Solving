#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N_SIZE = 100 + 1;

int n, k;
int walk[N_SIZE], w_cost[N_SIZE], bike[N_SIZE], b_cost[N_SIZE];
ll cache[100000 + 1][100 + 1];

void input(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> walk[i] >> w_cost[i] >> bike[i] >> b_cost[i];
	}
}

ll dp(int restTime, int idx){
	if(idx > n) return 0;
	if(restTime - walk[idx] < 0 && restTime - bike[idx] < 0) return -INF;
	ll &ret = cache[restTime][idx];
	if(ret != -1) return ret;
	ret = -INF;
	if(restTime - walk[idx] >= 0) ret = max(ret, dp(restTime-walk[idx], idx+1) + w_cost[idx]);
	if(restTime - bike[idx] >= 0) ret = max(ret, dp(restTime-bike[idx], idx+1) + b_cost[idx]);
 	return ret;
}

ll solution(){
	memset(cache, -1, sizeof(cache));
	return dp(k, 1);
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}