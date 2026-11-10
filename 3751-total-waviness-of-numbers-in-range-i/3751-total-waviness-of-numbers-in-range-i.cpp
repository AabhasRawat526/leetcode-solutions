class Solution {
public:

int findwaviness(string s){
    int answer=0;
    for (int i=1;i< s.size()-1;i++){
        if (s[i] > s[i+1] && s[i] > s[i-1]){
            answer++;
        }
        if (s[i] < s[i+1] && s[i] < s[i-1]){
            answer++;
        }
    }
    return answer;
}

    int totalWaviness(int num1, int num2) {
        if (num1 < 100 && num2 < 100){
            return 0;
        }
        int score=0;
        for (int num=num1;num<=num2;num++){   // tc is 0(num2-num1) outer loop inside loop 0(log10(num))     traversing digit and the digit is 0(log10(num))   .. ... . .. 
            string s=to_string(num);
            score=score+findwaviness(s);
        }
        return score;
    }
};
