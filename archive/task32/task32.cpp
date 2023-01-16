class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        stack<int> before_zero;
        vector<int> after_zero;
        
        int i = 0;
        int to_add = -1;
        int len_nums = nums.size();
        
        while(i < len_nums && nums[i] < 0) {
            before_zero.push(nums[i] * nums[i]);
            ++i;
        }
        
        while(i < len_nums) {
            to_add = nums[i] * nums[i];
            if(!before_zero.empty() && to_add < before_zero.top()) {
                after_zero.push_back(to_add);
                ++i;
            } else if (!before_zero.empty() && to_add >= before_zero.top()) {
                after_zero.push_back(before_zero.top());
                before_zero.pop();
            } else {
                after_zero.push_back(to_add);
                ++i;
            }
        }
        
        while(!before_zero.empty()) {
            after_zero.push_back(before_zero.top());
            before_zero.pop();
        }
        
        return after_zero;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
