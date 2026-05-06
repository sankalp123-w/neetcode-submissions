class Solution {
public:
    bool isPalindrome(string s) {
    string destStr;
    for (char c : s) {
        if (isalnum(c)) {
            destStr += c;
        }
    }

    int i=0,j=destStr.size()-1;
    while(i<=j){
    cout<<i<<j;
    if(tolower(destStr[i])!=tolower(destStr[j])) return false;    
        j--;
        i++;
    }
    return true;
    }
};
