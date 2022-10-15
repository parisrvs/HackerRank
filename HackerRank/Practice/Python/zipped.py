count_students, count_subjects = map(int, input().split())
students = [i for i in range(1, count_students+1)]
grades = [students, ]
for _ in range(count_subjects):
    l = list(map(float, input().split()))
    grades.append(l)

gradesheet = zip(*grades)
for item in gradesheet:
    l = list(item[1:])
    print(f"{sum(l)/len(l):.1f}")











#This function returns a list of tuples.
#The i'th tuple contains the i'th element from each of the argument sequences or iterables.
#If the argument sequences are of unequal lengths,
# then the returned list is truncated to the length of the shortest argument sequence.

#>>> print zip([1,2,3,4,5,6],'Hacker')
#[(1, 'H'), (2, 'a'), (3, 'c'), (4, 'k'), (5, 'e'), (6, 'r')]
#>>> 
#>>> print zip([1,2,3,4,5,6],[0,9,8,7,6,5,4,3,2,1])
#[(1, 0), (2, 9), (3, 8), (4, 7), (5, 6), (6, 5)]
#>>> 
#>>> A = [1,2,3]
#>>> B = [6,5,4]
#>>> C = [7,8,9]
#>>> X = [A] + [B] + [C]
#>>> 
#>>> print zip(*X)
#[(1, 6, 7), (2, 5, 8), (3, 4, 9)]