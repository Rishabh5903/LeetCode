class DetectSquares {
public:
map<vector<int>,int> fr;
vector<vector<int>> points;
    DetectSquares() {
        points = vector<vector<int>>(1001);
    }
    
    void add(vector<int> point) {
        fr[point]++;
        points[point[0]].push_back(point[1]);
    }
    
    int count(vector<int> point) {
    int x = point[0], y = point[1];
    int ans = 0;

    for (int col:points[x]) {
        if (col == y) continue;

        int len = abs(y - col);

        auto it1 = fr.find({x - len, col});
        auto it2 = fr.find({x - len, y});

        if (it1 != fr.end() && it2 != fr.end() ) {
            ans += it1->second * it2->second;
        }

        auto it4 = fr.find({x + len, col});
        auto it5 = fr.find({x + len, y});

        if (it4 != fr.end() && it5 != fr.end()) {
            ans += it4->second * it5->second ;
        }
    }
    return ans;
}

};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */