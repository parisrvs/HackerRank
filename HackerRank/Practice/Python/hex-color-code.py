import re

n = int(input())
a = []
string = ''
for _ in range(n):
    s = input().strip()
    string += s

i = re.findall(r"(\{.*\}).*(\{.*\})", string)
if i:
    for j in i:
        for k in j:
            p = re.findall(r"#[A-Fa-f\d]{3,6}", k)
            if p:
                for q in p:
                    a.append(q)
else:
    i = re.findall(r"(\{.*\}).*(\{.*\})*", string)
    if i:
        for j in i:
            for k in j:
                p = re.findall(r"#[A-Fa-f\d]{3,6}", k)
                if p:
                    for q in p:
                        a.append(q)


for r in a:
    print(r)
    



#i = re.findall(r"#[A-Fa-f\d]{3,6}", string)
# s = """
# #BED
# {
#     color: #FfFdF8; background-color:#aef;
#     font-size: 123px;
#     background: -webkit-linear-gradient(top, #f9f9f9, #fff);
# }
# #Cab
# {
#     background-color: #ABC;
#     border: 2px dashed #fff;
# }
# """

# a = []
# c = s.split()
# for i in c:
#     i.strip()
#     print(i)
#     x = re.findall(r"#[a-fA-F0-9]{3,6}", i)
#     if x:
#         a.append(x)
# print(a)