class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int column=matrix[0].size();
        int left=0;
        int right=(row*column)-1;
        while(left<=right){
            int guess =(left+right)/2;
            if (matrix[guess/column][guess%column] > target){
                right=guess-1;
            }
            else if (matrix[guess/column][guess%column] < target){
                left=guess+1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};