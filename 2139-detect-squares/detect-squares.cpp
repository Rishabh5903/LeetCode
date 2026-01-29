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
        int x=point[0], y=point[1];
        int ans=0;
        for(int col:points[x]){
            if(col!=y){
                int len=abs(y-col);
                
                ans+=fr[{x-len,col}]*fr[{x-len,y}];
                ans+=fr[{x+len,col}]*fr[{x+len,y}];
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