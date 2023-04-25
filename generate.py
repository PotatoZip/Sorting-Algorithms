import random

# open file for writing
with open('dane_losowe.txt', 'w') as file:
    # generate and write random numbers to file
    for i in range(10000000):
        random_num = random.randint(-100, 100)
        file.write(str(random_num) + ' ')


