def swap_case(s):
    string = ''
    for c in s:
        if c.islower() and c.isalpha():
            string += c.upper()
        elif c.isupper() and c.isalpha():
            string += c.lower()
        else:
            string += c

    return string

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)