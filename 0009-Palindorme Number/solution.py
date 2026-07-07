class Solution:
    def isPalindrome(self, x: int) -> bool:
        self.convert = str(x)
        if self.convert == self.convert[::-1]:
            return True
        else:
            return False
