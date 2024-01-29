tekst = "A flea and a fly flew up in a flue"
wzorzec = "fly flew"

print(wzorzec)
print(tekst)

for i in range(len(tekst) - len(wzorzec) + 1):
    podciag = tekst[i:i + len(wzorzec)]
    print("^" if podciag == wzorzec else " ", end="")

print("\n\n")