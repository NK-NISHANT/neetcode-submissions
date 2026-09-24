class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> idx;
        vector<int> days(temp.size(),0);

        for(int i = 0; i<temp.size(); i++){
            while(!idx.empty() && temp[i]>temp[idx.top()]){
                days[idx.top()] = i - idx.top();
                idx.pop();
            }
            idx.push(i);
        }
        return days;
    }
};