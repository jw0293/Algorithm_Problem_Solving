#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, k;
int arr[100000 + 2];
int psum[100000 + 2];

void input(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		psum[i] = psum[i-1] + arr[i];
	}
}

int solution(){
	int maxV = -INF;
	for(int i=k;i<=n;i++){
		maxV = max(maxV, psum[i] - psum[i-k]);
	}
	return maxV;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;
	
	return 0;
}