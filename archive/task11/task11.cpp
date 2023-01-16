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
    ListNode *middleNode(ListNode *one_speed)
    {
        ListNode *two_speed = one_speed;

        while (two_speed->next != nullptr)
        {
            two_speed = two_speed->next->next;
            one_speed = one_speed->next;

            if (!two_speed || !two_speed->next)
            {
                return one_speed;
            }
        }

        return two_speed;
    }
};

TEST_CASE("Example 1")
{
    Solution s;

    ListNode *lst = new ListNode(1);
    lst->next = new ListNode(2);
    lst->next->next = new ListNode(3);
    lst->next->next->next = new ListNode(4);
    lst->next->next->next->next = new ListNode(5);

    CHECK_EQ(
        s.middleNode(lst),
        lst->next->next);
}

TEST_CASE("Example 2")
{
    Solution s;

    ListNode *lst = new ListNode(1);
    lst->next = new ListNode(2);
    lst->next->next = new ListNode(3);
    lst->next->next->next = new ListNode(4);
    lst->next->next->next->next = new ListNode(5);
    lst->next->next->next->next->next = new ListNode(6);

    CHECK_EQ(
        s.middleNode(lst),
        lst->next->next->next);
}
