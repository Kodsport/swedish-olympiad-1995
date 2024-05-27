#include <cstdio>
#include <iostream>
#include <map>
#include <cassert>

using namespace std;

map<char, int> dig;

typedef long long ll;
ll tobase(string& s, int base){
	ll ans = 0;
	for(int i = 0; i < s.size(); ++i){
		ans *= base;
		ans += dig[s[i]];
	}
	return ans;
}

int main(){
	for(int i = 0; i <= 9; ++i) dig['0'+i] = i;
	for(int i = 0; i <= 5; ++i) dig['A'+i] = 10+i;
	string a, b, c;
	cin >> a >> b >> c;
	int mi = 1;
	int count = 0;
	for(int i = 0; i < a.size(); ++i) if(dig[a[i]] > mi) mi = dig[a[i]];
	for(int i = 0; i < b.size(); ++i) if(dig[b[i]] > mi) mi = dig[b[i]];
	for(int i = 0; i < c.size(); ++i) if(dig[c[i]] > mi) mi = dig[c[i]];
	for(int i = mi+1; i <= 16; ++i){
		if(tobase(a, i) + tobase(b, i) == tobase(c, i)) count++, printf("%d\n", i);
	}
	assert(count > 0);
}
