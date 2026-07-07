# 0009 - Palindrome Number

**Difficulty:** Easy
**Link:** https://leetcode.com/problems/palindrome-number/

## Problem

Given an integer `x`, return `true` if `x` is a palindrome (reads the same forwards and backwards), and `false` otherwise. Negative numbers are never palindromes, since the `-` sign only appears at the front.

## Approach (String Conversion)

The simplest way to check if a number reads the same forwards and backwards is to treat it as a string:

1. Convert the integer `x` to a string.
2. Reverse a copy of that string.
3. Compare the original string to the reversed one — if they match, it's a palindrome.

This naturally handles negative numbers correctly too: `-121` becomes `"-121"`, and its reverse is `"121-"`, which will never match the original — so negatives correctly fail the check without needing a separate special case.

## Complexity

- **Time:** O(n) — where n is the number of digits, since converting and reversing both scan through the digits once.
- **Space:** O(n) — extra space is used to store the string and its reversed copy.

## Solutions

- [Python](./solution.py)
- [C++](./solution.cpp)

## Notes

- This solution is simple and readable but has more overhead than necessary, since converting an int to a string (and back) isn't free — this showed up as a mid-tier runtime percentile on submission.
- A more efficient O(1) space approach is possible by reversing the number mathematically, using `% 10` to peel off digits and `/ 10` to remove them, without ever converting to a string. Planned as a follow-up solution.