import datetime
import calendar
 
s = input()
s = datetime.datetime.strptime(s, '%m %d %Y').weekday()
print((calendar.day_name[s]).upper())