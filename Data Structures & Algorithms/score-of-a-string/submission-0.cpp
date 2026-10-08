class Solution {
public:
    int score=0;
    int scoreOfString(string s) {
        for(int i=0;i<s.size()-1;i++){
            score+=abs(s[i]-s[i+1]);
        }
        return score;
    }
};