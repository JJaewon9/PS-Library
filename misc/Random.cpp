ll rand_int(ll s,ll e){ // [s,e]
    static random_device rd;
    static mt19937 gen(rd());
    return uniform_int_distribution<ll>(s,e)(gen);
}
