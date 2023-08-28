#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
bool visited[16 + 1];
int cache[17][1 << 16];
int cost[16 + 1][16 + 1];

void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> cost[i][j];
		}
	}
}

int path(int node, int visited){
	if(visited == (1 << n) - 1){
		if(!cost[node][0]) return INF;
		return cost[node][0];
	}
	int &ret = cache[node][visited];
	if(ret != -1) return ret;
	ret = INF;
	for(int i=1;i<=n;i++){
		if(cost[node][i] == 0) continue;
		if((1 << i) & visited) continue;
		ret = min(ret, path(i, visited | (1 << i)) + cost[node][i]);
	}
	return ret;
}

int solution(){
	memset(cache, -1, sizeof(cache));
	return path(0, 1 << 0);
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}