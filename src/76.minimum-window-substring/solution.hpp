class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        int i = 0, j = 0;
        unordered_map<char, int> need, window;
        int nSatisfy = 0;
        int start = 0;
        for (char c: t)
            need[c]++;
        while(j < s.size()) {
            char c = s[j];
            j++;
            if (need.count(c)) {
                window[c]++; 
                if (window[c] == need[c])
                    nSatisfy++;
            }
            while (nSatisfy == need.size()) {
                c = s[i];
                if (need.count(c)) {
                    int len = j - i;
                    if (len < minLen) {
                        minLen = len;
                        start = i;
                    }
                    if (window[c] == need[c])
                        nSatisfy--;
                    window[c]--;
                }
                i++;
            }
        }
        return minLen == INT_MAX? "": s.substr(start, minLen);
    }
};
