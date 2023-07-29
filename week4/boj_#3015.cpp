#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<int> info;

void input(){
	cin >> n;
	info = vector<int>(n, 0);
	for(int i=0;i<n;i++){
		cin >> info[i];
	}
}

int getValue(int n){
	int ret = 0;
	for(int i=n-1;i>=1;i--) ret += i;
	return ret;
}

ll solution(){
	ll cnt, ans = 0;
	stack<pair<int, int>> stk;
	for(auto &n : info){
		cnt = 1;
		while(stk.size() && stk.top().first <= n){
			ans += stk.top().second;
			if(stk.top().first == n){
				cnt = stk.top().second + 1;
			} else{
				cnt = 1;
			}
			stk.pop();
		}
		if(stk.size()) ans++;
		stk.push({n, cnt});
	}
	return ans;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}