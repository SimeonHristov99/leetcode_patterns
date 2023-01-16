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
    bool isPalindrome(ListNode *one_speed)
    {
        ListNode *two_speed = one_speed;
        ListNode *rev = nullptr;
        ListNode *tmp = nullptr;

        while (two_speed && two_speed->next)
        {
            two_speed = two_speed->next->next;
            tmp = one_speed->next;
            one_speed->next = rev;
            rev = one_speed;
            one_speed = tmp;
        }

        if (two_speed)
        {
            // odd number of elements
            one_speed = one_speed->next;
        }

        while (rev && one_speed)
        {
            if (rev->val != one_speed->val)
            {
                return false;
            }

            rev = rev->next;
            one_speed = one_speed->next;
        }

        return rev == nullptr && one_speed == nullptr;
    }
};

TEST_CASE("Example 1")
{
    Solution s;

    ListNode *lst = new ListNode(1);
    lst->next = new ListNode(2);
    lst->next->next = new ListNode(2);
    lst->next->next->next = new ListNode(1);

    CHECK(s.isPalindrome(lst));
}

TEST_CASE("Example 2")
{
    Solution s;

    ListNode *lst = new ListNode(1);
    lst->next = new ListNode(2);

    CHECK_FALSE(s.isPalindrome(lst));
}

TEST_CASE("Example 3")
{
    Solution s;

    ListNode *lst = new ListNode(1);
    lst->next = new ListNode(0);
    lst->next->next = new ListNode(1);

    CHECK(s.isPalindrome(lst));
}

TEST_CASE("Example 4")
{
    Solution s;

    ListNode *lst = new ListNode(0);
    lst->next = new ListNode(0);

    CHECK(s.isPalindrome(lst));
}
