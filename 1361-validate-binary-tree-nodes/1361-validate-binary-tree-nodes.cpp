class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>>adj;   // int contains the parent and the vector<int> contains the children of the parent
        unordered_map<int,int>child_to_parent; // contains the parent and children
        for (int i=0;i<n;i++){
            int node=i;
            int leftchild=leftChild[i];
            int rightchild=rightChild[i];
            if (leftchild!=-1){
                adj[node].push_back(leftchild);
                if (child_to_parent.find(leftchild)!=child_to_parent.end()){
                    return false;
                }
                else {
                    child_to_parent[leftchild]=i;
                }
            }
            if (rightchild!=-1){
                adj[node].push_back(rightchild);
                if (child_to_parent.find(rightchild)!=child_to_parent.end()){
                    return false;
                }
                else {
                    child_to_parent[rightchild]=i;
                }
            }
        }
        int root=-1;
        for (int i=0;i<n;i++){
            if (child_to_parent.find(i)==child_to_parent.end()){
                if (root!=-1){
                    return false;
                }
                root=i;
            }
        }
        if (root==-1){
            return false;
        }

        // TRAVERSING 
        // BFS 
        int count=0;
        queue<int>q;
        vector<bool>visited(n , false);
        q.push(root);
        count=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for (int &v : adj[node]){
                if (!visited[v]){
                    visited[v]=true;
                    count++;
                    q.push(v);
                }
            }
        }
        return (n==count);
    }
};