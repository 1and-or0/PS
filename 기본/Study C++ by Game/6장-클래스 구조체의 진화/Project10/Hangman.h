#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
#include <string>
#include <conio.h>

using namespace std;

class Hangman 
{
	string progress[64];  // ��� ���� ���� ��� �۸�
	string problem;   // ���� �ܾ�
	string answer;  // ���� ���� ���� �ܾ�

	string guessed; // ��ü ���ĺ��� ������� ���� ��Ȳ
	int nTries;   // ������� Ʋ�� Ƚ��
	const int maxTries = 7; // �ִ� ��� �õ� Ƚ�� ����

	void load(const char* fileName = "HangmanProgress.txt")
	{
		ifstream fs(fileName);
		if (fs)
		{
			getline(fs, progress[0]);  // ù ��° ���� �ּ� �������� from ����(.txt)
			for (int i = 0; i < 64; ++i)
			{
				getline(fs, progress[i]);
			}
		}
	}

	void print()
	{
		system("cls");
		cout << " <Hangman Game>\n";

		for (int i = 0; i < 8; ++i)
		{
			cout << '\t' << progress[nTries * 8 + i] << endl;
		}
		cout << "\n\t" << answer;
		cout << "\n\n" << guessed;
	}

	int countMatched(char ch)
	{
		int nMatched = 0;
		for (int pos = -1; ; )
		{
			pos = problem.find(ch, pos + 1);
			if (pos < 0)
			{
				break;
			}
			answer[pos] = ch;  // ���� �ܾ ���� (���� ���� ����)
			++nMatched;
		}
		return nMatched;
	}

	void guess()
	{
		char ch = _getch();
		if (ch >= 'a' && ch <= 'z')
		{
			int pos = guessed.find(ch);
			if (pos < 0)
			{
				guessed[ch - 'a'] = ch;
				if (countMatched(ch) == 0)
				{
					++nTries;
				}
			}
		}
	}

public:
	void play(string prob)
	{
		load();
		problem = prob;
		answer = string(problem.length(), '-');
		guessed = string(26, '.');
		nTries = 0;
		while (nTries < maxTries && answer != problem)
		{
			print();
			guess();
		}
		print();
		cout << "\n\t" << ((nTries == maxTries) ? "����" : "����") << endl;
	}
};