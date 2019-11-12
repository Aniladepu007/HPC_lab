#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout.setf(ios::fixed); cout.precision(20);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define endl "\n"
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define b begin
#define e end
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<long long> vl;
#define pl pair<ll, ll>
#define pll pair<ll, pair<ll, ll> >
#define gcd __gcd
const int MOD = 1e9+7;
const ll INF = 1e18;
const int MX = 1e5 + 5;
const ld PI = 4 * atan((ld)1);
#define mod 1e9+7
ll M = mod;

int vis[MX];
vi adj[MX];
void dfs(int v){
	vis[v]=1;
	for(auto it:adj[v])
		if(!vis[it])
			dfs(it);
}

void scan(ll &number) {
    bool negative = false; register ll c; number = 0;
    c = getchar(); if (c=='-') { negative = true; c = getchar(); }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

void solve() {

}

int main() {
    fio;
//ll t;cin>>t;
//while(t--)
    solve();

    return 0;
}
