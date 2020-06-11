/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
private:
    bool isDigit(char& c) {
        return isdigit(c) || c == '-';
    }
    NestedInteger deserializeInterger(stringstream &ss) {
        int value;
        ss >> value;
        return NestedInteger(value);
    }
    NestedInteger deserializeList(stringstream &ss) {        
        NestedInteger ni;
        char c;
        ss >> c; // [
        while ((c = ss.peek()) != ']') {            
            if (isDigit(c)) {
                ni.add(deserializeInterger(ss));
            } else if (c == '[') {
                ni.add(deserializeList(ss));
            } else {
                // just ignore
                ss >> c;
            }
        }
        ss >> c; // ]
        return ni;
    }
public:
    // 字符流解析
    NestedInteger deserialize(string s) {
        stringstream ss(s);
        char c = ss.peek();
        NestedInteger ni;
        if (isDigit(c)) {    
            ni = deserializeInterger(ss);
        } else {
            ni = deserializeList(ss);
        }
        return ni;
    }

    NestedInteger deserialize1(string s) {
        if (isdigit(s[0]) || '-' == s[0]) return NestedInteger(stoi(s));

        NestedInteger result;
        stack<NestedInteger*> st;
        int num = 0, d = 0, sig = 1;
        for (auto c: s) {
            if (c == '-') sig = -1;
            else if (isdigit(c)) {
                num = num * 10 + c - '0';
                d++;
            }
            else {
                if (d > 0) {
                    st.top()->add(NestedInteger(sig * num));
                    num = 0, d = 0, sig = 1;
                }
                if (c == '[')
                    st.push(new NestedInteger());
                else if (c == ']') {
                    NestedInteger *res = st.top();
                    st.pop();
                    if (st.empty()) return *res; 
                    else st.top()->add(*res);
                }
            }
        }
        return NestedInteger();
    }
};
