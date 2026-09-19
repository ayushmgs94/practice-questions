class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        for (int start = 0; start + needle.size() <= haystack.size(); start++) {
            bool matches = true;

            for (int offset = 0; offset < needle.size(); offset++) {
                if (haystack[start + offset] != needle[offset]) {
                    matches = false;
                    break;
                }
            }

            if (matches) return start;
        }

        return -1;
    }
};