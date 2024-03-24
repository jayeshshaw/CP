#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> adj(n);
        for(auto i: roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<ll> dist(n,LLONG_MAX);
        vector<ll> cnt(n,0);
        
        multiset<pair<ll,ll>> m;
        dist[0]=0;
        cnt[0]=1;
        m.insert({0,0});
        
        while(!m.empty()){
            auto it=*m.begin();
            ll dis=it.first;
            ll node=it.second;
            m.erase(m.begin());
            if(dist[node]<dis)continue;
            
            for(auto x: adj[node]){
                ll adjNode=x.first;
                ll adjDist=x.second;
                
                if(adjDist+dis< dist[adjNode]){
                    dist[adjNode]=adjDist+dis;
                    m.insert({dist[adjNode],adjNode});
                    cnt[adjNode] = cnt[node];
                }
                else if(adjDist+dis==dist[adjNode]){
                    cnt[adjNode]=(cnt[adjNode] + cnt[node])%MOD;
                }
            }
        }
        return cnt[n-1];
        
    }
};