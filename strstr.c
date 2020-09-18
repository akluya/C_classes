#include <stdio.h>
#include <stdlib.h>
char *my_strstr(const char *str, const char *substr)
{
	unsigned int a, b, i, j = 0;
	for (a = 0; str[a]; a++); //����� ������
	for (b = 0; substr[b]; b++); //����� ���������
	for (i = 0; i < a; i++)
	{
		if (str[i] != substr[j] && j != b)
		{
			if (j != 0)
				i -= j;
			j = 0;
		}
		else if (str[i] == substr[j] && j != b)
			j++;
		else
			break;
	}
	if (j == b)
		return &str[i - j];
	if (j != b)
		return NULL;
	return 0;
}
/*{
	unsigned int a, b, i, j, n;
	int p;
	for (a = 0; str[a]; a++); //����� ������
	for (b = 0; substr[b]; b++); //����� ���������
	j = b;
	for (i = a; i >= 0; i--)
	{
		if (str[i] != substr[j] && j != 0)
			j = b;
		else if (str[i] == substr[j] && j != 0)
			j--;
		else
			break;
	}
	if (j == 0)
		p = &str[i - j];
	if (j != 0)
		p = NULL;
	return p;
}*/

int main()
{
	char str[50] = "qwertyaaaabcsd", substr[20] = "aaab"; //������ � ���, ��� �� ��� � ������, ������� ���� �� ������������� ���� ����� ��������
	char *s;
	s = my_strstr(str, substr);
	printf("%s\n", s);	
	return 0;
}