class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        unordered_map<int,int>f;
        for (int i=0;i<n;i++){
            f[tasks[i]]++;
        }
        int round=0;
        for (auto &it:f){
            int count=it.second;
            if (count==1){
                return -1;
            }
            if (count % 3 ==0){
                round=round+(count/3);     
            }
            else {
                round=round + (count/3)+1;    // work for both 3k+1 and for 3k+2 one too so that is why no need to do k/3 + 1 and k/3 + 2 respectively this formula is doing the work of both cases ....
            }
        }
        return round;
    }
};