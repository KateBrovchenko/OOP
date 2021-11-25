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

	cout << "������ ������� �������� �������: ";
	cin >> size;
	complex_nums = new ComplexNum[size];

	do
	{
		cout << "1.������ ���� ����� �������;" << endl << "2.������ ���� ����� �������;" << endl << "3.������ ����� ������������� �����;" << endl;
		cout << "4.������ ���������� ����� �������;" << endl << "5.������� ���� ����� �������;" << endl << "6.������� ���� ����� �������;" << endl;
		cout << "7.������� ����� ������������ �����;" << endl << "8.������� ���������� ����� �������;" << endl << "9.��������� ���������� ����� �� ������� ��������� ���������;" << endl;
		cout << "10.������ ����� ������� �����;"  << endl << "11.��������� ��������" << endl;

		cout << "������ ������ ����: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "������ ����� �������: ";
			cin >> material;
			complex_nums[i].SetMaterial(material);
			break;
		case 2:
			cout << "������ ����� �������: ";
			cin >> imaginary;
			complex_nums[i].SetImaginary(imaginary);
			break;
		case 3:
			cout << "������ ����� ��� ������������ �����: ";
			cin >> name;
			complex_nums[i].SetName(name);
			break;
		case 4:
			cout << "������ ����� �������: ";
			cin >> material;
			cout << "������ ����� �������: ";
			cin >> imaginary;
			cout << "������ ����� ��� ������������ �����: ";
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
				cout << "������!" << endl;
			}
			else
			{
				cout << "������ ������ ���������!" << endl;
			}
			break;
		default:
			cout << "���������� ��������!";
			return 0;
			break;
		}
	} while (i < size);

	return 0;
}