# 0013 - Roman to Integer

**Difficulty:** Easy
**Link:** https://leetcode.com/problems/roman-to-integer/

## Problem

Given a Roman numeral string, convert it to an integer. Roman numerals are normally read left to right and added together (e.g. `VI` = 5 + 1 = 6), except when a smaller-value symbol appears directly before a larger one — in that case, the smaller value is subtracted instead (e.g. `IV` = 5 - 1 = 4).

## Approach

1. Map each Roman symbol to its integer value using a hash map: `{I: 1, V: 5, X: 10, L: 50, C: 100, D: 500, M: 1000}`.
2. Walk through the string one character at a time, keeping the current index.
3. For each character, look at the **next** character (if one exists):
   - If the current symbol's value is *smaller* than the next symbol's value, subtract the current value from the running total (subtractive case, e.g. the `I` in `IV`).
   - Otherwise, add the current value to the running total (normal case, or the current symbol is the last character in the string).
4. Return the running total once the whole string has been processed.

The key insight is that deciding "add or subtract" always depends on comparing the *current* symbol to the *next* one — a single character can never tell you what to do on its own.

## Complexity

- **Time:** O(n) — single pass through the string.
- **Space:** O(1) — the symbol-to-value map has a fixed size (7 entries) regardless of input length.

## Solutions

- [Python](./solution.py)
- [C++](./solution.cpp)

## Notes

- **Python version:** builds the value lookup and add/subtract decision directly off the input string using a dictionary.
- **C++ version:** first converts each Roman character into its integer value (stored in a `vector<int>`), then applies the same add/subtract comparison logic over the vector of values instead of re-looking-up characters each time.
- Watched out for a classic C++ scope bug here: a variable declared inside an `if` block isn't visible in the matching `else` block — needed to declare shared variables (like `current_val`) *before* the branch, so both paths could use it.
- Also ran into `unordered_map`'s `[]` operator silently returning a default value (`0`) for missing keys instead of erroring — a good reminder to use `.find()`/`.count()` when a key's existence isn't guaranteed.
