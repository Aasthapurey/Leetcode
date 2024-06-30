class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
    int count()
    {
        int ans = 0;
        for(int i=0 ; i<parent.size() ; i++)
        {
            ans += (parent[i] == i);
        }
        return ans;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        UnionFind dsu_a(n), dsu_b(n);
        int remove_cnt = 0;

        for(auto &edge: edges)
        {
            if(edge[0] == 3)
            {
                if(dsu_a.find(edge[1]-1) != dsu_a.find(edge[2]-1))
                {
                    dsu_a.union_set(edge[1]-1, edge[2]-1);
                    dsu_b.union_set(edge[1]-1, edge[2]-1);
                }else
                {
                    remove_cnt++;
                }
            }
        }
        for(auto &edge: edges)
        {
            if(edge[0] == 1)
            {
                if(dsu_a.find(edge[1]-1) != dsu_a.find(edge[2]-1))
                {
                    dsu_a.union_set(edge[1]-1, edge[2]-1);
                }else
                {
                    remove_cnt++;
                }
            }
        }
        for(auto &edge: edges)
        {
            if(edge[0] == 2)
            {
                if(dsu_b.find(edge[1]-1) != dsu_b.find(edge[2]-1))
                {
                    dsu_b.union_set(edge[1]-1, edge[2]-1);
                }else
                {
                    remove_cnt++;
                }
            }
        }
        // cout << dsu_a.count() << " " << dsu_b.count() << "\n";
        if(dsu_a.count() > 1 || dsu_b.count() > 1) return -1;
        return remove_cnt;
    }
};