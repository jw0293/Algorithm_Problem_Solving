#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, c, ans;
int stone[13 + 1];
bool visited[13 + 1];
int cache[24][1 << 14][24];

void input(){
	cin >> n >> m >> c;
	for(int i=0;i<n;i++){
		cin >> stone[i];
	}
}

int dp(int here, int ing, int capacity){
	if(here == m) return 0;
	int &ret = cache[here][ing][capacity];
	if(ret != -1) return ret;
	ret = max(ret, dp(here+1, ing, c));
	for(int i=0;i<n;i++){
		bool isbeforeIng = (1 << i) & ing;
		bool isINGCAN = (capacity - stone[i]) >= 0;
		if(!isbeforeIng && isINGCAN) ret = max(ret, dp(here, ing | (1 << i), capacity - stone[i]) + 1);
	}
	return ret;
}

int solution(){
	memset(cache, -1, sizeof(cache));
	return dp(0, 0, c);
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}