#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll s, c;
ll total;
vector<ll> info;

void input(){
	cin >> s >> c;
	info = vector<ll>(s, 0);
	for(int i=0;i<s;i++){
		cin >> info[i];
		total += info[i];
	}
}

ll solution(){
	ll pl = 1, pr = 1000000000, mid;
	mid = (pl + pr) / 2;
	while(pl <= pr){
		int cnt = 0;
		for(int i=0;i<s;i++){
			cnt += info[i] / mid;
		}

		if(c <= cnt) pl = mid + 1;
		else pr = mid - 1;
		mid = (pl + pr) / 2;
	}
	
	return total - mid * c;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}