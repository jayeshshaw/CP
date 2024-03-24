const int N=1e5;
vector<int> fen(N,0);
void update(int val,int i){while(i<fen.size()){fen[i]+=val;i=i+(i&(-i));}}
int sum(int i){int sm=0;while(i>0){sm+=fen[i];i=i-(i&(-i));}return sm;}
int find(int k){int n=fen.size();int curr=0,ans=0,prevsum=0;for(int i=log2(n);i>=0;i--){if(fen[curr+(1<<i)]+ prevsum<k){curr=curr+(1<<i);prevsum+=fen[curr];}}return curr+1;}


