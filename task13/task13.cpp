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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
        {
            return nullptr;
        }

        if (head->val == val)
        {
            return removeElements(head->next, val);
        }

        return new ListNode(head->val, removeElements(head->next, val));
    }
};

TEST_CASE("Example 1")
{
    Solution s;

    ListNode *lst = new ListNode(1);
    lst->next = new ListNode(2);
    lst->next->next = new ListNode(6);
    lst->next->next->next = new ListNode(3);
    lst->next->next->next->next = new ListNode(4);
    lst->next->next->next->next->next = new ListNode(5);
    lst->next->next->next->next->next->next = new ListNode(6);

    ListNode *expected = new ListNode(1);
    expected->next = new ListNode(2);
    expected->next->next = new ListNode(3);
    expected->next->next->next = new ListNode(4);
    expected->next->next->next->next = new ListNode(5);

    ListNode *result = s.removeElements(lst, 6);

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

    ListNode *lst = nullptr;
    ListNode *expected = nullptr;
    ListNode *result = s.removeElements(lst, 1);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 3")
{
    Solution s;

    ListNode *lst = new ListNode(7);
    lst->next = new ListNode(7);
    lst->next->next = new ListNode(7);
    lst->next->next->next = new ListNode(7);

    ListNode *expected = nullptr;
    ListNode *result = s.removeElements(lst, 7);

    CHECK_EQ(result, expected);
}
