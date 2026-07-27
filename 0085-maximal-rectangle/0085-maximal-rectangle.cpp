class Solution {
public:

vector<int> getnsr(vector<int>&height){

    int n=height.size();
    stack<int> st;

    vector<int>nsr(n);

    nsr[n-1]=n;
    st.push(n-1);    // stack will store the indexes

    for (int i=n-2;i>=0;i--){
        while(!st.empty() && height[i]<=height[st.top()]){
            st.pop();
        }
        if (st.empty()){
            nsr[i]=n;
            //st.push(i);

        }
        else {
            nsr[i]=st.top();
            //st.push(i);
        }
        st.push(i);
    }
    return nsr;
}

vector<int> getnsl(vector <int>&height){

    int n=height.size();
    stack <int> st;
    vector <int> nsl(n);
    nsl[0]=-1;
    st.push(0);
    for (int i=1;i<n;i++){
        while(!st.empty() && height[i]<=height[st.top()]){
            st.pop();
        }
        if (st.empty()){
            nsl[i]=-1;
        }
        else {
            nsl[i]=st.top();
        }
        st.push(i);
    }
    return nsl;
}

int findmaxarea(vector<int>&height){

    // width and height so for width we need to find nsr and nsl

    vector<int>nsr=getnsr(height);

    vector<int>nsl=getnsl(height);

    int n=height.size();

    vector<int> width(n);
    
    for (int i=0;i<n;i++){
        width[i]=nsr[i]-nsl[i]-1;
    }
    int maxarea=0;
    for (int i=0;i<n;i++){
        int a=width[i]*height[i];

        maxarea=max(maxarea,a);
    }
    return maxarea;
}


    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();    // row calculate
        int m=matrix[0].size();   // column calculate
        vector <int> height(m);
        for (int i=0;i<m;i++){
            height[i]=matrix[0][i]=='1'?1:0; 
        }
        int maxarea=findmaxarea(height);

        for (int row=1;row<n;row++){
            for (int column=0;column<m;column++){
                if (matrix[row][column]=='0'){
                    height[column]=0;
                }
                else {
                    height[column]=height[column]+1;
                }
            }
            maxarea=max(maxarea,findmaxarea(height));
        }
        return maxarea;
    }
};