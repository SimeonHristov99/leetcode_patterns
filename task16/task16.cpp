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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *result = nullptr;
        ListNode *result_current = nullptr;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                if (!result)
                {
                    result = new ListNode(list1->val);
                    result_current = result;
                }
                else
                {
                    result_current->next = new ListNode(list1->val);
                    result_current = result_current->next;
                }

                list1 = list1->next;
            }
            else
            {
                if (!result)
                {
                    result = new ListNode(list2->val);
                    result_current = result;
                }
                else
                {
                    result_current->next = new ListNode(list2->val);
                    result_current = result_current->next;
                }

                list2 = list2->next;
            }
        }

        while (list1)
        {
            if (!result)
            {
                result = list1;
                break;
            }
            else
            {
                result_current->next = new ListNode(list1->val);

                list1 = list1->next;
                result_current = result_current->next;
            }
        }

        while (list2)
        {
            if (!result)
            {
                result = list2;
                break;
            }
            else
            {
                result_current->next = new ListNode(list2->val);

                list2 = list2->next;
                result_current = result_current->next;
            }
        }

        return result;
    }
};

TEST_CASE("Example 1")
{
    Solution s;

    ListNode *lst1 = new ListNode(1);
    lst1->next = new ListNode(2);
    lst1->next->next = new ListNode(4);

    ListNode *lst2 = new ListNode(1);
    lst2->next = new ListNode(3);
    lst2->next->next = new ListNode(4);

    ListNode *expected = new ListNode(1);
    expected->next = new ListNode(1);
    expected->next->next = new ListNode(2);
    expected->next->next->next = new ListNode(3);
    expected->next->next->next->next = new ListNode(4);
    expected->next->next->next->next->next = new ListNode(4);

    ListNode *result = s.mergeTwoLists(lst1, lst2);

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

    ListNode *lst1 = nullptr;
    ListNode *lst2 = nullptr;

    ListNode *expected = nullptr;
    ListNode *result = s.mergeTwoLists(lst1, lst2);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 3")
{
    Solution s;

    ListNode *lst1 = nullptr;
    ListNode *lst2 = new ListNode(0);

    ListNode *expected = new ListNode(0);
    ListNode *result = s.mergeTwoLists(lst1, lst2);

    while (expected)
    {
        CHECK_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }
}

TEST_CASE("Example 4")
{
    Solution s;

    ListNode *lst1 = new ListNode(1);
    ListNode *lst2 = new ListNode(2);

    ListNode *expected = new ListNode(1);
    expected->next = new ListNode(2);
    ListNode *result = s.mergeTwoLists(lst1, lst2);

    while (expected)
    {
        CHECK_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }
}
