from collections import Counter
import sys
input = sys.stdin.readline

n = int(input())

nums = []
for _ in range(n):
    nums.append(int(input()))

average = int(round(sum(nums)/n))
print(average)
nums.sort()
mid = nums[n//2]
print(mid)

# Counter(�迭) -> �迭�� ��� ���� ��ȯ

# Counter(�迭).most_common() -> �迭���� �ֺ� ��ȯ
# cnt = ����Ʈ ��ҷ� Ʃ���� ���� Ʃ���� (�ֺ�1, ����Ƚ��)�� ����
# �Ʒ��� ��� ���� �Է�3���� cnt = [(-2, 2), (-1, 2)]�� ������
most_nums = Counter(nums).most_common(2)

if len(most_nums) > 1:
    # �ֺ��� ���� Ƚ���� ������
    if most_nums[0][1] == most_nums[1][1]:
        print(most_nums[1][0]) # �ι�°�� ���� �� ���
    else: # �ƴϸ� �ֺ� ���
        print(most_nums[0][0])
else:
    print(most_nums[0][0])

print(max(nums)-min(nums))