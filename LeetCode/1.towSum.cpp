/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.52%)
 * Likes:    8616
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.4M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
vector<int> twoSum(vector<int> &nums, int target)
{
    int sum = 0;
    vector<int> result;
    for (int i = 0; i != nums.size(); ++i)
    {
        sum = nums[i] + nums[i + 1];
        if (sum == target)
        {
            result.push_back(i);
            result.push_back(i + 1);
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{2, 7, 11, 15};
    vector<int> result;
    result = twoSum(nums, 9);
    for (auto i : result)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}

// @lc code=end
