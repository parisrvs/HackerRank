def fun(s):
    try:
        l = s.split('@')
        username = l[0]
        l = l[1].split('.')
        website, extension = l[0], l[1]
    except:
        return False
    
    if not username or not website or not extension:
        return False
    
    alphabets_uppercase = [chr(i) for i in range(65, 91)]
    alphabets_lowercase = [chr(i) for i in range(97, 123)]
    numbers = [chr(i) for i in range(48, 58)]
    characters = ['-', '_']

    for c in username:
        if c not in alphabets_uppercase and c not in alphabets_lowercase and c not in numbers and c not in characters:
            return False
    for c in website:
        if c not in alphabets_uppercase and c not in alphabets_lowercase and c not in numbers:
            return False
    if len(extension) <= 3:
        for c in extension:
            if c not in alphabets_uppercase and c not in alphabets_lowercase:
                return False
    else:
        return False
    
    return True

def filter_mail(emails):
    return list(filter(fun, emails))

if __name__ == '__main__':
    n = int(input())
    emails = []
    for _ in range(n):
        emails.append(input())

filtered_emails = filter_mail(emails)
filtered_emails.sort()
print(filtered_emails)