vowel = "aeuio"


def is_vowel(character):
    if character in vowel:
        return True
    return False


def main():
    cha = input("Please input a character:")
    print(cha, "is vowel--->", is_vowel(cha))


main()
