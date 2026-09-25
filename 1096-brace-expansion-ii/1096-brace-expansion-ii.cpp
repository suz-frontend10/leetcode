class Solution {
public:
    int idx;

    set<string> product(set<string>& a, set<string>& b) {
        set<string> res;
        for (auto &x : a) {
            for (auto &y : b) {
                res.insert(x + y);
            }
        }
        return res;
    }

    set<string> parse(string& s) {
        set<string> res;
        set<string> cur = {""};

        while (idx < s.size()) {
            char ch = s[idx];

            if (islower(ch)) {
                set<string> temp = {string(1, ch)};
                cur = product(cur, temp);
                idx++;
            }
            else if (ch == '{') {
                idx++;
                set<string> inside = parse(s);
                cur = product(cur, inside);
            }
            else if (ch == ',') {
                res.insert(cur.begin(), cur.end());
                cur = {""};
                idx++;
            }
            else if (ch == '}') {
                idx++;
                break;
            }
        }

        res.insert(cur.begin(), cur.end());
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        idx = 0;
        set<string> ans = parse(expression);
        return vector<string>(ans.begin(), ans.end());
    }
};