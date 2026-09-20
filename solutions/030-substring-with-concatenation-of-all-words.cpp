class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        if (words.empty()) return answer;

        int wordLength = words[0].size();
        int wordCount = words.size();
        unordered_map<string, int> needed;
        for (string& word : words) needed[word]++;

        for (int offset = 0; offset < wordLength; offset++) {
            int left = offset;
            int right = offset;
            int wordsInWindow = 0;
            unordered_map<string, int> window;

            while (right + wordLength <= s.size()) {
                string word = s.substr(right, wordLength);
                right += wordLength;

                if (!needed.count(word)) {
                    window.clear();
                    wordsInWindow = 0;
                    left = right;
                    continue;
                }

                window[word]++;
                wordsInWindow++;
                while (window[word] > needed[word]) {
                    string leftWord = s.substr(left, wordLength);
                    window[leftWord]--;
                    left += wordLength;
                    wordsInWindow--;
                }

                if (wordsInWindow == wordCount) {
                    answer.push_back(left);
                    string leftWord = s.substr(left, wordLength);
                    window[leftWord]--;
                    left += wordLength;
                    wordsInWindow--;
                }
            }
        }

        return answer;
    }
};