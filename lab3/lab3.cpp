#include "Header.h"
#include "lab03.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ComplexNum* complex_nums;
	ComplexNum complex_for_constructor_demonstration(1.0, 1.0, "name");
	int menu;
	int material;
	int imaginary;
	int size;
	int i = 0;
	char name[256];

	cout << "Введіть кількість елементів таблиці: ";
	cin >> size;
	complex_nums = new ComplexNum[size];

	do
	{
		cout << "1.Задати лише дійсну частину;" << endl << "2.Задати лише уявну частину;" << endl << "3.Задати назву копмплексного числа;" << endl;
		cout << "4.Задати комплексне число повністю;" << endl << "5.Вивести лише дійсну частину;" << endl << "6.Вивести лише уявну частину;" << endl;
		cout << "7.Вивести назву комплексного числа;" << endl << "8.Вивести комплексне число повністю;" << endl << "9.Скопіювати комплексне число та вивести отриманий результат;" << endl;
		cout << "10.Додати новий елемент класу;"  << endl << "11.Завершити програму" << endl;

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
			cout << "Введіть назву для комплексного числа: ";
			cin >> name;
			complex_nums[i].SetName(name);
			break;
		case 4:
			cout << "Введіть дійсну частину: ";
			cin >> material;
			cout << "Введіть уявну частину: ";
			cin >> imaginary;
			cout << "Введіть назву для комплексного числа: ";
			cin >> name;
			complex_nums[i].SetComplexNum(material, imaginary, name);
			break;
		case 5:
			complex_nums[i].PrintMaterial();
			break;
		case 6:
			complex_nums[i].PrintImaginary();
			break;
		case 7:
			complex_nums[i].PrintName();
			break;
		case 8:
			complex_nums[i].PrintComplexNum();
			break;
		case 9:
		{
			ComplexNum complex_for_copy(complex_nums[i]);
			complex_for_copy.PrintComplexNum();
			break;
		}
		case 10:
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
		default:
			cout << "Завершення програми!";
			return 0;
			break;
		}
	} while (i < size);

	return 0;
}