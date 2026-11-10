import random
digits = '0123456789'
lowercase_letters = 'abcdefghijklmnopqrstuvwxyz'
uppercase_letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
punctuation = '!#$%&*+-=?@^_'
chars = ''

pw_cnt = input("Укажите количество паролей для генерации ")    
pw_len = input("Укажите длину одного пароля ")
pw_dig = input("Включать ли цифры 0123456789 (YES/NO) ")
pw_uppercase = input("Включать ли прописные буквы ABCDEFGHIJKLMNOPQRSTUVWXYZ (YES/NO) ")
pw_lowercase = input("Включать ли строчные буквы abcdefghijklmnopqrstuvwxyz (YES/NO) ")
pw_punctuation = input("Включать ли символы !#$%&*+-=?@^_ (YES/NO) ")
pw_exceptions = input("Исключать ли неоднозначные символы il1Lo0O (YES/NO) ")
if pw_dig.lower() == "yes":
    chars += digits
if pw_uppercase.lower() == "yes":
    chars += uppercase_letters
if pw_lowercase.lower() == "yes":
    chars += lowercase_letters
if pw_punctuation.lower() == "yes":
    chars += punctuation
if pw_exceptions.lower() == "yes":
    for i in 'il1Lo0O':
        chars = chars.replace(i, '')   
def generate_password(length, chars):
    return ''.join(random.choice(chars) for _ in range(length))
for _ in range(int(pw_cnt)):
    print(generate_password(int(pw_len), chars))             