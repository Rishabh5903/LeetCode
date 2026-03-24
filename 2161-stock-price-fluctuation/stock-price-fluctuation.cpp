class StockPrice {
public:
map<int,int> prices;
priority_queue<pair<int,int>> maxo;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mino;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        
        // while(maxo.size() && maxo.top().second==timestamp){
        //     maxo.pop();
            
        // }
        // while(mino.size() && mino.top().second==timestamp){
        //     mino.pop();
            
        // }
        prices[timestamp] = price;
        maxo.push({price,timestamp});
        mino.push({price,timestamp});
    }
    
    int current() {
        return (*prices.rbegin()).second;
    }
    
    int maximum() {
        while(maxo.size() && prices[maxo.top().second] != maxo.top().first)maxo.pop();
        return maxo.top().first;
    }
    
    int minimum() {
        while(mino.size() && prices[mino.top().second] != mino.top().first)mino.pop();
        return mino.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */