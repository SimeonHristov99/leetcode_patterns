class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len_nums = nums.size();
        int critical = len_nums / 2;
        
        unordered_map<int, int> freqs;
        
        for(const int n : nums) {
            unordered_map<int, int>::iterator it = freqs.find(n);
            if(it != freqs.end()) {
                int freq = it->second;
                freqs.erase(it);
                freqs.insert({n, freq + 1});
            } else {
                freqs.insert({n, 1});
            }
        }
        
        for(const auto& freq : freqs) {
            if(freq.second > critical) {
                return freq.first;
            }
        }
        
        return -1;
    }
};

// Time complexity: O(n), n = len(nums)
// Space complexity: O(n), n = len(nums)