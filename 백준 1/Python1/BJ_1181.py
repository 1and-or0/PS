n = int(input())

str_s = []
for _ in range(n):
    str_s.append(input())

str_s = list(set(str_s))
str_s.sort(key=lambda x : (len(x), x))  # ��� ���̷� �켱 ����, ���Ŀ� ����������

for s in str_s:
    print(s)