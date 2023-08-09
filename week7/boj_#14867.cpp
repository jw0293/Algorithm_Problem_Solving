#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int a, b, purposeA, purposeB;
map<pair<int, int>, int> cache;

void input(){
	cin >> a >> b >> purposeA >> purposeB;
}

int dp(int curA, int curB){
	if(curA > a && curB > b) return INF;
	if(curA == purposeA && curB == purposeB) return 0;
	auto &ret = cache[{curA,curB}];
	if(ret != 0) return ret;
	ret = INF;
	ret = min({ret, dp(a, curB) + 1, dp(curA, b) + 1, dp(0, curB) + 1, dp(curA, 0) + 1});
	if(b - curB > 0 && curA <= b - curB) ret = min(ret, dp(0, curB + curA) + 1);
	else {
		int rest = b - curB;
		ret = min(ret, dp(curA - rest, b) + 1);
	}

	if(a - curA > 0 && curB <= a - curA) ret = min(ret, dp(curA + curB, 0) + 1);
	else {
		int rest = a - curA;
		ret = min(ret, dp(a, curB - rest) + 1);
	}
	return ret;
}

int solution(){
	int ans = dp(0, 0);
	return ans == INF ? -1 : ans;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}