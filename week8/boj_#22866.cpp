#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<int> h;
int cnt[100000 + 1], idx[100000 + 1][2];

void input(){
	cin >> n;
	h = vector<int>(n+1, 0);
	for(int i=1;i<=n;i++){
		cin >> h[i];
		idx[i][0] = INF;
	}
}

void findLeftTall(){
	stack<pair<int, int>> temp;
	for(int i=1;i<=n;i++){
		while(!temp.empty() && temp.top().second <= h[i]) temp.pop();
		cnt[i] += temp.size();
		if(!temp.empty() && abs(i-temp.top().first) < idx[i][0]){
			idx[i][0] = abs(i-temp.top().first);
			idx[i][1] = temp.top().first;
		}
		temp.push({i, h[i]});
	}
}

void findRightTall(){
	stack<pair<int, int>> temp;
	for(int i=n;i>=1;i--){
		while(!temp.empty() && temp.top().second <= h[i]) temp.pop();
		cnt[i] += temp.size();
		if(!temp.empty() && abs(i-temp.top().first) < idx[i][0]){
			idx[i][0] = abs(i-temp.top().first);
			idx[i][1] = temp.top().first;
		}
		temp.push({i, h[i]});
	}
}

void solution(){
	findLeftTall();
	findRightTall();
	for(int i=1;i<=n;i++){
		cout << cnt[i] << " ";
		if(idx[i][0] == INF) cout << endl;
		else cout << idx[i][1] << endl;
	}
}

int main(){
	fastio;	
	input();
	solution();

	return 0;
}