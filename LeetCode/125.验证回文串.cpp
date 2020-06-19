/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (42.28%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    128.2K
 * Total Submissions: 282.7K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

#include <string>
#include <stack>
#include <cctype>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        stack<char> reverse;
        for (auto i = s.cbegin(); i != s.cend(); ++i)
        {
            if (ispunct(*i) || isspace(*i))
                continue;
            reverse.push(tolower(*i));
        }
        for (auto i : s)
        {
            if (ispunct(i) || isspace(i))
                continue;
            if (tolower(i) == reverse.top())
            {
                reverse.pop();
            }
        }
        if (reverse.empty())
            return true;
        return false;
    }
};

// @lc code=end
