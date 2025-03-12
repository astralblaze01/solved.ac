import datetime as dt
import sys
import datetime
input = sys.stdin.readline

array = list(map(str, input().split()))
array[1] = array[1][:-1]
array.append(int(array[3][:2]))
array.append(int(array[3][-2:]))

dateDic = {"January": 1, "February": 2, "March": 3, "April": 4, "May": 5,
           "June": 6, "July": 7, "August": 8, "September": 9, "October": 10,
           "November": 11, "December": 12}

# for i in range(len(array)):
#     print(array[i])

today = datetime.datetime(
    year=int(array[2]), month=dateDic[array[0]], day=int(array[1]), hour=int(array[4]), minute=int(array[5]))

newDay = datetime.datetime(
    int(array[2]), 1, 1, 0, 0, 0)

difference = today - newDay

if(int(array[2])) % 400 == 0 or (int(array[2]) % 100 != 0 and int(array[2]) % 4 == 0):
    print((difference.total_seconds()/31622400) * 100)
else:
    print((difference.total_seconds()/31536000) * 100)
