#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef struct Info{
	ll tp;
	ll attack;
	ll health;
}Info;

int n;
ll s_h, atk, temp;
vector<Info> infos;

void input(){
	cin >> n >> atk;
	temp = atk;
	for(int i=0;i<n;i++){
		ll tp, a, h;
		cin >> tp >> a >> h;

		infos.push_back({tp, a, h});
	}
}

bool fight(ll m_a, ll m_h){
	ll s2m = m_h / atk;
	if(m_h % atk != 0) s2m++;

	ll m2s = s_h / m_a;
	if(s_h % m_a != 0) m2s++;

	if(s2m > m2s) return false;

	s_h -= (m_a * s2m);
	s_h += m_a;
	return true;
}

bool go(ll mid){
	s_h = mid, atk = temp;
	ll maxH = s_h;
	for(auto &a : infos){
		if(a.tp == 2){
			atk += a.attack;
			s_h += a.health; 
			if(maxH < s_h) s_h = maxH;
		} 
		else if(a.tp == 1) {
			bool result = fight(a.attack, a.health);
			if(!result) return false;
		}
	}
	return true;
}

ll solution(){
	ll left = 1, right = 9e18 - 10;
	ll mid = (left + right) / 2;
	while(left <= right){		
		if(go(mid)) right = mid - 1;
		else left = mid + 1;

		mid = (left + right) / 2;
	}
	return mid+1;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}