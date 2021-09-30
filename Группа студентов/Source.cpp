#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <time.h>
#include <stdio.h>
using namespace std;

struct Student
{
	char Name[50];
	int Group;
	float Ses[5];
	float srbal = 0.0;
};

void goodswap(float& x, float& y)
{
	float temp = x;
	x = y;
	y = temp;
}
void goodswap2(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	const int N = 10;  //кол-во студентов
	Student Stud1[N];
	for (int i = 0; i < N; i++)
	{
		cout << "Введите фамилию и инициалы " << i + 1 << " Студента\n";
		cin >> Stud1[i].Name;
		cout << "Введите номер группы " << i + 1 << " Студента\n";
		cin >> Stud1[i].Group;
		cout << "Введите пять оценок " << i + 1 << " Студента\n";
		for (int j = 0; j < 5; j++)
		{
			cout << j + 1 << " Оценка студента\n";
			cin >> Stud1[i].Ses[j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		Stud1[i].srbal = (Stud1[i].Ses[0] + Stud1[i].Ses[1] + Stud1[i].Ses[2] + Stud1[i].Ses[3] + Stud1[i].Ses[4]) / 5;
	}

	int temp1;
	float temp2;
	char temp3[50];
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (Stud1[i].Group > Stud1[j + 1].Group)
			{
				temp1 = Stud1[i].Group;
				Stud1[i].Group = Stud1[j + 1].Group;
				Stud1[j + 1].Group = temp1;

				temp2 = Stud1[i].srbal;
				Stud1[i].srbal = Stud1[j + 1].srbal;
				Stud1[j + 1].srbal = temp2;

				strcpy(temp3, Stud1[i].Name);
				strcpy(Stud1[i].Name, Stud1[j + 1].Name);
				strcpy(Stud1[j + 1].Name, temp3);
			}
		}
	}
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		if (Stud1[i].srbal > 4)
		{
			flag++;
			cout << "\nСредний бал выше 4 у "<<Stud1[i].Name<<" Он составляет: "<< Stud1[i].srbal <<". "<< Stud1[i].Name <<" учится в "<<Stud1[i].Group<<" Группе.\n";
		}
	}

	if (flag == 0)
	{
		cout << "\n Нет студентов у которых средний бал выше 4\n";
	}




	return 0;
}