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
private:
    // void reverseListHelper(ListNode *head, ListNode *&result)
    // {
    //     if (!head)
    //     {
    //         return;
    //     }

    //     result = new ListNode(head->val, result);

    //     reverseListHelper(head->next, result);
    // }

public:
    // iterative
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *tmp = head;
        ListNode *current = nullptr;

        while (tmp)
        {
            current = tmp->next;
            tmp->next = prev;

            prev = tmp;
            tmp = current;
        }

        return prev;
    }

    // recursive
    // ListNode *reverseList(ListNode *head)
    // {
    //     ListNode *result = nullptr;

    //     reverseListHelper(head, result);

    //     return result;
    // }
};

TEST_CASE("Example 1")
{
    Solution s;

    ListNode *lst = new ListNode(1);
    ListNode *lst_current = lst;

    for (int i = 2; i < 6; ++i)
    {
        lst_current->next = new ListNode(i);
        lst_current = lst_current->next;
    }

    ListNode *expected = new ListNode(5);
    ListNode *expected_current = expected;

    for (int i = 4; i > 0; --i)
    {
        expected_current->next = new ListNode(i);
        expected_current = expected_current->next;
    }

    ListNode *result = s.reverseList(lst);

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
    ListNode *lst_current = lst;

    for (int i = 2; i < 4; ++i)
    {
        lst_current->next = new ListNode(i);
        lst_current = lst_current->next;
    }

    ListNode *expected = new ListNode(3);
    ListNode *expected_current = expected;

    for (int i = 2; i > 0; --i)
    {
        expected_current->next = new ListNode(i);
        expected_current = expected_current->next;
    }

    ListNode *result = s.reverseList(lst);

    while (expected)
    {
        CHECK_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }
}

TEST_CASE("Example 3")
{
    Solution s;
    ListNode *lst = nullptr;
    ListNode *expected = nullptr;
    ListNode *result = s.reverseList(lst);

    CHECK_EQ(result, expected);
}
