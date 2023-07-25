#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
vector<int> a, b;

void solution(){
	sort(a.begin(), a.end());
	for(auto &x : b){
		int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
		if(idx == n || a[idx] != x) cout << 0 << endl;
		else cout << 1 << endl;
	}
}

void input(){
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n;
		a = vector<int>(n, 0);
		for(int i=0;i<n;i++){
			cin >> a[i];
		}

		cin >> m;
		b = vector<int>(m, 0);
		for(int i=0;i<m;i++){
			cin >> b[i];
		}

		solution();
	}
}

int main(){
	fastio;	
	input();

	return 0;
}