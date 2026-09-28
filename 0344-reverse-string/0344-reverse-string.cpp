class Solution {
public:
    void reverseString(vector<char>& s) {
        /*
        int n=s.size();
        int j=n-1;
        int i=0;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        s;
        */
        stack<char>st;
        int n=s.size();
        for (int i=0;i<n;i++){
            st.push(s[i]); 
        }
        int j=0;
        while(!st.empty()){
            s[j]=st.top();
            st.pop();
            j++;
        }
        s;
    }
};