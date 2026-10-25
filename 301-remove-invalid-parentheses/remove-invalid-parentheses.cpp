class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int i, int leftRem, int rightRem,
             int balance, string curr) {

        if (balance < 0)
            return;

        if (i == s.size()) {
            if (leftRem == 0 && rightRem == 0 && balance == 0)
                ans.insert(curr);
            return;
        }

        if (s[i] == '(') {
            if (leftRem > 0)
                dfs(s, i + 1, leftRem - 1, rightRem, balance, curr);

            dfs(s, i + 1, leftRem, rightRem, balance + 1, curr + '(');
        }
        else if (s[i] == ')') {
            if (rightRem > 0)
                dfs(s, i + 1, leftRem, rightRem - 1, balance, curr);

            if (balance > 0)
                dfs(s, i + 1, leftRem, rightRem, balance - 1, curr + ')');
        }
        else {
            dfs(s, i + 1, leftRem, rightRem, balance, curr + s[i]);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRem = 0, rightRem = 0;

        for (char c : s) {
            if (c == '(')
                leftRem++;
            else if (c == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        dfs(s, 0, leftRem, rightRem, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};