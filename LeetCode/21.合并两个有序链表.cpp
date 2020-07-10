/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (59.49%)
 * Likes:    1142
 * Dislikes: 0
 * Total Accepted:    308.5K
 * Total Submissions: 487.9K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。
 * 新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *newHead = nullptr;  // 指向合并后链表的第一个节点
        ListNode *tailHead = nullptr; // 指向新链表的最后一个节点
        if (nullptr == l1)
            return l1;
        else if (nullptr == l2)
            return l2;
        else // 两个链表都不为空
        {
            // 确定头节点
            if (l1->val < l2->val)
            {
                newHead = l1;
                l1 = l1->next;
            }
            else
            {
                newHead = l2;
                l2 = l2->next;
            }

            tailHead = newHead; // 头尾指向同一个节点

            while (nullptr != l1 && nullptr != l2)
            {
                if (l1->val <= l2->val)
                {
                    tailHead->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    tailHead->next = l2;
                    l2 = l2->next;
                }

                tailHead = tailHead->next;
            }

            // 确定尾节点
            if (nullptr == l2)
                tailHead->next = l2;
            else if (nullptr == l1)
                tailHead->next = l1;
        }
        return newHead;
    }
};
// @lc code=end
