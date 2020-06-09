class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<pair<int, int>> st;
        for (string log: logs) {
            int p1 = log.find(':');
            int p2 = log.rfind(':');
            int id = stoi(log.substr(0, p1));
            string action = log.substr(p1 + 1, p2 - p1 - 1);
            int ts = stoi(log.substr(p2 + 1));
            if (action == "start") st.push(make_pair(id, ts));
            else {
                int dur = ts - st.top().second + 1;
                result[id] += dur;
                st.pop();
                if (!st.empty()) result[st.top().first] -= dur;
            }
        }
        return result;
    }
};
