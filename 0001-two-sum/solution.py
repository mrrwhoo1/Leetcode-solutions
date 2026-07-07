class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        self.seen = {}
        for index, value in enumerate(nums):
            complement = target - value
            if complement in self.seen:
                return [self.seen[complement], index]
            self.seen[value] = index
        return []
