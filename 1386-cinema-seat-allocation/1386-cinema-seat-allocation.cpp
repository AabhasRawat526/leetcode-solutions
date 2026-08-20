class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        /*
        int m=reservedSeats.size();
        unordered_map<int,unordered_set<int>> f;
        for (int i=0;i<m;i++){
            int row=reservedSeats[i][0]; 
            int seats=reservedSeats[i][1];

            f[row].insert(seats);   // Put seat 2 into row 1's reserved-seat set.
        }

        int result=0;
        if (n-f.size()>0){
            result=result+(n-f.size())*2;
        }

        for (auto [rows,bookedSeats] : f){

            auto isAvailable=[&](int seats){
                return bookedSeats.find(seats)== bookedSeats.end();
            };


            bool groupa=isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);

            bool groupb=isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);

            bool groupc=isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9); 


            if (groupa && groupc){
                result=result+2;
            }
            else if (groupa || groupb || groupc){
                result=result+1;
            }
        }
        return result;

        */

        int m=reservedSeats.size();
        unordered_map<int,int> f;
        int result=0;
        for (int i=0;i<m;i++){
            int rows=reservedSeats[i][0];
            int seats=reservedSeats[i][1];

            f[rows]= f[rows] | (1<<seats);
        }

        if(n-f.size()>0){
            result=result+(n-f.size())*2;
        }

        int maskA=((1<<2) | (1<<3) | (1<<4) | (1<<5));
        int maskB=((1<<4) | (1<<5) | (1<<6) | (1<<7));
        int maskC=((1<<6) | (1<<7) | (1<<8) | (1<<9));

        for (auto [rows,bookedSeats] : f){

            bool groupA = (bookedSeats & maskA)==0;
            bool groupB= (bookedSeats & maskB)==0;
            bool groupC= (bookedSeats & maskC)==0;

            if (groupA && groupC){
                result=result+2;
            }
            else if (groupA || groupB || groupC){
                result=result+1;
            }
        }
        return result;
    }
};