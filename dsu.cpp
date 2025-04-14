#include<bits/stdc++.h>
using namespace std;


class DSU{
   vector<int> rank, par, size;
public:
   DSU(int n){
       rank.resize(n+1,0);size.resize(n+1,1);
       par.resize(n+1);
       for(int i=0;i<=n;i++)par[i]=i;
   }


   int findPar(int node){
       if(node==par[node])
           return node;
       return par[node] = findPar(par[node]);
   }


   //false if already in same component
   bool unionByRank(int a, int b){
       int u = findPar(a);
       int v = findPar(b);
       if(u == v)return false;


       if(rank[u]<rank[v])
           par[u] = v;
       else if(rank[u]>rank[v])
           par[v] = u;
       else
           par[u]=v, rank[v]++;
       return 1;
   }


   bool unionBySize(int a, int b){
       int u = findPar(a);
       int v = findPar(b);
       if(u == v)return false;
       if(size[u]<size[v])
           par[u]=v, size[v]+=size[u];
       else
           par[v]=u, size[u]+=size[v];
       return 1;
   }
};
DSU d(7); d.unionByRank(2,5);


