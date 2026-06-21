mint fact[10000010],factInv[10000010];
void precalc(int MX){
    fact[0]=1;
    for(int i=1;i<=MX;i++) fact[i]=fact[i-1]*i;
    factInv[MX]=mint(1)/fact[MX];
    for(int i=MX-1;i>=0;i--) factInv[i]=factInv[i+1]*(i+1);
}
mint choose(int n,int r){
    if(r<0||r>n) return 0;
    return fact[n]*factInv[r]*factInv[n-r];
}
