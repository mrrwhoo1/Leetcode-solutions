# 0020 - Valid Parentheses

**Difficulty:** Easy
**Link:** https://leetcode.com/problems/valid-parentheses/

## Problem

Given a string containing only `(`, `)`, `{`, `}`, `[`, `]`, determine if it's valid. A string is valid if:
1. Every opening bracket has a matching closing bracket of the same type.
2. Brackets close in the correct order (the most recently opened bracket must be the next one closed).

Example: `"()[]{}"` → valid. `"(]"` → invalid (wrong type). `"([)]"` → invalid (wrong order, even though bracket counts match).

## Approach (Stack)

A simple open/close count can't catch ordering problems (`"([)]"` has balanced counts but is still invalid), so this needs a structure that tracks *which bracket was opened most recently*. That's exactly what a **stack** (Last In, First Out) is for.

1. Walk through the string one character at a time.
2. If the character is an **opening** bracket, push it onto the stack.
3. If it's a **closing** bracket:
   - If the stack is empty, there's nothing to match against — invalid.
   - If the top of the stack doesn't match the expected opener for this closing bracket, invalid.
   - Otherwise, pop the matching opener off the stack — it's been successfully closed.
4. After processing every character, the string is valid only if the stack is **empty** (no unclosed brackets left over).

The key lookup is a dictionary mapping each **closing** bracket to its expected **opening** bracket (e.g. `")" → "("`), since at the moment you encounter a closer, that's the question you need answered: "what opener am I expecting to find on top?"

## Complexity

- **Time:** O(n) — single pass through the string.
- **Space:** O(n) — worst case, the stack holds every character (e.g. a string of all opening brackets).

## Solutions

- [Python](./solution.py)
- [C++](./solution.cpp)

## Notes

- **Python:** uses a plain `list` as the stack, via `.append()` (push) and `.pop()`, with `stack[-1]` used to peek at the top without removing it.
- **C++:** uses the dedicated `std::stack<char>` container (`#include <stack>`), which only exposes `.push()`, `.pop()`, `.top()`, and `.empty()` — enforcing "only touch the top" at the language level, unlike Python's list which *could* be misused to access the middle.
- One C++ gotcha: `.pop()` on `std::stack` does **not** return the removed value (unlike Python's `.pop()`) — use `.top()` first to read the value, then `.pop()` separately to remove it.
