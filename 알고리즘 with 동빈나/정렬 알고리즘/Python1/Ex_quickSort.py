# �� ���� ��� �ð����⵵: O(NlongN), �־�: O(N^2)
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

# �� ���� �Լ�(�迭, ���� �ε���, �� �ε���)
def quick_sort(array, start, end):
    if start >= end:  # ���Ұ� 1���� ��� ����
        return

    pivot = start  # �ǹ�(= ���ذ�)�� ù ��° ����
    left = start + 1
    right = end

    # left�� right�� ����Ű�� ���� ���� �������� ������: ��
    while left <= right:
        # �ǹ����� ū �����͸� ã�� ������ �ݺ�
        while (left <= end and array[left] <= array[pivot]):
            left += 1

        # �ǹ����� ���� �����͸� ã�� ������ �ݺ�
        while(right > start and array[right] >= array[pivot]):
            right -= 1

        # ������ ��� left�� ����Ų �����Ϳ� pivot�� swap
        if left > right:
            array[right], array[pivot] = array[pivot], array[right]
        else: # left�� right�� ����Ű�� ������ swap
            array[left], array[right] = array[right], array[left]

    # ���� ���� pivot�� �������� ���ʰ� ������ ���� ���� ���� 
    quick_sort(array, start, right - 1)  # array[right]: pivot
    quick_sort(array, right + 1, end)  # array[right]: pivot


quick_sort(array, 0, len(array)-1)
print(array)
