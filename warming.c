#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double nagrev(int q, double m1, double m2, int c1, int c2, double t0, double t1, double t2, int A) //���-� ��� ������� �-�� � �������� ���������� ���������
{
	double t;
	t = q*m2*1e6 / (c2*m1) + t2 - (t1 - t0)*c1/c2 - A*1e-3/c2;
	return t;
}


double en_nagr(int c, double m, double t0, double t) //������� ��� ������� 
{
	double N;
	N = c*m*1e-3*fabs(t - t0);
	return N;
}

int main()
{
    int q, A, c1, c2, L, t0, t1, t2; //t - ����������� ����
    double m1, m2, t, Q, P, G;
    scanf_s("%d %lf\n", &q, &m2); //q(���/��) - �������� ������� �������� �������, m2(�) - ����� ��������
    scanf_s("%lf %d\n", &m1, &t0); //m1(�) - ����� �����������, to(�������) - ��� ��������� �����������
    scanf_s("%d\n", &c1); //c1(��/��/��) - �������� ����������� ������� �������� � ������ ���������
    scanf_s("%d %d\n", &A, &t1); //A(���/��) - �������� ������� ��������� ��������, t1(��) - ����������� ���������;
    scanf_s("%d\n", &c2); //c2(��/��/��) - �������� ����������� ������� �������� � ������ ���������
    scanf_s("%d %d", &L, &t2); //L(� ���/��) - �������� ������� ��������������� � ����������� ��������, t2(��) - ����������� �������.
//����� ������� L � � � ����, ���� ��� ����� ����, �� ����� ��������, � ����� ��������� ���������� ���� �-��, �� ���� ����������� ��������� �/��� ��������������� �� ������
	Q = q*m2*1e3; //������� ��������
	P = A*m1*1e-3; //������� ���������
	G = L*m1*1e-3; //������� ���������������
	
	if ((A != 0) && (L != 0)) //�� ���� ������ ����������� ��������� � ���������������
	{
		if (t0 <= t1)//�� ���� � ������ ���������
		{
			if (Q <= en_nagr(c1, m1, t0, t1))//��� �� ������ ���������
				//t = nagrev(q, m2, c1, m1, t0);
				t = nagrev(q, m1, m2, 0, c1, 0, 0, t0, 0);
			else if (Q <= (en_nagr(c1, m1, t0, t1) + P))//������������ �� �� �����
				t = t1;
			else if (Q <= (c1*m1*1e-3*abs(t1 - t0) + P + c2*m1*1e-3*abs(t2 - t1)))//��� �� ������ ������
				//t = nagrev(q, m2, c2, m1, t1) - A*1e3 / c2 - (c1*(t1 + 273.15)) / c2 + (c1*(t0 + 273.15)) / c2;
				t = nagrev(q, m1, m2, c1, c2, t0, t1, t2, A);
			else if (Q < (en_nagr(c1, m1, t0, t1) + P + en_nagr(c2, m1, t1, t2) + G))//������ ��������
				t = t2;
			else //��������
				t = -1;
		}

		else if (t0 >= t1 && t0 <= t2)//� ������ ���������
		{
			if (Q <= (c2*m1*1e-3*abs(t2 - t0)))//��� �� ������ ������
				//t = q*m2*1e6 / (c2*m1) + t0;
				t = nagrev(q, m1, m2, 0, c2, 0, 0, t0, 0);
			else if (Q < (c2*m1*1e-6*abs(t2 - t0) + P))//������ ��������
				t = t2;
			else //��������
				t = -1;
		}
		else //� ������������ ���������
			t = -1;

		printf("%lf\n", t);
	}
	
    return 0;
}