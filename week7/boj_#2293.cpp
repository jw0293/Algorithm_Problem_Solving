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
}

int solution(){
	cache[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=coin[i];j<=k;j++){
			cache[j] += cache[j - coin[i]];
		}
	}
	return cache[k];
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}