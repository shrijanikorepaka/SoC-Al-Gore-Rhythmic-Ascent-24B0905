#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         deque<int> dq; // Stores indices
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove elements smaller than the current from the back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Add the current max to the result once the window is of size k
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};
