#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;

void input(){
	cin >> n;
}

string solution(){
	int cnt = 0, number = 1, index;
	string op = "666";
	while(1){
		if((index = to_string(number).find(op)) != string::npos){
			cnt++;
			if(cnt == n) return to_string(number);
		}
		number++;
	}
	return "no";
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}