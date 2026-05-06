class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.size()!= t.size()) return false;
    vector<char> chars(s.begin(), s.end());
    vector<char> chart(t.begin(), t.end());
    sort(chars.begin(), chars.end());
    sort(chart.begin(), chart.end());
    for (int i =0; i<chars.size(); i++){
        if(chars[i]!=chart[i]){
            return false;
        }
        
    }
    return true;
    }
};
