#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, t, A, B;
int sum1, sum2;
string info, pretv="";

int changeToInt(string str){
	return (stoi(str.substr(0, 2)) * 60) + stoi(str.substr(3, 2));
}

string print(int x){
	string h = "00" + to_string(x / 60);
	string m = "00" + to_string(x % 60);

	return h.substr(h.size()-2, 2) + ":" + m.substr(m.size()-2,2);
}

void input(){
	cin >> n;
	while(n--){
		cin >> t >> info;
		if(A > B) sum1 += changeToInt(info) - changeToInt(pretv);
		else if(B > A) sum2 += changeToInt(info) - changeToInt(pretv);
		t == 1 ? A++ : B++;
		pretv = info;
	}
	if(A > B) sum1 += changeToInt("48:00") - changeToInt(pretv);
	else if(B > A) sum2 += changeToInt("48:00") - changeToInt(pretv);

	cout << print(sum1) << endl;
	cout << print(sum2) << endl;
}

int main(){
	fastio;	
	input();

	return 0;
}