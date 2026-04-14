class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        if (minVal == maxVal) return 0;

        // Bucket size is at least 1, so max gap should cross bucket boundaries
        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        // Each bucket tracks the min and max value that got into it
        vector<int> bMin(bucketCount, INT_MAX);
        vector<int> bMax(bucketCount, INT_MIN);

        // Each number goes into its respective bucket
        for (int num : nums) {
            int index = (num - minVal) / bucketSize;
            bMin[index] = min(bMin[index], num);
            bMax[index] = max(bMax[index], num);
        }
        
        // Scan buckets, max gap is between successive non-empty buckets
        int maxGap = 0;
        int prevMax = minVal;

        for (int i = 0; i < bucketCount; i++) {
            if (bMin[i] == INT_MAX) continue; // Empty bucket, skip
            maxGap = max(maxGap, bMin[i] - prevMax);
            prevMax = bMax[i];
        }
        return maxGap;
    }
};