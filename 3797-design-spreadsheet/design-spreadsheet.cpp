#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
    int r;
    vector<vector<int>> mp;

    pair<int,int> conv(const string &s) {
        int x = s[0] - 'A';
        int y = stoi(s.substr(1));
        return {x,y};
    }

public:
    Spreadsheet(int rows) {
        r = rows;
        mp.assign(26, vector<int>(rows+1,0));
    }
    
    void setCell(string c, int v) {
        auto [x,y] = conv(c);
        mp[x][y] = v;
    }
    
    void resetCell(string c) {
        auto [x,y] = conv(c);
        mp[x][y] = 0;
    }
    
    int getValue(string f) {
        string s = f.substr(1);
        int p = s.find('+');
        string a = s.substr(0,p), b = s.substr(p+1);
        auto val=[&](const string &z){
            if(isalpha(z[0])){auto [x,y]=conv(z);return mp[x][y];}
            return stoi(z);
        };
        return val(a)+val(b);
    }
};
