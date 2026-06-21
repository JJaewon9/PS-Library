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

//combination prefix sum
vector<vector<mint>> cache;
int BUC;
void cachePrecalc(int MX){
    BUC=sqrt(MX+1);
    cache.resize(MX/BUC+1);
    for(int i=0;i*BUC<=MX;i++){
        cache[i].resize(MX+1);
        for(int j=0;j<=MX;j++){
            if(j>0) cache[i][j]=cache[i][j-1];
            cache[i][j]+=choose(i*BUC,j);
        }
    }
}
mint combPsum(int n,int x){ // C(n,0) + ... + C(n,x)
    if(x<0) return 0;
    int q=n/BUC,r=n%BUC;
    mint ret=0;
    for(int i=0;i<=min(r,x);i++) ret+=choose(r,i)*cache[q][x-i];
    return ret;
}
