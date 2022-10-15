def merge_the_tools(string, k):
    temp = 0
    l = []
    for c in range(0, len(string), k):
        temp = temp + k
        l.append(string[c:temp])
        
    counter = 1
    m = []
    s = ''
    for i in l:
        for j in i:
            if counter:
                s += j
                counter = 0
            elif j not in s:
                s += j
        m.append(s)
        s = ''
        counter = 1
    
    for i in m:
        print(i)
    return

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)