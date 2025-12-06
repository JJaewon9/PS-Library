struct Line {
	ll a, b;
	Line(ll a = 0, ll b = 0) : a(a), b(b) {}
	bool operator<= (const Line& i) const { return (__int128_t)a * i.b <= (__int128_t)i.a * b; }
};
ll F(const Line& i, ll a) { return i.a * a + i.b; }
Line C(const Line& a, const Line& b) { return { a.b - b.b, b.a - a.a }; }
struct CHT {
	vector<Line> S; int pos = 0;
	void Insert(Line l) {
        if(S.size() > pos && S.back().a == l.a){
            if(l.b < S.back().b) l = S.back(); // max: <=, min: >=
            S.pop_back();
        }
		while (S.size() > 1 && C(S.back(), l) <= C(S[S.size() - 2], S.back())) S.pop_back();
		S.push_back(l);
	}
    ll Query(ll x) {
		int lo = 0, hi = S.size();
		while (lo + 1 < hi) {
			const int mid = lo + hi >> 1;
			if (C(S[mid - 1], S[mid]) <= Line(x, 1)) lo = mid; 
			else hi = mid;
		}
		return F(S[lo], x);
	}
    ll Query2(ll x) {     // x좌표 단조증가
        if(S.empty()) return -LINF;
		while (pos + 1 < S.size() && F(S[pos], x) <= F(S[pos + 1], x)) pos++; // max: <=, min >=
		return F(S[pos], x);
	}
};

// Linecontainer start (max query)
struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
}; // (for doubles, use inf = 1/.0, div(a,b) = a/b)
struct LineContainer : multiset<Line, less<>> {
  static const ll inf = LLONG_MAX;
  ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // floor
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
  }
  ll query(ll x) { assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};
