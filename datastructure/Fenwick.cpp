struct Fenwick{ // 1-based!!!!!!!!!!!!!!!!
    vector<ll> tree;
    Fenwick(int n):tree(n+1){}
    void update(int p,ll v){
        while(p<tree.size()){
            tree[p]+=v;
            p+=(p&-p);
        }
    }
    ll sum(int p){
        ll ret=0;
        while(p){
            ret+=tree[p];
            p-=(p&-p);
        }
        return ret;
    }
    ll query(int s,int e){ return sum(e)-sum(s-1); }
};
