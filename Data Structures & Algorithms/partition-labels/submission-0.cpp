class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]=i;
        }
        int end_marker = -1;
        int count = 0;
        for(int i=0;i<s.size();i++){
            end_marker = max(m[s[i]],end_marker);
            count++;
            if(i==end_marker){
                ans.push_back(count);
                count = 0;
            }
        }
        return ans;
    }
};
