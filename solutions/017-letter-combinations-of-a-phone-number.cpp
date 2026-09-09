class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> answer;
        string current;
        buildCombinations(digits, 0, current, answer, letters);
        return answer;
    }

private:
    void buildCombinations(const string& digits, int index, string& current,
                           vector<string>& answer,
                           const vector<string>& letters) {
        if (index == digits.size()) {
            answer.push_back(current);
            return;
        }

        for (char letter : letters[digits[index] - '0']) {
            current.push_back(letter);
            buildCombinations(digits, index + 1, current, answer, letters);
            current.pop_back();
        }
    }
};