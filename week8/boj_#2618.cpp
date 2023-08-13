#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, w;
int py[1003], px[1003];
int cache[1003][1003];

void input(){
	cin >> n >> w;
	py[0] = 1, px[0] = 1;
	py[1] = n, px[1] = n;
	for(int i=2;i<w+2;i++){
		cin >> px[i] >> py[i];
	}
}

int getDist(int a, int b){
	return abs(px[a] - px[b]) + abs(py[a] - py[b]);
}

int dp(int a, int b){
	if(a == w+1 || b == w+1) return 0;
	int &ret = cache[a][b];
	if(ret != -1) return ret;
	ret = 0;
	int next = max(a, b)+1;
	return ret = min(dp(a, next) + getDist(b, next), dp(next, b) + getDist(a, next));

}

int solution(){
	memset(cache, -1, sizeof(cache));
	return dp(0, 1);
}

void printPath(){
	int a = 0, b = 1;
	for(int i=2;i<w+2;i++){
		if(cache[i][b] + getDist(a, i) < cache[a][i] + getDist(b, i)) cout << 1 << endl, a = i;
		else cout << 2 << endl, b = i;
	}
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;
	printPath();

	return 0;
}