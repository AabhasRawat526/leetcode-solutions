class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        multiset<int>leftside;      // stores the smaller element always greater than or bigger than rightside by one 
        multiset<int>rightside;    // stores the bigger element
        vector<double>res;
        while(j<n){
            if (leftside.empty() || nums[j] <= *leftside.rbegin()){
                leftside.insert(nums[j]);
            }
            else {
                rightside.insert(nums[j]);
            }
            if (leftside.size() > rightside.size() + 1){
                rightside.insert(*leftside.rbegin());
                leftside.erase(prev(leftside.end()));
            }
            else if (rightside.size() > leftside.size()){
                leftside.insert(*rightside.begin());
                rightside.erase(rightside.begin());
            }

            if (j-i+1 == k){
                if (k%2==1){
                    res.push_back(*leftside.rbegin());
                }
                else {
                    double a = *leftside.rbegin();
                    double b = *rightside.begin();
                    res.push_back((a+b)/2);
                }
                if (leftside.find(nums[i])!=leftside.end()){
                    leftside.erase(leftside.find(nums[i]));
                }
                else {
                    rightside.erase(rightside.find(nums[i]));
                }
                i++;

                if (leftside.size() > rightside.size() + 1){
                    rightside.insert(*leftside.rbegin());
                    leftside.erase(prev(leftside.end()));
                }
                else if (rightside.size() > leftside.size()){
                    leftside.insert(*rightside.begin());
                    rightside.erase(rightside.begin());
                }
            }
            j++;
        }
        return res;
    }
};