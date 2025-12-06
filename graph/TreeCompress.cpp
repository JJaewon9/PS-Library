//in[i]: euler tour idx, lca 전처리 필요
void treeComp(vector<int>& v){
    sort(all(v),[&](int a,int b){ return in[a]<in[b]; });
    int sz=v.size();
    for(int i=1;i<sz;i++) v.push_back(lca(v[i-1],v[i]));
    sort(all(v),[&](int a,int b){ return in[a]<in[b]; });
    v.erase(unique(all(v)),v.end());
    sz=v.size();
    for(int i=1;i<sz;i++){
        int p=lca(v[i-1],v[i]);
        vG[p].push_back({v[i],dist[v[i]]-dist[p]});
        vG[v[i]].push_back({p,dist[v[i]]-dist[p]});
    }
    ...
}
