#include <vector>

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivotIndex(vector<int>& nums) {
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            rightSum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (leftSum == rightSum - nums[i])
            {
                return i;
            }
            else
            {
                leftSum += nums[i];
                rightSum -= nums[i];
            }
        }
    }
    }
};

int main()
{
    vector<int> v = {1, 7, 3, 6, 5, 6};
    Solution sol;
    int answer = sol.pivotIndex(v);
    cout << "answer : " << answer;
    return 0;
}