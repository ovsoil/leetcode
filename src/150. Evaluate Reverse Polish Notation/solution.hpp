class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        for(auto token: tokens) {
            if ( token == "+" || token == "-" || token == "*" || token == "/" ) {
                auto rh = s.top(); s.pop();
                auto lh = s.top(); s.pop();
                if ( token == "+") s.push(lh + rh);
                if ( token == "-") s.push(lh - rh);
                if ( token == "*") s.push(lh * rh);
                if ( token == "/") s.push(lh / rh);
            }
            else
                s.push(stoi(token));
        }
        return s.top();
    }

    int evalRPN2(vector<string> &tokens) {
        string token = tokens.back(); tokens.pop_back();
        if ( token == "+" || token == "-" || token == "*" || token == "/" ) {
            int rh = evalRPN2(tokens);
            int lh = evalRPN2(tokens);
            if ( token == "+") return lh + rh;
            if ( token == "-") return lh - rh;
            if ( token == "*") return lh * rh;
            if ( token == "/") return lh / rh;
        }
        else
            return atoi(token.c_str());
    }
};
