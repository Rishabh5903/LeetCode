class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for(string i:logs){
            if(i=="../" && s.size())
            s.pop();
            else if(i!="./" && i!="../")s.push(i);
        }return s.size();
    }
};