class SnapshotArray {
public:
vector<vector<int>> versions, values;
int id=-1;
    SnapshotArray(int length) {
        versions.resize(length);
        values.resize(length);
        for(auto& v:versions)v.push_back(-1);
        for(auto& v:values)v.push_back(0);
    }
    
    void set(int index, int val) {
        if((id+2)==values[index].size()) {values[index].back()=val;versions[index].back()=id;}
        else {values[index].push_back(val); versions[index].push_back(id);}
    }
    
    int snap() {
        id++;
        return id;
    }
    
    int get(int index, int snap_id) {
        int ver_idx = lower_bound(versions[index].begin(), versions[index].end(), snap_id) - versions[index].begin() -1;
        return values[index][ver_idx];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */