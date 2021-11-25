#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <windows.h>
using namespace std;

class ComplexNum
{
	public:
		ComplexNum();

		void SetMaterial(double material);
		void SetImaginary(double imaginary);
		void SetComplexNum(double material, double imaginary);

		double GetMaterial();
		double GetImaginary();

		void PrintMaterial();
		void PrintImaginary();
		void PrintComplexNum();
	private:
		double material_;
		double imaginary_;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ComplexNum* complex_nums;
	int menu;
	int material;
	int imaginary;
	int size;
	int i = 0;

	cout << "Введіть кількість елементів таблиці: ";
	cin >> size;
	complex_nums = new ComplexNum[size];

	do
	{
		cout << "1.Задати лише дійсну частину;" << endl << "2.Задати лише уявну частину;" << endl << "3.Задати комплексне число повністю;" << endl;
		cout << "4.Вивести лише дійсну частину;" << endl << "5.Вивести лише уявну частину;" << endl << "6.Вивести комплексне число повністю;" << endl;
		cout << "7.Додати новий елемент класу;" << endl << "8.Вивести таблицю;" << endl << "9.Завершити програму" << endl;

		cout << "Оберіть варіант меню: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "Введіть дійсну частину: ";
			cin >> material;
			complex_nums[i].SetMaterial(material);
			break;
		case 2:
			cout << "Введіть уявну частину: ";
			cin >> imaginary;
			complex_nums[i].SetImaginary(imaginary);
			break;
		case 3:
			cout << "Введіть дійсну частину: ";
			cin >> material;
			cout << "Введіть уявну частину: ";
			cin >> imaginary;
			complex_nums[i].SetComplexNum(material, imaginary);
		
			break;
		case 4:
			complex_nums[i].PrintMaterial();
			break;
		case 5:
			complex_nums[i].PrintImaginary();
			break;
		case 6:
			complex_nums[i].PrintComplexNum();
			break;
		case 7:
			if (i < size)
			{
				i++;
				cout << "Додано!" << endl;
			}
			else
			{
				cout << "Більше додати неможливо!" << endl;
			}
			break;

		case 8:
			
			cout << "| Дійсна частина |    Уявна частина  |\n";
			cout << "|________________|___________________|\n";
			for (int i = 0; i < size; i++) {
				cout << "|      ";
				cout << complex_nums[i].GetMaterial();
				cout << "         |    ";
				cout << complex_nums[i].GetImaginary();
				cout << "              |\n";	
				cout << "|________________|___________________|\n";
			}
			break;
		default:
			cout << "Завершення програми!";
			return 0;
			break;
		}
	} while (i < size);

	return 0;
}

ComplexNum::ComplexNum()
{
	material_ = 0;
	imaginary_ = 0;
}

void ComplexNum::SetMaterial(double material)
{
	material_ = material;
}

void ComplexNum::SetImaginary(double imaginary)
{
	imaginary_ = imaginary;
}

void ComplexNum::SetComplexNum(double material, double imaginary)
{
	SetMaterial(material);
	SetImaginary(imaginary);
}


double ComplexNum::GetMaterial()
{
	return material_;
}

double ComplexNum::GetImaginary()
{
	return imaginary_;
}

void ComplexNum::PrintMaterial()
{
	cout << "Дійсна: " << material_ << endl;
}

void ComplexNum::PrintImaginary()
{
	cout << "Уявна: " << imaginary_ << endl;
}

void ComplexNum::PrintComplexNum()
{
	if (material_ != 0 && imaginary_ != 0)
	{
		cout << material_ << " + " << imaginary_ << "i" << endl;
	}
	else if (material_ == 0)
	{
		cout << imaginary_ << "i" << endl;
	}
	else if(imaginary_ == 0)
	{
		cout << material_ << endl;
	}
	else
	{
		cout << "Всі значення рівні 0!";
	}
}

