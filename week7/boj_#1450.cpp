#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, c, a[30 + 1];
vector<int> temp1, temp2;

void input(){
	cin >> n >> c;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
}

void go(int here, int _last, vector<int> &v, int sum){
	if(sum > c) return;
	if(here > _last){
		v.push_back(sum);
		return;
	}
	go(here+1, _last, v, sum + a[here]);
	go(here+1, _last, v, sum);
}

ll solution(){
	ll ret = 0;
	go(0, n/2-1, temp1, 0);
	go(n/2, n-1, temp2, 0);
	sort(temp1.begin(), temp1.end());
	sort(temp2.begin(), temp2.end()); 
	for(auto cur : temp1){
		if(c - cur >= 0) ret += ((int)(upper_bound(temp2.begin(), temp2.end(), c-cur) - temp2.begin()));
	}
	return ret;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}