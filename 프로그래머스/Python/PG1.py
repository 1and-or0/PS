# �˾���2
# 11�ٿ��� ���ǻ��� raplace(a, "")���� �ۼ��� ���
# yayae��� ���ڿ��� Ȯ���� ��, ye�� ���ƹ��� ������ 
def solution(babbling):
    a_can = ["aya", "ye", "woo", "ma"]  # 2, 3, 1��   4, 5, 6, 2��   7, 8, 3��   10 4��

    answer = 0

    for word in babbling:
        for a in a_can:
            if a*2 not in word:
                word = word.replace(a, " ")
        if word.strip() == '':
            answer += 1
    return answer

