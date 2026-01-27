class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        digits[digits.size()-1]++;
        if(digits.back()==10){
            carry=1;
            digits[digits.size()-1]=0;
        }
        int temp=0;
        for(int i=digits.size()-2;i>=0;i--){
            temp=digits[i]+carry;
            carry=temp/10;
            digits[i]=temp%10;
        }
        if(carry){
            vector<int> ANS={carry};
            ANS.insert(ANS.end(),digits.begin(),digits.end());
            digits=ANS;
        }
        return digits;
    }
};