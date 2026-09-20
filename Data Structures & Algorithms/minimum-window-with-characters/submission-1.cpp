class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> need, window;

        int required = 0;

        for(char c : t) {
            if(need[c] == 0) required++;
            need[c]++;
        }

        int left = 0;
        int formed = 0;

        int bestStart = 0;
        int bestLength = INT_MAX;

        for(int right = 0; right < s.size(); right++) {

            if(need.count(s[right])) {
                window[s[right]]++;

                if(window[s[right]] == need[s[right]])
                    formed++;
            }

            while(formed == required) {

                int windowLength = right - left + 1;

                if(windowLength < bestLength) {
                    bestLength = windowLength;
                    bestStart = left;
                }

                if(need.count(s[left])) {
                    window[s[left]]--;

                    if(window[s[left]] < need[s[left]])
                        formed--;
                }

                left++;
            }
        }

        if(bestLength == INT_MAX) return "";

        return s.substr(bestStart, bestLength);
    }
};