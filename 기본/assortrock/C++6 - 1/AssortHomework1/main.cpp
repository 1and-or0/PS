#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>

int wcscmp_(const wchar_t* str1, const wchar_t* str2)
{
	int result = 0;

	unsigned int i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[i])
		{
			result = 0;
		}
		else
		{
			if (str1[i] < str2[i])
			{
				result = -1;
			}
			else if (str1[i] > str2[i])
			{
				result = 1;
			}
			break;
		}

		++i;
	}

	return result;
}

// ���ڿ� ���� ���ϴ� �Լ� 
unsigned int len(const wchar_t* str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		++i;
	}
	return i;
}

// ���ڿ�[�迭] ��ġ�� �Լ� - 
void str_str_p(wchar_t* str1, const wchar_t* str2)
{
	if (false)
	{
		assert(nullptr);
	}

	int len_str2 = len(str2);

	for (int i = 0; i < len_str2 + 1; ++i)
	{	
		str1[len(str1) + i] = str2[i];
	}
}

//
//typedef struct MyStruct1
//{
//	wchar_t wchar;
//	wchar_t* p_wchar;
//	int i = len(p_wchar);
//}StrSize;
//
//
//
//
//// ���ڿ� ��ġ�� �Լ� - 
//wchar_t* new_str_str(wchar_t* str1, wchar_t* str2)
//{
//	wchar_t str3[] = L"";
//	
//
//	for (int i = 0; i < len(str1); ++i)
//	{
//		str3[i] = str1[i];
//		
//	}
//	for (int i = 0; i < len(str2); ++i)
//	{
//		str3[len(str1) + i] = str2[i];
//	}
//
//	return str3;
//}
//
//
//// ���ڿ� ��ġ�� �Լ� - 
//wchar_t* new_str_str(StrSize a1, StrSize* a2)
//{
//
//	wchar_t str3[a1.i + a2.i] = L"";
//
//
//	for (int i = 0; i < len(str1); ++i)
//	{
//		str3[i] = str1[i];
//
//	}
//	for (int i = 0; i < len(str2); ++i)
//	{
//		str3[len(str1) + i] = str2[i];
//	}
//
//	return str3;
//}



int main()
{
	int value_ = wcscmp_(L"abc", L"abc");
	
	// ���� ���ڴ� �ƽ�Ű�ڵ�� ũ��񱳰� �����ϴ�!
	// �̰� ���̽��̶� �Ȱ���?
	/*wchar_t a = L'a';
	wchar_t b = L'b';
	wchar_t d = L'd';

	printf("%d\n", a > b);
	printf("%d\n", b > d);
	printf("%d\n", a > d);*/

	wchar_t str1[10] = L"abc";
	wchar_t str2[10] = L"def";

	str_str_p(str1, L"def");
	



	// �ڽ�
	/*StrSize str_size1;
	StrSize str_size2;
	str_size1.p_wchar = str1;
	str_size2.p_wchar = str2;


	wchar_t str3[] = new_str_str(str1, str2);

	wchar_t str3[] = new_str_str(str1, str2);*/

	return 0;
}