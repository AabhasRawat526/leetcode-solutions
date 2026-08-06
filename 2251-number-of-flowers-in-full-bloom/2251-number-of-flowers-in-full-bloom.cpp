class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
        int m=people.size();
        vector <int> start_time(n);
        vector <int> end_time(n);

        for (int i=0;i<n;i++){
            start_time[i]=flowers[i][0];
            end_time[i]=flowers[i][1];
        }
        sort(start_time.begin(),start_time.end());
        sort(end_time.begin(),end_time.end());

        vector <int> result;

        for (int i=0;i<m;i++){

            int bloomed=upper_bound(start_time.begin(),start_time.end(),people[i])-(start_time.begin());

            int died=lower_bound(end_time.begin(),end_time.end(),people[i])-(end_time.begin());

            int validflowers=bloomed-died;

            result.push_back(validflowers);
        }

        return result;
    }
};