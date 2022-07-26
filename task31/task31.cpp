#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <vector>
#include <vector>

/**
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find
 * the minimum number of conference rooms required.
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return 2.
 *
 */

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
private:
    static bool compareByLength(const Interval &i1, const Interval &i2)
    {
        return i1.start < i2.start || i1.start == i2.start && i1.end < i2.end;
    }

public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(std::vector<Interval> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), compareByLength);

        size_t len_intervals = intervals.size();

        for (size_t i = 1; i < len_intervals; ++i)
        {
            if (intervals[i].start < intervals[i - 1].end)
            {
                return false;
            }
        }

        return true;
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(1)

TEST_CASE("Example 1")
{
    Solution s;

    std::vector<Interval> times = {
        Interval(0, 30),
        Interval(5, 10),
        Interval(15, 20),
    };

    unsigned result = s.canAttendMeetings(times);
    unsigned expected = false;

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 2")
{
    Solution s;

    std::vector<Interval> times = {
        Interval(0, 8),
        Interval(8, 10),
    };

    unsigned result = s.canAttendMeetings(times);
    unsigned expected = true;

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 3")
{
    Solution s;

    std::vector<Interval> times = {
        Interval(5, 8),
        Interval(9, 15),
    };

    unsigned result = s.canAttendMeetings(times);
    unsigned expected = true;

    CHECK_EQ(result, expected);
}
