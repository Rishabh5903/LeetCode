class Solution {
public:
    string multiply(string num1, string num2) {
        int mul1 = 0;
        vector<string> res;

        for(int i = num2.size() - 1; i >= 0; i--) {
            char c2 = num2[i];
            string temp = "";
            int carry = 0;

            for(int j = num1.size() - 1; j >= 0; j--) {
                int prod = (c2 - '0') * (num1[j] - '0') + carry;
                temp.push_back((prod % 10) + '0');
                carry = prod / 10;
            }

            if(carry)
                temp.push_back(carry + '0');

            reverse(temp.begin(), temp.end());

            string zeros(mul1, '0');
            res.push_back(temp + zeros);
            mul1++;
        }

        string ans = "";
        int carry = 0;

        for(int i = 0; i < res.back().size(); i++) {
            int temp = 0;
            for(string &s : res) {
                int n = s.size();
                if(i < n) temp += s[n - i - 1] - '0';
            }
            temp += carry;
            carry = temp / 10;
            ans.push_back((temp % 10) + '0');
        }

        if(carry) ans.push_back(carry + '0');

        while(ans.size() && ans.back() == '0') ans.pop_back();
        if(ans.empty()) ans = "0";

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
