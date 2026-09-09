class Solution {
public:
    string longestCommonPrefix(vector<string>& words) {
        if (words.empty()) return "";

        string prefix = words[0];
        for (int wordIndex = 1; wordIndex < words.size(); wordIndex++) {
            int matchingLength = 0;
            while (matchingLength < prefix.size() &&
                   matchingLength < words[wordIndex].size() &&
                   prefix[matchingLength] == words[wordIndex][matchingLength]) {
                matchingLength++;
            }
            prefix = prefix.substr(0, matchingLength);
            if (prefix.empty()) return "";
        }
        return prefix;
    }
};