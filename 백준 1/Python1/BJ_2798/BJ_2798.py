nums, goal = map(int, input().split())
values = []
list1 = list(map(int, input().split()))
for i in list1:
    list2 = [x for x in list1]
    list2.remove(i)
    for j in list2:
        list3 = [x for x in list2]
        list3.remove(j)
        for k in list3:
            y = i + j + k
            values.append(y)

# �ո������� ���� �� ����. gap �ʱⰪ
# ī�� �� ���� �ִ����� ������... 
values = set(values)
gap = sum(values)
result = sum(values)
for i in values:
    if gap > ((goal - i) if (goal - i)>0 else (goal - i)*-1):
        gap = ((goal - i) if (goal - i)>0 else (goal - i)*-1)
        result = i

print(result)
