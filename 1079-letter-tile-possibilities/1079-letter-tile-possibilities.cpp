class Solution {
public:

/*
int n;

void solve(string & tiles,unordered_set<string>& result,vector<bool>& used,string res){
    result.insert(res);
    for (int i=0;i<n;i++){
        if (used[i]){
            continue;
        }
        used[i]=true;   // exploring
        res.push_back(tiles[i]); // entering
        solve(tiles,result,used,res);
        used[i]=false;
        res.pop_back();
    }
}
    int numTilePossibilities(string tiles) {
      n=tiles.size();
      unordered_set<string>result;
      vector<bool>used(26,false);
      string res="";
      solve(tiles,result,used,res);
      return result.size()-1;  
    */
    int totalcount=0;
    int n;
    void solve(vector<int>& result){
        totalcount++;
        for (int i=0;i<26;i++){
            if (result[i]==0){
                continue;
            }
            result[i]--;
            solve(result);
            result[i]++;
        }
    }
     int numTilePossibilities(string tiles) {
        n=tiles.size();
        vector<int>result(26);
        for (int i=0;i<n;i++){
            result[tiles[i]-'A']++;
        }
        solve(result);
        return totalcount-1;
    }
};