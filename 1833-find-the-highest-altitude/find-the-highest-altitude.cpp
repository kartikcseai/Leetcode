class Solution {
public:
    
int largestAltitude(vector<int>& gain) {
    int currentAlt = 0;
    int maxAlt = 0;

    // Traverse through the gain array
    for (int i = 0; i < gain.size(); i++) {
        currentAlt += gain[i];  // Update the current altitude
        maxAlt = max(maxAlt, currentAlt);  // Track the highest altitude
    }

    return maxAlt;
}
};