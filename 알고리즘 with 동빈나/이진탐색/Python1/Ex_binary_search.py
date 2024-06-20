# -*- coding: euc-kr -*-
# visual studio python ���� ���� �ذ�
import sys
import io
sys.stdout = io.TextIOWrapper(sys.stdout.detach(), encoding = 'utf-8')
sys.stderr = io.TextIOWrapper(sys.stderr.detach(), encoding = 'utf-8')

# ����Ž��
# �ð����⵵: log N
# ���� Ƚ��: ���� 2��log N�� ���

# �ݺ��� ����
def binary_search_iterative(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            start = mid + 1
        elif array[mid] > target:
            end = mid -1
    
    return None


# ����� ����
def binary_search_recursive(array, target, start, end):
    if start > end:
        return None

    mid = (start + end) // 2
    
    if target == arr[mid]:
        return mid
    elif target > arr[mid]:
        return binary_search_recursive(array, target, mid + 1, end)
    else:
        return binary_search_recursive(array, target, start, mid - 1)

        
arr = [1, 3, 4, 5, 7, 8, 9, 11, 12, 14, 16, 18, 20]

n = int(input())

result = binary_search_iterative(arr, n, 0, len(arr)-1)

if result == None:
    print(f"n: {n}�� ����Ʈ {arr}�� �����ϴ�")    
else:
    print(f"n: {n}�� ����Ʈ{arr}�� �ֽ��ϴ�")

result = binary_search_recursive(arr, n, 0, len(arr)-1)

if result == None:
    print(f"n: {n}�� ����Ʈ{arr}�� �����ϴ�")
else:
    print(f"n: {n}�� ����Ʈ{arr}�� �ֽ��ϴ�")


