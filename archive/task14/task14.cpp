#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode *current = head;
        ListNode *candidate = head->next;
        ListNode *tmp = nullptr;

        while (candidate)
        {
            if (candidate->val != current->val)
            {
                current = current->next;
                candidate = candidate->next;
            }
            else
            {
                tmp = candidate;
                candidate = candidate->next;
                current->next = candidate;
                tmp->next = nullptr;
                delete tmp;
                tmp = nullptr;
            }
        }

        return head;
    }
};

TEST_CASE("Example 1")
{
    Solution s;

    ListNode *lst = new ListNode(1);
    lst->next = new ListNode(1);
    lst->next->next = new ListNode(2);

    ListNode *expected = new ListNode(1);
    expected->next = new ListNode(2);

    ListNode *result = s.deleteDuplicates(lst);

    while (expected)
    {
        CHECK_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }
}

TEST_CASE("Example 2")
{
    Solution s;

    ListNode *lst = new ListNode(1);
    lst->next = new ListNode(1);
    lst->next->next = new ListNode(2);
    lst->next->next->next = new ListNode(3);
    lst->next->next->next->next = new ListNode(3);

    ListNode *expected = new ListNode(1);
    expected->next = new ListNode(2);
    expected->next->next = new ListNode(3);

    ListNode *result = s.deleteDuplicates(lst);

    while (expected)
    {
        CHECK_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }
}
