# 0021 - Merge Two Sorted Lists

**Difficulty:** Easy
**Link:** https://leetcode.com/problems/merge-two-sorted-lists/

## Problem

Given the heads of two sorted linked lists, merge them into one single sorted linked list, and return its head. The merged list should be made by splicing together the nodes of the two input lists — no new nodes are created for the values themselves.

Example: `list1 = 1→2→4`, `list2 = 1→3→4` → merged: `1→1→2→3→4→4`.

## Approach (Two-Pointer Merge)

This is the first linked list problem in the repo — a linked list is a chain of individually-allocated **nodes**, each holding a value and a pointer to the next node, rather than a contiguous block like an array/Python list. You can't jump to a random position; the only way to reach any node is to follow pointers one step at a time from the head.

Since both input lists are already sorted individually, the merge doesn't need a full sort — just a single pass comparing the two lists' current nodes and picking the smaller one each time (the same core idea behind the merge step of merge sort):

1. Create a **dummy placeholder node** to act as a starting handle for the new merged chain, and a `tail` pointer starting at that dummy node (tracking "the current end of the merged chain so far").
2. While both lists still have nodes remaining:
   - Compare the current node's value in `list1` vs `list2`.
   - Attach whichever is smaller onto `tail.next`, and advance that list's pointer to its next node.
   - Advance `tail` to the node just attached, so the next attachment extends the chain instead of overwriting the previous link.
3. Once one list runs out, the other list's remaining nodes are already sorted relative to each other — attach the rest of that leftover chain directly onto `tail.next`, no more comparisons needed.
4. Return the node after the dummy (skipping over the placeholder itself, which was never part of the real result).

## Complexity

- **Time:** O(n + m) — where n and m are the lengths of list1 and list2; every node from both lists is visited exactly once.
- **Space:** O(1) extra space — no new nodes are created; existing nodes are re-linked in place.

## Solutions

- [Python](./solution.py)
- [C++](./solution.cpp)

## Notes

- The dummy-node pattern is a common trick for building a new linked list from scratch: without it, there's nothing to attach the very first real node onto (attaching to `None`/`nullptr` directly would crash), so a throwaway placeholder node solves that bootstrapping problem cleanly.
- **Python:** `tail.next = list1 if list1 else list2` handles the leftover-list step — whichever list still has nodes remaining (is truthy, i.e. not `None`) gets attached wholesale.
- **C++:** nodes are accessed through pointers (`ListNode*`), so member access uses `->` instead of `.` (e.g. `list1->val`, `list1->next`). The dummy node itself is a plain stack-allocated `ListNode`, with `tail` initialized to its address (`&dummy`) so it can be reassigned as the chain grows. The leftover-list step uses C++'s ternary operator: `list1 ? list1 : list2`.
