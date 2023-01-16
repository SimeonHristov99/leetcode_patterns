#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

// Time Complexity: O(n*m*(m-1))
// Space Complexity: O(m)

std::vector<std::pair<int, int>> get_indices(const std::string &word, const std::string &text, const size_t len_text)
{
    std::vector<std::pair<int, int>> result;
    size_t word_i = 0, len_word = word.length();

    for (size_t i = 0; i < len_text; ++i)
    {
        if (text[i] == word[word_i])
        {
            int ci = i;
            while (i < len_text && text[i] == word[word_i])
            {
                ++word_i;
                ++i;
            }
            if (word_i == len_word)
            {
                result.push_back({ci, i - 1});
            }
            word_i = 0;
            i = ci;
        }
    }

    return result;
}

std::vector<std::pair<int, int>> index_pairs(const std::string &text, const std::vector<std::string> &words)
{
    size_t len_text = text.size();
    std::vector<std::pair<int, int>> result;
    std::vector<std::pair<int, int>> indices;

    // append all instances of the word in the text
    for (const std::string &word : words) // O(n), n = len(words)
    {
        indices = get_indices(word, text, len_text); // O(m*(m-1)), m = len(text)

        for (const auto &p : indices) // O(m)
        {
            result.push_back(p);
        }
    }

    // sort vector of pairs
    // O(m * logm)
    std::sort(result.begin(), result.end(), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2)
              { return p1.first < p2.first || p1.first == p2.first && p1.second < p2.second; });

    return result;
}

TEST_CASE("Example 1")
{
    size_t len_expected = 0, len_expected_i = 0;

    std::string text = "thestoryofleetcodeandme";
    std::vector<std::string> words{"story", "fleet", "leetcode"};

    std::vector<std::pair<int, int>> expected{{3, 7}, {9, 13}, {10, 17}};
    std::vector<std::pair<int, int>> result = index_pairs(text, words);

    len_expected = expected.size();

    CHECK_EQ(len_expected, result.size());

    for (size_t i = 0; i < len_expected; ++i)
    {
        CHECK_EQ(expected[i], result[i]);
    }
}

TEST_CASE("Example 2")
{
    size_t len_expected = 0, len_expected_i = 0;

    std::string text = "ababa";
    std::vector<std::string> words{"aba", "ab"};

    std::vector<std::pair<int, int>> expected{{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    std::vector<std::pair<int, int>> result = index_pairs(text, words);

    len_expected = expected.size();

    CHECK_EQ(len_expected, result.size());

    for (size_t i = 0; i < len_expected; ++i)
    {
        CHECK_EQ(expected[i], result[i]);
    }
}

TEST_CASE("Example 3")
{
    size_t len_expected = 0, len_expected_i = 0;

    std::string text = "aaaa";
    std::vector<std::string> words{"a"};

    std::vector<std::pair<int, int>> expected{{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    std::vector<std::pair<int, int>> result = index_pairs(text, words);

    len_expected = expected.size();

    CHECK_EQ(len_expected, result.size());

    for (size_t i = 0; i < len_expected; ++i)
    {
        CHECK_EQ(expected[i], result[i]);
    }
}