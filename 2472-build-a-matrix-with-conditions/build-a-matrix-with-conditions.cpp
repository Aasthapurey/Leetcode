class Solution {
private:
    vector<int> TopoSort(int k, vector<vector<int>>& adj)
    {
        vector<int> indegree(k+1, 0);
        for(int node=1; node<=k; node++)
            for(auto it : adj[node])
                indegree[it]++;

        queue<int> q;
        vector<int> vis(k+1, 0);
        for(int node=1; node<=k; node++)
            if(indegree[node]==0)
                q.push(node);

        vector<int> ans;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                int node = q.front();
                q.pop();

                vis[node] = true;
                ans.push_back(node);

                for(auto it : adj[node])
                {
                    if(!vis[it])
                    {
                        indegree[it]--;
                        if(indegree[it]==0) 
                            q.push(it);
                    }
                }
            }
        }

        vector<int> notTopo;
        for(int node=1; node<=k; node++) 
            if(indegree[node] != 0) 
                return notTopo;
        return ans;
    }

    void fillTopoArray(int k, vector<int>& arr)
    {
        unordered_map<int, bool> mp;
        for(auto it : arr) 
            mp[it] = true;

        for(int i=1; i<=k; i++)
            if(!mp[i]) 
                arr.push_back(i);
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        int n=rowConditions.size(),m=colConditions.size();

        vector<vector<int>> adjRow(k+1);
        vector<vector<int>> adjCol(k+1);

        for(auto it: rowConditions)
            adjRow[it[0]].push_back(it[1]);
        
        for(auto it: colConditions)
            adjCol[it[0]].push_back(it[1]);

        //Apply Toposort

        vector<int> rowTopo=TopoSort(k,adjRow);
        vector<int> colTopo=TopoSort(k,adjCol);
        vector<vector<int>> ans;

        //Base case
        if(rowTopo.size()==0 || colTopo.size()==0)
            return ans;
        

        fillTopoArray(k, rowTopo);
        fillTopoArray(k, colTopo);

        unordered_map<int, int> mp;
        for(int j=0; j<k; j++)
            mp[colTopo[j]] = j;

        ans = vector<vector<int>>(k, vector<int>(k, 0));
        for(int i=0; i<k; i++)
            ans[i][mp[rowTopo[i]]] = rowTopo[i];
        
        return ans;        
    }
};