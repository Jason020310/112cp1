nums = input()
nums = nums.split()
nums = [int(x) for x in nums]
if nums[0] < nums[1]:
    tmp = nums[0]
    nums[0] = nums[1]
    nums[1] = tmp
print(nums[0] - nums[1])
