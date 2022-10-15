def minion_game(string):
    vowels = "AEIOU"
    kevin = 0
    stuart = 0
    l = len(string)
    for c in range(len(string)):
        if string[c] in vowels:
            kevin += l - c
        else:
            stuart += l - c
    
    if kevin > stuart:
        print("Kevin", kevin)
    elif kevin < stuart:
        print("Stuart", stuart)
    else:
        print("Draw")
    return

if __name__ == '__main__':
    s = input()
    minion_game(s)