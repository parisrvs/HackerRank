def count_substring(string, sub_string):
    count = 0
    while(True):
        index = string.find(sub_string)
        if index == -1:
            return count
        s = string[index:(index + len(sub_string))]
        if s == sub_string:
            count += 1
        string = string[index+1:]

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)