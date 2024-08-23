class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> num,deno;
        string temp="";
        for(int i=0;i<expression.size();i++){
            if((expression[i]=='+' || expression[i]=='-') && i!=0){deno.push_back(stoi(temp));temp="";}

            if(expression[i]=='/'){num.push_back(stoi(temp));temp="";}
            else temp+=expression[i];

        }deno.push_back(stoi(temp));
        int denominator=1;
        for(int i:deno)denominator*=i;
        int numerator=0;
        for(int i=0;i<num.size();i++){
            numerator+=num[i]*(denominator/deno[i]);
        }
        int gc=gcd(numerator,denominator);
        numerator/=gc;
        denominator/=gc;
        return (to_string(numerator)+'/'+to_string(denominator));

    }
};