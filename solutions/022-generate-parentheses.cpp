class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string current;
        buildParentheses(n, 0, 0, current, answer);
        return answer;
    }

private:
    void buildParentheses(int n, int openCount, int closeCount,
                          string& current, vector<string>& answer) {
        if (current.size() == 2 * n) {
            answer.push_back(current);
            return;
        }

        if (openCount < n) {
            current.push_back('(');
            buildParentheses(n, openCount + 1, closeCount, current, answer);
            current.pop_back();
        }

        if (closeCount < openCount) {
            current.push_back(')');
            buildParentheses(n, openCount, closeCount + 1, current, answer);
            current.pop_back();
        }
    }
};