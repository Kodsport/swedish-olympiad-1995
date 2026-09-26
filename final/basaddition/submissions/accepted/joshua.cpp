#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using p2 = pair<ll, ll>;
const ll inf = 1e18;

#define rep(i,n) for (ll i = 0; i < (n); i++)
#define repp(i,a,n) for (ll i = (a); i < (n); i++)
#define repe(i, arr) for (auto& i : arr)
#define all(x) begin(x),end(x)
#define sz(x) ((ll)(x).size())

bool check_base(int base, string l, string r, string ans) {
    map<char, ll> charToNum = { };

    rep(i, base) {
        if (i < 10) {
            charToNum[char(i + '0')] = i;
        }
        else {
            charToNum[char(i - 10 + 'A')] = i;
        }
    }

    auto to_base2 = [&](string val) { // interpret as base b
        ll value = 0;
        for (char c : val) {
            if (!charToNum.count(c)) return -1LL;
            value = value*base + charToNum[c];
        }
        return value;
    };

    ll lp = to_base2(l);
    ll rp = to_base2(r);
    ll ap = to_base2(ans);
    if (lp == -1 || rp == -1 || ap == -1) return false;
    return lp + rp == ap;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string l,r,ans;
    cin >> l >> r >> ans;
    vector<int> bases;
    repp(base, 2, 16+1) {
        if (check_base(base, l, r, ans)) {
            bases.push_back(base);
        }
    }

    repe(b,bases) cout << b << ' ';

    return 0;
}
