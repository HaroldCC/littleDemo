/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = nullptr; // 新建一个保存和的链表头节点
        ListNode *current = nullptr;
        int carry = 0; // 保存相加后产生的进位
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            carry += (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val);
            ListNode *temp = new ListNode(carry % 10); // 取余数创建链表节点
            carry /= 10;                               // 记录进位

            if (dummyHead == nullptr)
            {
                dummyHead = temp;
                current = dummyHead;
            }
            else
            {
                current->next = temp;
                current = current->next;
            }
            l1 = (l1 == nullptr ? nullptr : l1->next);
            l2 = (l2 == nullptr ? nullptr : l2->next);
        }
        return dummyHead;
    }
};
// @lc code=end