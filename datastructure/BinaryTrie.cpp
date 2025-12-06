struct BTRIE{
    vector<int> ch[2],sz;
    BTRIE(){
        ch[0].push_back(-1);
        ch[1].push_back(-1);
        sz.push_back(0);
    }
    void add(int x){
        int curr=0;
        for(int i=30;i>=0;i--){
            int b=(x>>i)&1;
            if(ch[b][curr]==-1){
                ch[0].push_back(-1);
                ch[1].push_back(-1);
                sz.push_back(0);
                ch[b][curr]=(int)sz.size()-1;
            }
            curr=ch[b][curr];
            sz[curr]++;
        }
    }
    int query(int x){ // xor min
        int curr=0,ret=0;
        for(int i=30;i>=0;i--){
            int b=(x>>i)&1;
            if(ch[b][curr]!=-1) curr=ch[b][curr];
            else ret|=(1<<i),curr=ch[b^1][curr];
        }
        return ret;
    }
