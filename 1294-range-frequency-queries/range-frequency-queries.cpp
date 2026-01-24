class RangeFreqQuery {
public:
    vector<unordered_map<int,int>> st;
    int n;
    unordered_map<int,int> add_maps(unordered_map<int,int>& m1, unordered_map<int,int>& m2){
        unordered_map<int,int> mp;
        for(auto x:m1) mp.insert(x);
        for(auto x:m2){
            int key=x.first, freq=x.second;
            if(mp.find(key)==mp.end()) mp.insert(x);
            else mp[key]+=freq;
        }
        return mp;
    }
    void buildTree(vector<int>& arr, int i, int lo, int hi){
        if(lo==hi){
            int key=arr[lo], freq=1;
            st[i].insert({key,freq});
            return;
        }
        int mid=lo+(hi-lo)/2;
        buildTree(arr,2*i+1,lo,mid);
        buildTree(arr,2*i+2,mid+1,hi);
        st[i]=add_maps(st[2*i+1],st[2*i+2]);
    }
    RangeFreqQuery(vector<int>& arr) {
        n=arr.size();
        st.resize(4*n);
        buildTree(arr,0,0,n-1);
    }
    int getfreq(int i, int lo, int hi, int& l, int& r, int& key){
        if(l>hi || r<lo) return 0;
        if(lo>=l && hi<=r){
            if(st[i].find(key)==st[i].end()) return 0;
            else return (st[i])[key];
        }
        int mid=lo+(hi-lo)/2;
        int leftFreq=getfreq(2*i+1,lo,mid,l,r,key);
        int rightFreq=getfreq(2*i+2,mid+1,hi,l,r,key);
        return leftFreq+rightFreq;
    }
    int query(int left, int right, int value) {
        return getfreq(0,0,n-1,left,right,value);
    }
};