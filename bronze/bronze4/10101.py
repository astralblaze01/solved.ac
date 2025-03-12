a = int(input())
b = int(input())
c = int(input())

result = a + b + c
if(result != 180):
    print("Error")
elif(a == b == c == 60):
    print("Equilateral")
elif(result == 180 and (a == b or b == c or c == a)):
    print("Isosceles")
elif(result == 180 and (a != b or b != c or c != a)):
    print("Scalene")
