// range add update, range max query
int lazy[1<<21],tree[1<<21];
void push(int p,int s,int e){
    tree[p]+=lazy[p];
    if(s!=e){
        lazy[p*2]+=lazy[p];
        lazy[p*2+1]+=lazy[p];
    }
    lazy[p]=0;
}
int query(int p,int s,int e,int l,int r){
    push(p,s,e);
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return tree[p];
    int m=(s+e)/2;
    int lRes=query(p*2,s,m,l,r),rRes=query(p*2+1,m+1,e,l,r);
    return max(lRes,rRes);
}
void update(int p,int s,int e,int l,int r,int v){
    push(p,s,e);
    if(r<s||e<l) return;
    if(l<=s&&e<=r){
        lazy[p]+=v;
        push(p,s,e);
        return;
    }
    int m=(s+e)/2;
    update(p*2,s,m,l,r,v); update(p*2+1,m+1,e,l,r,v);
    tree[p]=max(tree[p*2],tree[p*2+1]);
}
