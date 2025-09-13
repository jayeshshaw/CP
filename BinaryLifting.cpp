const int LOG = 20; // supports up to 2^20 ~ 1e6 nodes
vector<vector<int>> up; // binary lifting table
vector<int> depth;

// Precompute binary lifting table
void preprocess(int n, const vector<int>& parent) {
    up.assign(n, vector<int>(LOG, -1));
    depth.assign(n, 0);

    // Initialize immediate parent (2^0 ancestor)
    for (int v = 0; v < n; v++) {
        up[v][0] = parent[v];
        if (parent[v] != -1)
            depth[v] = depth[parent[v]] + 1;
    }

    // Precompute ancestors for powers of two
    for (int j = 1; j < LOG; j++) {
        for (int v = 0; v < n; v++) {
            if (up[v][j-1] != -1) {
                up[v][j] = up[up[v][j-1]][j-1];
            }
        }
    }
}

// Lift node u up by k steps
int lift(int u, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            u = up[u][j];
            if (u == -1) break;
        }
    }
    return u;
}

// Query LCA
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // Lift u up to same depth as v
    u = lift(u, depth[u] - depth[v]);
    if (u == v) return u;

    // Lift both simultaneously until just before LCA
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0]; // parent of either is LCA
}

// Example driver
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; // number of nodes
    vector<int> parent(n);
    for (int i = 0; i < n; i++) cin >> parent[i]; // parent[i], -1 for root

    preprocess(n, parent);

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}
