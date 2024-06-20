print("Hello world")

# �ݺ������� ������ ���丮��
def factorial_iterative(n):
    result = 1

    for i in range(1, n+1):
        result *= i 
    return result


# ��������� ������ ���丮��
def factorial_recursive(n):
    if n <= 1:
        return 1
    else:
        return n * factorial_recursive(n-1)

print("iterative", factorial_iterative(5))
print("recursive", factorial_recursive(5))