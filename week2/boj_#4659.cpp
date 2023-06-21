#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

bool isFirst(string pw){
	for(auto c : pw){
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	}
	return false;
}

bool isSecond(string pw){
	if(pw.size() < 3) return true;
	for(int i=0;i<pw.size()-2;i++){
		bool flag = false;
		if(pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u'){
			for(int j=i+1;j<=i+2;j++){
				if(pw[j] != 'a' && pw[j] != 'e' && pw[j] != 'i' && pw[j] != 'o' && pw[j] != 'u'){
					flag = true;
					break;
				}
			}
			if(!flag) return false;
		} else{
			for(int j=i+1;j<=i+2;j++){
				if(pw[j] == 'a' || pw[j] == 'e' || pw[j] == 'i' || pw[j] == 'o' || pw[j] == 'u'){
					flag = true;
					break;
				}
			}
			if(!flag) return false;
		}
	}
	return true;
}

bool isThird(string pw){
	if(pw.size() < 2) return true;
	for(int i=0;i<pw.size()-1;i++){
		if(pw[i] == 'e' || pw[i] == 'o') continue;
		if(pw[i] == pw[i+1]) return false;
	}
	return true;
}

void solve(){
	string pw;
	while(1){
		cin >> pw;
		if(pw == "end") break;
		cout << "<" << pw << ">";
		if(!isFirst(pw) || !isSecond(pw) || !isThird(pw)) cout << " is not acceptable.\n";
		else cout << " is acceptable.\n";
	}
}

int main(){
	fastio;	
	solve();
	
	return 0;
}