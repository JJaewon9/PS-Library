template<ll P, ll M> struct Hashing {
    vector<ll> h, p;
    void build(const string &s){
        int n = s.size();
        h = p = vector<ll>(n+1); p[0] = 1;
        for(int i=1; i<=n; i++) h[i] = (h[i-1] * P + s[i-1]) % M;
        for(int i=1; i<=n; i++) p[i] = p[i-1] * P % M;
    }
    ll get(int s, int e) const {
        ll res = (h[e] - h[s-1] * p[e-s+1]) % M;
        return res >= 0 ? res : res + M;
    }
};

template<ll P1, ll M1, ll P2, ll M2> struct DoubleHashing {
    Hashing<P1, M1> H1;
    Hashing<P2, M2> H2;

    void build(const string &s) {
        H1.build(s);
        H2.build(s);
    }
    ll get(int s, int e) const {
        return H1.get(s, e) * M2 + H2.get(s, e);
    }
};
