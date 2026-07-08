class Solution:
    def romanToInt(self, s: str) -> int:

        self.characters = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        self.new_list = list(s)
        self.total = 0
        for index, char in enumerate(self.new_list):
            current_val = self.characters[char]
            next_index = index + 1

            if next_index < len(self.new_list):
                next_char = self.new_list[next_index]
                next_val = self.characters[next_char]

                if current_val < next_val:
                    self.total -= current_val
                else:
                    self.total += current_val
            else:
                self.total += current_val

        return self.total
