class Solution:
    def isValid(self, s: str) -> bool:
        self.stack = []
        self.pairs = {")": "(", "]": "[", "}": "{"}

        for char in s:
            if char in "([{":
                self.stack.append(char)
            else:
                if not self.stack or self.stack[-1] != self.pairs[char]:
                    return False
                self.stack.pop()

        return len(self.stack) == 0
