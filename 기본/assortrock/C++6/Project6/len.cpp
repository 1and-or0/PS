#include <stdio.h>
#include <wchar.h>

// �����ڵ� ���ڸ� ����ϱ� ���� ������� tchar
#include <tchar.h>
// ���������� ���ֱ� ���� ������� locale
#include <locale.h>

// ���ڿ� ���� ���ϴ� �Լ�
unsigned int len(const wchar_t* str)
{
	unsigned int len = 0;

	// ���� ����'' ���ڿ�"", '\0': null ����
	// ����2 *(str + len) == str[len]
	// ����3 ���Ǻ� �ۼ��� ��� == ���� �̷������� �ۼ��ϸ�
	// ==�� ��Ÿ���� =�� �ۼ��� ��� ������ ���� ������ ����
	// �������� ���̸� ����!
	while (str[len] != '\0')
	{
		++len;
	}

	return len;
}

int main()
{
	wchar_t name1[10] = L"����� ���۵���";

	int len_name1 = len(name1);
	printf("%d\n", len(name1));
	wprintf(L"%s\n", name1);
	wprintf(L"%c\n", name1[0]);
	
	// ������ �ѱ����� �������ִ� �κ� L"kroean", L"������"
	_tsetlocale(LC_ALL, L"korean");

	// _TCHAR ��� �ڷ����� �����ڵ� ���� �ڷ����̰� ũ��� 2byte��. 2byte �迭�� ������� 
	_TCHAR name2[10] = L"����� ���۵���";

	int len_name2 = len(name2);
	printf("%d\n", len(name2));
	// �����ڵ� ���ڸ� ����ϴ� �Լ��� printf�� �ƴ϶� _tprintf��
	// ���ڿ� ��� ��ȣ�� %s, ���� ��� ��ȣ�� %c��
	_tprintf(L"%s\n", name2);
	_tprintf(L"%c\n", name2[0]);



	return 0;
}