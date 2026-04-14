class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0, 0, 0};

        // first pass to count occurrences of 0, 1, and 2
        for (int n : nums)
            count[n]++;

        // second pass to overwrite array using counts
        int i = 0;
        for (int color = 0; color < 3; color++)
            while (count[color]--)
                nums[i++] = color;
    }
};