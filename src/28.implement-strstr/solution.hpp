class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; ; i++) {
            for (int j = 0; ; j++) {
                if (j == needle.size()) return i;
                if (i + j == haystack.size()) return -1;
                if (needle[j] != haystack[i + j]) break;
            }
        }
    }

    int strStr2(string haystack, string needle) {
        int l1 = haystack.size(); int l2 = needle.size();
        if (l1 < l2) return -1;
        else if (l2 == 0) return 0;
        for(int p = 0; p < l1; ) {
            auto iBegin = haystack.begin();
            if (equal(iBegin + p, iBegin + p + l2, needle.begin()))
                return p;
            else
                p = p + l2 - needle.find_last_of(haystack[p + l2]);
        }
        return -1;
    }
};
