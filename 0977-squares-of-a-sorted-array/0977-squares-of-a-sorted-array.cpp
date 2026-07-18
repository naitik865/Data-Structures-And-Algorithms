class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int size = nums.size();
        vector<int> neg;
        vector<int> pos;

        // Separate negative and positive numbers
        for (int i = 0; i < size; i++) {
            if (nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

        // If there are no negative numbers
        if (neg.size() == 0) {
            for (int i = 0; i < pos.size(); i++) {
                pos[i] = pos[i] * pos[i];
            }
            return pos;
        }

        // If there are no positive numbers
        if (pos.size() == 0) {
            for (int i = 0; i < neg.size(); i++) {
                neg[i] = neg[i] * neg[i];
            }
            reverse(neg.begin(), neg.end());
            return neg;
        }

        int n = neg.size();
        int m = pos.size();

        // Square all elements
        for (int i = 0; i < n; i++) {
            neg[i] = neg[i] * neg[i];
        }

        reverse(neg.begin(), neg.end());

        for (int i = 0; i < m; i++) {
            pos[i] = pos[i] * pos[i];
        }

        // Merge two sorted arrays
        vector<int> res(n + m);

        int i = 0, j = 0, k = 0;

        while (i < n && j < m) {
            if (neg[i] <= pos[j]) {
                res[k++] = neg[i++];
            } else {
                res[k++] = pos[j++];
            }
        }

        while (i < n) {
            res[k++] = neg[i++];
        }

        while (j < m) {
            res[k++] = pos[j++];
        }

        return res;
    }
};