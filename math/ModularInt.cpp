using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t; // available on 64-bit targets
template <typename T, auto &M> struct Mod {
  using V = conditional_t<sizeof(T) <= 4, u64, u128>;
  static V inv(V x, V m) { return x > 1 ? m - inv(m % x, x) * m / x : 1; }
  make_unsigned_t<T> x;
  Mod() : x(0) {}
  template <typename U> Mod(U y) : x(y % M) { x >= M ? x += M : x; }
  operator T() const { return x; }
  Mod operator-() const { return Mod() -= *this; }
  template <typename U> Mod operator+(U rhs) const { return Mod(*this) += rhs; }
  template <typename U> Mod operator-(U rhs) const { return Mod(*this) -= rhs; }
  template <typename U> Mod operator*(U rhs) const { return Mod(*this) *= rhs; }
  template <typename U> Mod operator/(U rhs) const { return Mod(*this) /= rhs; }
  Mod &operator+=(Mod rhs) { return (x += rhs.x) >= M ? x -= M : x, *this; }
  Mod &operator-=(Mod rhs) { return (x -= rhs.x) >= M ? x += M : x, *this; }
  Mod &operator*=(Mod rhs) { return x = x * V(rhs.x) % M, *this; }
  Mod &operator/=(Mod rhs) { return x = x * inv(rhs.x, M) % M, *this; }
  template <typename U> Mod pow(U y) const { // O(log y) | 0^(-inf,0] -> 1
    Mod ans(1), base(*this);
    for (auto e = y < 0 ? ~y + u128(1) : +y; e; e >>= 1, base *= base) {
      e & 1 ? ans *= base : ans;
    }
    return y < 0 ? Mod(1) /= ans : ans;
  }
};
template <typename T> struct Barrett {
  static inline conditional_t<sizeof(T) <= 4, u64, u128> m, u;
  static void set(T y) { m = y, u = -1 / m; } // u = 2^(16*sizeof(T))/m
  operator T() const { return m; }
  static auto div(u128 x) {
    if constexpr (sizeof(T) <= 4) {
      return u64(x * u >> 64);
    } else {
      u128 xl = u64(x), ul = u64(u), xh = x >> 64, uh = u >> 64;
      auto a = xl * ul, b = xl * uh, c = ul * xh, d = xh * uh;
      return d + (b >> 64) + (c >> 64) + (((a >> 64) + u64(b) + u64(c)) >> 64);
    }
  }
  template <typename U, typename = enable_if_t<sizeof(U) <= sizeof(u)>>
  friend U operator/(U x, Barrett) {
    auto q = x < 0 ? ~div(~x + u128(1)) : div(x);
    return q + (x < 0 ? x > q * m : x >= (q + 1) * m);
  }
  template <typename U, typename = enable_if_t<sizeof(U) <= sizeof(u)>>
  friend U operator%(U x, Barrett) {
    auto q = x < 0 ? ~div(~x + u128(1)) : div(x);
    return x -= q * m, x < 0 || x < m ? x : x - m;
  }
};
/*
1. fixed modular
constexpr int MOD=1000000007;
using mint=Mod<int,MOD>;
2. arbitrary modular
Barrett<int> DynamicMod;
using mint=Mod<int,DynamicMod>;
DynamicMod.set(m);
*/
