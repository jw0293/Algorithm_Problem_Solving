#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, k;
vector<int> num;

void input(){
	cin >> n;
	num = vector<int>(n, 0);
	for(int i=0;i<n;i++){
		cin >> num[i];
	}
	cin >> k;
}

int solution(){
	int answer = 0;
	sort(num.begin(), num.end());
	for(int i=0;i<num.size()-1;i++){
		if(k <= num[i]) break;
		int x = k - num[i];
		int y = lower_bound(num.begin() + i + 1, num.end(), x) - num.begin();
		if(num[i] + num[y] == k) answer++;
	}
	return answer;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}