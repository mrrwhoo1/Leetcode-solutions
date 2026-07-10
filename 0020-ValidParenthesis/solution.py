# def isValid(self, s: str) -> bool:
empty_stack = []
empty_closing = []

opening = ["(", "[", "{"]
closing_to_opening = {"(": ")", "{": "}", "[": "]"}


def check(p):
    index = 0
    first = empty_stack[index]
    first_closing = empty_closing[index]


user = input("Enter Parenthesis: ")
for i in user:
    if i in opening:
        empty_stack.append(i)
