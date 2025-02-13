# Pattern: Hash Map.


def maximum_sum(nums: list[int]) -> int:
    max_sum = -1
    sum_to_index = {}

    for i in range(len(nums)):
        sum_of_digits = sum(map(int, str(nums[i])))
        if sum_of_digits in sum_to_index:
            max_sum = max(max_sum, nums[i] + nums[sum_to_index[sum_of_digits]])
            sum_to_index[sum_of_digits] = i if nums[i] > nums[
                sum_to_index[sum_of_digits]] else sum_to_index[sum_of_digits]
        else:
            sum_to_index[sum_of_digits] = i

    return max_sum


# Slower alternative
# max_sum = -1
# for i in range(len(nums) - 1):
#     for j in range(i + 1, len(nums)):
#         if sum(int(digit) for digit in str(nums[i])) == sum(int(digit) for digit in str(nums[j])):
#             max_sum = max(nums[i] + nums[j], max_sum)
#             print(nums[i], nums[j], max_sum)
# return max_sum
