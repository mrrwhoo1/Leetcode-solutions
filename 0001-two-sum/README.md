# 0001 - Two Sum

**Difficulty:** Easy
**Link:** https://leetcode.com/problems/two-sum/

## Problem

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to `target`. Each input has exactly one solution, and the same element can't be used twice.

## Approach

Brute force checks every pair of numbers, which costs O(n²) time — for each number, you scan the rest of the array looking for a match.

The optimized approach uses a hash map to cut this down to a single pass:

1. Walk through the array once, keeping track of both the value and its index.
2. For each number, calculate its `complement` (`target - value`) — the number that would complete the pair.
3. Check whether that complement has already been seen and stored in the map.
   - If yes, return the stored index of the complement along with the current index.
   - If no, store the current value and its index in the map, and move on.

This works because checking "have I seen this value before" against a hash map is close to instant (O(1) on average), instead of rescanning the array each time.

## Complexity

- **Time:** O(n) — single pass through the array.
- **Space:** O(n) — the hash map can hold up to n entries in the worst case.

## Solutions

- [Python](./solution.py)
- [C++](./solution.cpp)

## Notes

- Trade-off: this solution uses extra memory (the hash map) to gain a big speed-up over brute force — a classic time vs. space trade-off.
- In C++, the map is `unordered_map<int, int>`, mapping a value seen so far to its index.
