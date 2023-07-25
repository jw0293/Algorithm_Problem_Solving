#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int k, n, m;
int a[1000 + 1], b[1000 + 1];
int pSum1[2000 + 1], pSum2[2000 + 1];
map<int, int> aCnt, bCnt;

void input(){
	cin >> k >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pSum1[i] = pSum1[i-1] + a[i];
	}
	for(int i=n+1;i<=2 * n;i++) pSum1[i] = pSum1[i-1] + a[i-n];
	
	for(int i=1;i<=m;i++){
		cin >> b[i];
		pSum2[i] = pSum2[i-1] + b[i];
	}
	for(int i=m+1;i<=m*2;i++) pSum2[i] = pSum2[i-1] + b[i-m];
}

void createMap(int n, int *psum, map<int, int> &cnt){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n+i-1;j++){
			int sum = psum[j] - psum[j-i];
			cnt[sum]++;
			if(i==n) break;
		}
	}
}

int solution(){
	int ans = 0;
	createMap(n, pSum1, aCnt);
	createMap(m, pSum2, bCnt);
	ans = (aCnt[k] + bCnt[k]);
	for(int i=1;i<k;i++) ans += (aCnt[i] * bCnt[k-i]);

	return ans;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}