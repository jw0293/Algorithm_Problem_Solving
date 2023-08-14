#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
bool visited[50 + 1];
int cache[1001][1001];
int str[51], _int[51], pnt[51];

void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> str[i] >> _int[i] >> pnt[i];
	}
}

int dp(int STR, int INT){
	int &ret = cache[STR][INT];
	if(ret != -1) return ret;

	ret = 0;
	int pt = 0;
	vector<int> v;
	for(int i=0;i<n;i++){
		if(STR < str[i] && INT < _int[i]) continue;
		
		ret++;
		if(!visited[i]){
			visited[i] = true;
			pt += pnt[i];
			v.push_back(i);
		}
	}

	for(int p=0;p<=pt;p++){
		int nextSTR = min(1000, STR + p);
		int nextINT = min(1000, INT + pt - p);
		ret = max(ret, dp(nextSTR, nextINT));
	}

	for(auto here : v) visited[here] = false;

	return ret;
}

int solution(){
	int ans = -1;
	memset(cache, -1, sizeof(cache));
	ans = dp(1, 1);
	return ans == -1 ? 0 : ans;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}