if __name__ == '__main__':
    s = input()
    v = {
        "alnum": 0,
        "alpha": 0,
        "digit": 0,
        "lower": 0,
        "upper": 0
    }
    alnum, alpha, digit, lower, upper = 0, 0, 0, 0, 0
    for c in s:
        if c.isalnum():
            v["alnum"] = 1
        if c.isalpha():
            v["alpha"] = 1
        if c.isdigit():
            v["digit"] = 1
        if c.islower():
            v["lower"] = 1
        if c.isupper():
            v["upper"] = 1
    
    for i in v.keys():
        if v[i]:
            print(True)
        else:
            print(False)
        
    
