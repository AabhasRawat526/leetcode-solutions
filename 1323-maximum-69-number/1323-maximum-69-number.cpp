class Solution {
public:
    int maximum69Number (int num) {
        int placevalue=0;
        int placevaluetosix=-1;
        int temp=num;
        while(temp > 0){
            int remainder=temp%10;
            if (remainder==6){
                placevaluetosix=placevalue;
            }
            temp=temp/10;
            placevalue++;
        }
        if (placevaluetosix == -1){
            return num;
        }
        return num + 3*pow(10,placevaluetosix);
    }
};