import math
AB, BC = float(input()), float(input())
theta = int(round(math.degrees(math.atan2(AB, BC))))
print(f"{theta}{chr(176)}")