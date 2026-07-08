characters = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
}

user = input("enter character[s]: ")
new_list = list(user)
total = 0
for index, char in enumerate(new_list):
    current_val = characters[char]
    next_index = index + 1

    if next_index < len(new_list):
        next_char = new_list[next_index]
        next_val = characters[next_char]

        if current_val < next_val:
            total -= current_val
        else:
            total += current_val
    else:
        total += current_val
