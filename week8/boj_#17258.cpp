#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M, K, T;
int otherPeople[300 + 1];
int cache[300 + 1][300 + 1][300 + 1];

void input(){
	cin >> N >> M >> K >> T;
	for(int i=0;i<M;i++){
		int from, to;
		cin >> from >> to;
		for(int nxt = from; nxt < to; nxt++){
			otherPeople[nxt]++;
		}
	}
}

int dp(int idx, int frd, int cur){
	if(idx > N) return 0;
	int &ret = cache[idx][frd][cur];
	if(ret != -1) return ret;
	ret = 0;
	if(T <= otherPeople[idx] + cur) {
		if(otherPeople[idx] < T){
			ret = max(ret, dp(idx+1, frd, cur) + 1);
		} else{
			if(otherPeople[idx] < T) ret = max(ret, dp(idx+1, frd, 0));
			else ret = max(ret, dp(idx+1, frd, 0) + 1);
		}
	} else{
		for(int i=0;i<=T-otherPeople[idx];i++){
			if(frd < i) break;
			if(T <= cur + i + otherPeople[idx]) {
				ret = max({ret, dp(idx+1, frd-i, cur+i) + 1});
			} else{
				ret = max({ret, dp(idx+1, frd-i, cur+i), dp(idx, frd-i, cur+i)});
			}
		}
	}
	return ret;
}

int solution(){
	memset(cache, -1, sizeof(cache));
	return dp(1, K, 0);
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}