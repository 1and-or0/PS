#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
// ��� �߻� ���
#include <assert.h>

// �Լ� �������̵��̶� �ٸ���!
// ���� �ܰ� ���� �Լ� �����ε� vs �������̵�

// �ε� �ҷ����� (���ҽ��� �޸𸮿�)
// �Լ� �����ε�: ���� �̸��� �Լ��� ������ �������!
// �Լ� �����ε�, ������ ����, ������ �ڷ������� �Լ��� �����ȴ�!
void Test(int a)
{

}

void Test(float a)
{

}


void Test(int a, int b)
{

}


// const �� �߰��� �Ű������� �ۼ������ν� �޾ƿ� �ּҸ� ���� ������ ���� ���� ��ȭ��Ű�� ���� ������ ���!

// ���ڿ��� ���� ���ϴ� �Լ�
unsigned int len(const wchar_t* p_str)
{ 
	// �ε��� 0�� ���� ������ ����
	// p_str[0];  // ������ �Ұ��� const pointer�� �޾ƿԱ� ������


	// tip from ���Ʈ�� ���Ӿ�ī����
	// �ݺ����� �ͼ����� ���� ��� ���ǿ� �ϴ� true�� �ְ� ����
	// �׸��� Ư�� ��Ȳ���� break; �� ���� ������ �ȴ�

	// ���� ���� Ȯ���ϴ� ���� 
	unsigned int index_ = 0;

	while (true)
	{
		// �޾ƿ� ���ڿ��� �ּҸ� ó������ �����ذ��� ��� ����
		wchar_t p_n_char = p_str[index_];
		p_n_char = p_str[index_];

		// null���ڴ� \0��
		if (p_n_char == '\0')
		{
			break;
		}
		else
		{
			++index_;
		}
		/*if ("\0" == p_n_char)
		{
			break;
		}
		else
		{
			++index_;
		}*/
	}

	return index_;
}


// ���ڿ� �̾���̱�
// ����ũ�μ���Ʈ ���۷��� ����
// ���ڿ��� �� ��ü�� ������ ����, �ּ��̴�
void Cat_(wchar_t* str1, unsigned int size_str3, const wchar_t* str2)
{
	int len_str1 = len(str1);
	int len_str2 = len(str2);

	if (size_str3 < len_str1 + len_str2 + 1)
	{
		assert(nullptr);
	}

	// str2�� ���ڿ��� str1 ���ڿ��� �߰��ϱ�
	for (int i = 0; i < len_str2 + 1; ++i)
	{
		str1[len_str1 + i] = str2[i];
	}

}

int main()
{
	// ���ڿ� ���� �˷��ִ� wsclen �Լ� ���� ������
	wchar_t name[10] = L"����� ���۵���";
	
	int len_name = len(name);
	

	wchar_t String1[100] = L"abc";
	wchar_t String2[100] = L"defghijklmnopqrstuvwxyz";

	wcscat_s(String1, 100, L"defghijklmnopqrstuvwxyz");

	wchar_t str1[20] = L"abcdef";
	wchar_t str2[10] = L"ghijklmn";
	Cat_(str1, 39, str2);


	//wcscmp(); // �����ϱ�
	// �� ���ڿ��� ���ڷ� ����
	// �� ���ڿ��� �Ϻ��ϰ� ��ġ�ϸ� 0, �ƴϸ� ???
	// �������� ���Ŀ��� (�ļ���, ������) �̸� ���, 1
	// (������, �ļ���)�̸� ����, -1
	// ����� ���� ��
	// �� �� ,,, �쿭�� �ƽ�Ű �ڵ��...

	printf("�ƾƾ�");

	return 0;
}