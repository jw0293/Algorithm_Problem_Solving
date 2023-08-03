#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int number[100 + 1];
ll cache[100 + 1][2000 + 5][3];

void input(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> number[i];
	}
}

ll func(int idx, int cur, int op){
	if(cur < 0 || cur > 20) return 0;
	if(idx == n){
		if(cur == number[n]) return 1;
		return 0;
	}
	ll &ret = cache[idx][cur][op];
	if(ret != -1) return ret;
	ret = 0;
	return ret += func(idx+1, cur + number[idx], 1) + func(idx+1, cur - number[idx], 2);
}

ll solution(){
	memset(cache, -1, sizeof(cache));
	return func(2, number[1], 0);
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}