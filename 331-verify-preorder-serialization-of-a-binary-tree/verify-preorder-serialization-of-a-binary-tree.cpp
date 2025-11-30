class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot=1, n=preorder.size();
        for(int i=0;i<n;i++){
            if(preorder[i]==',') continue; // skip comma
            slot--;
            if(slot<0) return false;
            if(preorder[i]!='#'){
                slot+=2;
                i++;
            }
        }
        return slot==0;
    }
};