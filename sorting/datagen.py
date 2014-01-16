import random

file = open("data", "w")

for i in range(1, 1000000):
    num = str(random.randint(1, 10000))
    file.write(num + " ")
