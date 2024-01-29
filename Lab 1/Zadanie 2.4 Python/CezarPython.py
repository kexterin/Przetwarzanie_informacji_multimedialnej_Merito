s = input()

result = ""
for char in s:
    char = char.upper()
    if 'A' <= char <= 'Z':
        char = chr(65 + (ord(char) - 62) % 26)
    result += char

print(result)