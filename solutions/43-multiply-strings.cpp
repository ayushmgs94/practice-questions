class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> product(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int value = (num1[i] - '0') * (num2[j] - '0');
                int position = i + j + 1;
                int sum = value + product[position];
                product[position] = sum % 10;
                product[position - 1] += sum / 10;
            }
        }

        string answer;
        int i = 0;
        while (i < product.size() && product[i] == 0) i++;
        while (i < product.size()) answer += char('0' + product[i++]);
        return answer;
    }
};