#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, ret = INF;
int cache[40 + 1];

void input(){
	cin >> n;
	for(int i=1;i<=n;i++){
		string mp;
		cin >> mp;

		int value = 1;
		for(auto ch : mp){
			if(ch == 'T') cache[i] |= value;
			value *= 2;
		}
	}
}

void go(int here){
	if(here == n+1){
		int sum = 0;
		for(int i = 1; i <= (1 << (n-1)); i *= 2){
			int cnt = 0;
			for(int j = 1; j <= n; j++){
				if(cache[j] & i) cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		ret = min(ret, sum);
		return;
	}

	go(here + 1);
	cache[here] = ~cache[here];
	go(here + 1);
}

int main(){
	fastio;	
	input();
	go(1);
	cout << ret << endl;

	return 0;
}