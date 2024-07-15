class Solution {
public:
    string countOfAtoms(string formula) {int n=formula.size();
        stack<int> s;string num="";string ele="";unordered_map<string,int> cnt;int mul=1;
        for(int i=n-1;i>=0;i--){
            if(formula[i]==')'){
                if(num!="")
                {s.push(stoi(num));mul*=stoi(num);num="";}}
            else if(formula[i]=='('){if(s.size()){mul/=s.top();s.pop();}}
            else if(isdigit(formula[i])){num=formula[i]+num;}
            else if(islower(formula[i])){ele=formula[i]+ele;}
            else{
                ele=formula[i]+ele;
                if(num!=""){mul*=stoi(num);}
                cnt[ele]+=mul;ele="";
                if(num!=""){mul/=stoi(num);num="";}
            }
        }
        vector<string> v;
        for(auto i:cnt){
            if(i.second>1)v.push_back(i.first+to_string(i.second));else v.push_back(i.first);
        }
        sort(v.begin(),v.end());
        return accumulate(v.begin(),v.end(),string());
    }
};