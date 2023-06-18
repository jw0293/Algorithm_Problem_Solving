#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int a, b, c;
int parking[100 + 1];

vector<string> split(string input, string delimiter){
	vector<string> ret;
	ll pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);

	return ret; 
}

void input(){
	cin >> a >> b >> c;
	for(int i=0;i<3;i++){
		int from, to;
		cin >> from >> to;

		for(int j=from;j<to;j++){
			parking[j]++;
		}
	}
}

int solution(){
	int cost = 0;
	for(int i=1;i<=100;i++){
		if(parking[i] == 0) continue;
		if(parking[i] == 1){
			cost += a;
		} 
		else if(parking[i] == 2){
			cost += b * 2;
		}
		else if(parking[i] == 3){
			cost += c * 3;
		}
	}

	return cost;
}

int main(){
	fastio;
	input();
	cout << solution() << endl;

	return 0;
}