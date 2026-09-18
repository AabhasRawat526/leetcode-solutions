class Solution {
public:

vector<int> solve(string expression){
    vector<int>res;
    int n=expression.size();
    for (int i=0;i<n;i++){
        if (expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
            vector<int> left_sum=solve(expression.substr(0,i));
            vector<int> right_sum=solve(expression.substr(i+1));
            for (int x:left_sum){
                for (int y:right_sum){
                    if (expression[i]=='+'){
                        res.push_back(x+y);
                    }
                    else if (expression[i]=='-'){
                        res.push_back(x-y);
                    }
                    else {
                        res.push_back(x*y);
                    }
                }
            }
        }
    }
    // if there is no operation this means that there must be a number 
    if (res.empty()){
        res.push_back(stoi(expression));
    }
    return res;
}

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};