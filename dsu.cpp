#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int p[N];
int node[N];

void make(int v){p[v]=v;node[v]=1;}

int find(int x){return (x==p[x]?x:(p[x]=find(p[x])));}

bool join(int a, int b){
  a=find(a);b=find(b); 
  if(a==b)return 0; 
  if(node[a]<node[b])swap(a,b); 
  p[a]=b;node[a]+=node[b];
  return 1;
}

