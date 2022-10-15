if __name__ == '__main__':
    grades = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        grades.append([name, score])
    
    grades = sorted(grades, key=lambda x: x[1])
    for c in range(1, len(grades)):
        if (grades[c][1] != grades[c-1][1]):
            lscore = grades[c][1]
            break
    
    grades = sorted(grades)
    for c in range(len(grades)):
        if (grades[c][1] == lscore):
            print(grades[c][0])
        

