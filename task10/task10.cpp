#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *one_speed)
    {
        if (!one_speed)
        {
            return false;
        }

        ListNode *two_speed = one_speed;

        while (two_speed->next != nullptr && two_speed->next->next != nullptr)
        {
            two_speed = two_speed->next->next;

            if (two_speed == one_speed)
            {
                return true;
            }

            one_speed = one_speed->next;
        }

        return false;
    }
};

TEST_CASE("Example 1")
{
    Solution s;

    ListNode *lst = new ListNode(3);
    lst->next = new ListNode(2);
    lst->next->next = new ListNode(0);
    lst->next->next->next = new ListNode(-4);
    lst->next->next->next->next = lst->next;

    CHECK(s.hasCycle(lst));
}

TEST_CASE("Example 2")
{
    Solution s;

    ListNode *lst = new ListNode(1);
    lst->next = new ListNode(2);
    lst->next->next = lst;

    CHECK(s.hasCycle(lst));
}

TEST_CASE("Example 3")
{
    Solution s;

    ListNode *lst = new ListNode(1);

    CHECK_FALSE(s.hasCycle(lst));
}
