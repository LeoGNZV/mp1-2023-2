#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void main() {
	int n, num = 0, k = 0;
	int attempt = 0;
	int bull = 0, cow = 0;
	int mas[5] = {-1, -1, -1, -1, -1};
	srand(time(0));
	setlocale(LC_ALL, "rus");
	printf("������� ����� ������������� ����� � ���������� �� 2 �� 5 ������������: ");
	scanf("%d", &n);
	while (!(2 <= n && n <= 5)) {
		printf("�� ����� ����� ����� �����������, ������� ����� � ���������� �� 2 �� 5 ������������: ");
		scanf("%d", &n);
	} 
	int p = 1;
	while (!(pow(10, (n-1)) <= num && num < pow(10, n))) {
		int c = (rand()) % 9 + 1;
		for (int i = 0; i < n; i++)
		{
			if (c == mas[0] || c == mas[1] || c == mas[2] || c == mas[3] || c == mas[4])
				while (c == mas[0] || c == mas[1] || c == mas[2] || c == mas[3] || c == mas[4])
					c = (rand()) % 9 + 1;
		}
		mas[k] = c;
		num += c * p;
		p *= 10;
		k++;
	}
	printf("��������� �������� ����� ������� %d � ���������������� �������\n", n);
	printf("%d %d", (int)pow(10, n), (int)pow(10, (n - 2)));
	while (attempt != num) {
		printf("�������� ������� ������� �����: ");
		scanf("%d", &attempt);
		for (int i = 0; i < n; i++)
		{
			int figure_attempt = attempt % (int)pow(10, (n - i)) / pow(10, (n - i - 1));
			for (int j = n; j != 0; j--)
			{
				if ((mas[j-1]) == figure_attempt)
				{
					if (i ==  n - j)
						bull++;
					else
						cow++;
				}
			}
		}
		if (bull == n)
		{
			printf("�� ���������! �� �������! �� ������ ����� ������� �����! ");
			break;
		}
		printf("<< ���������� �����: %d. ���������� �����: %d.\n", cow, bull);
		printf("���� ������ ��������� ����, ������� 0, ���� ������ ���������� ������� ����� ������ ������: ");
		char d;
		scanf("%c", &d);
		int �;
		while ((� = getchar()) != '\n' && � != EOF) {}
		if (d == '0') {
			printf("�� ��������� ����, �� ��������, �� ����� ������! ");
			break;
		}
		bull = 0;
		cow = 0;
	}
	system("pause");
}