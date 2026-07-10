class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        try:
            self.first_name = strs[0]

            for index, value in enumerate(strs, 1):
                while not value.startswith(self.first_name):
                    self.first_name = self.first_name[:-1]
            return self.first_name
        except:
            return "Invalid list"
