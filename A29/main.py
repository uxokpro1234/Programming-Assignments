def divide(i):
    for x in range(1, i + 1):
        if i % x == 0:
            dividers.append(x)

def findDividers():
    for i in range(len(dividers)):
        for j in range(i + 1, len(dividers)):
            if dividers[i] == dividers[j]:
                print(dividers[i], end=" ")
                break

while True:
    try:
        a, b = map(int, input("Enter two natural numbers: ").split())

        if a <= 0 or b <= 0:
            print("Error: numbers must be natural numbers!")
            continue

        dividers = []

        divide(a)
        divide(b)

        print("Dividers for both numbers: ", end=" ")
        findDividers()
        print()

        c = input("Do you want to continue? Y/n: ")

        if c.lower() != "y":
            break

    except ValueError:
        print("Error: incorrect data type!")
        continue
