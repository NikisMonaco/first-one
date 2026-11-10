import random
print('Добро пожаловать в числовую угадайку')
count = 0
def is_valid(num):
    return num.isdigit() and 1 <= int(num) <= 100

def is_valid_num(): 
    global count   
    while True:
        num = input("Введите число от 1 до 100: ")
        if is_valid(num):
            count += 1
            return int(num)
        else:
            print("А может быть все-таки введем целое число от 1 до 100?\n")
def compare_num(n):
    global count
    while True:
        x = is_valid_num()
        if x < n:
            print('Ваше число меньше загаданного, попробуйте еще разок')
        elif x > n:
            print('Ваше число больше загаданного, попробуйте еще разок')
        elif x == n:
            print(f'Вы угадали, поздравляем! {n}')
            break
n = random.randint(1, 100)        
compare_num(n)
print(f"Попыток потрачено: {count}")         
print('Спасибо, что играли в числовую угадайку. Еще увидимся...')   
                                      
    