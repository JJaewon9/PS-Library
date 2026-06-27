#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define all(x) x.begin(),x.end()
const int INF=1e9;
const ll LINF=4e18;

// DEBUG tempalte
string to_string(const string& s) { return '"'+s+'"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <typename A,typename B> string to_string(pair<A,B> p) { return "("+to_string(p.first)+", "+to_string(p.second)+")"; }
template <typename A,typename B,typename C> string to_string(tuple<A,B,C> p) { return "("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+")"; }
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void DEBUG_OUT() { cerr << endl; }
template <typename Head,typename... Tail> void DEBUG_OUT(Head H, Tail... T) { cerr << " " << to_string(H); DEBUG_OUT(T...); }
#ifdef ONLINE_JUDGE
#define DEBUG(...)
#else
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", DEBUG_OUT(__VA_ARGS__)
#endif

// multidimentional vector
template <typename T>
auto vec(size_t n, const T& value) {
    return vector<T>(n, value);
}

template <typename... Args>
auto vec(size_t n, Args... args) {
    return vector(n, vec(args...));
}

void TESTCASE() {
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T=1; //cin>>T;
    for (int tc=1;tc<=T;tc++) {
        TESTCASE();
    }
    return 0;
}
