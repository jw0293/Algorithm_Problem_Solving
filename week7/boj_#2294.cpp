#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, k;
int coin[100 + 1];
int cache[10000 + 1];

void input(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> coin[i];
	}
	memset(cache, -1, sizeof(cache));
}

int solution(int cur, int cnt){
	if(cur == k) return 0;
	int &ret = cache[cur];
	if(ret != -1) return ret;
	ret = INF;
	for(int i=1;i<=n;i++){
		if(cur + coin[i] <= k) {
			ret = min(ret, solution(cur + coin[i], cnt+1) + 1);
		}
	}
	return ret;
}

int main(){
	fastio;	
	input();
	int answer = solution(0, 0);	
	if(answer == INF) answer = -1;
	cout << answer << endl;

	return 0;
}