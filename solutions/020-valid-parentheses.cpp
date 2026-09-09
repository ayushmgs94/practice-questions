class Solution {
public:
    bool isValid(string s) {
        stack<char> openBrackets;

        for (char bracket : s) {
            if (bracket == '(' || bracket == '[' || bracket == '{') {
                openBrackets.push(bracket);
                continue;
            }

            if (openBrackets.empty()) return false;
            char openingBracket = openBrackets.top();
            openBrackets.pop();

            if ((bracket == ')' && openingBracket != '(') ||
                (bracket == ']' && openingBracket != '[') ||
                (bracket == '}' && openingBracket != '{')) {
                return false;
            }
        }

        return openBrackets.empty();
    }
};