class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";

        if(s.size() < t.size()) return ans;

        if(t.size() == 1){
            for(int i = 0; i < s.size(); i++){
                if(s[i] == t[0]){
                    return string(1, s[i]);
                }
            }
            return ans;
        }

        map<char,int> mt;
        int needed = 0;

        for(int i = 0; i < t.size(); i++){
            if(mt.count(t[i]))
                mt[t[i]]++;
            else{
                mt[t[i]] = 1;
                needed++;
            }
        }

        map<char,int> ms;

        int left = 0, formed = 0;

        int bestStart = 0;
        int bestLength = s.size() + 1;

        for(int right = 0; right < s.size(); right++){

            if(mt.count(s[right])){
                ms[s[right]]++;

                if(ms[s[right]] == mt[s[right]])
                    formed++;
            }

            while(formed == needed){

                int windowLength = right - left + 1;

                if(windowLength < bestLength){
                    bestLength = windowLength;
                    bestStart = left;
                }

                if(mt.count(s[left])){
                    ms[s[left]]--;

                    if(ms[s[left]] < mt[s[left]])
                        formed--;
                }

                left++;
            }
        }

        if(bestLength == s.size() + 1)
            return "";

        return s.substr(bestStart, bestLength);
    }
};