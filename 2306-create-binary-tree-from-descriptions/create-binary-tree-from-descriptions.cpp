class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {

        int r = 0;
        unordered_map<int,TreeNode*> nodes;

        for(auto &i : arr){
            if(nodes.find(i[0])==nodes.end()){
                TreeNode* parent = new TreeNode(i[0]);
                nodes[i[0]]=parent;
                r^=i[0];
            }
        }

        for(auto &i : arr){
            r^=i[1];

            if(nodes.find(i[1]) == nodes.end()){
                r^=i[1];
                TreeNode* child = new TreeNode(i[1]);
                if(i[2]) nodes[i[0]]->left = child;
                else nodes[i[0]]->right = child;
            }
            
            else{
                if(i[2]) nodes[i[0]]->left = nodes[i[1]];
                else nodes[i[0]]->right = nodes[i[1]];
            }
        }


        return nodes[r];
    }
};