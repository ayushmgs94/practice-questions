class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for (int step = 1; step < n; step++) {
            string next;

            for (int i = 0; i < result.size();) {
                int j = i;
                while (j < result.size() && result[j] == result[i]) {
                    j++;
                }
                next += to_string(j - i);
                next += result[i];
                i = j;
            }

            result = next;
        }

        return result;
    }
};