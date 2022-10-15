from operator import itemgetter

def person_lister(f):
    def inner(people):
        for p in people:
            p[2] = int(p[2])
        people.sort(key = lambda x:x[2])
        a = []
        for p in people:
            a.append(f(p))
        return a
    return inner

@person_lister
def name_format(person):
    return ("Mr. " if person[3] == "M" else "Ms. ") + person[0] + " " + person[1]

if __name__ == '__main__':
    people = [input().split() for i in range(int(input()))]
    print(*name_format(people), sep='\n')