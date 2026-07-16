#include <bits/stdc++.h>
using namespace std;

struct Disjoint {
    vector<int> parent, size;

    Disjoint(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findparent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findparent(parent[node]);
    }

    void unite(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0, maxcol = 0;

        for(auto &s : stones) {
            maxrow = max(maxrow, s[0]);
            maxcol = max(maxcol, s[1]);
        }

        Disjoint ds(maxrow + maxcol + 2);

        unordered_map<int,int> used;

        for(auto &s : stones) {
            int r = s[0];
            int c = s[1] + maxrow + 1;

            ds.unite(r, c);

            used[r] = 1;
            used[c] = 1;
        }

        int components = 0;

        for(auto &e : used) {
            if(ds.findparent(e.first) == e.first) {
                components++;
            }
        }

        return stones.size() - components;
    }
};