#include "Header.h"
#include "lab04.h"

ComplexNum::ComplexNum()
{
	material_ = 0;
	imaginary_ = 0;
	name_ = nullptr;
}

ComplexNum::ComplexNum(double material, double imaginary, const char* name)
{
	material_ = material;
	imaginary_ = imaginary;
	name_ = new char[strlen(name) + 1];
	CheckArraySize(name);
	strcpy(name_, name);
}

ComplexNum::ComplexNum(ComplexNum& object)
{
	this->material_ = object.GetMaterial();
	this->imaginary_ = object.GetImaginary();
	this->name_ = new char[strlen(object.GetName()) + 1];
	CheckArraySize(this->name_);
	strcpy(this->name_, object.GetName());
}

ComplexNum::~ComplexNum()
{
	delete name_;
}

void ComplexNum::SetMaterial(double material)
{
	material_ = material;
}

void ComplexNum::SetImaginary(double imaginary)
{
	imaginary_ = imaginary;
}

void ComplexNum::SetName(const char* name)
{
	name_ = new char[strlen(name) + 1];
	CheckArraySize(name_);
	strcpy(name_, name);
}

void ComplexNum::SetComplexNum(double material, double imaginary, const char* name)
{
	SetMaterial(material);
	SetImaginary(imaginary);
	SetName(name);
}

double ComplexNum::GetMaterial()
{
	return material_;
}

double ComplexNum::GetImaginary()
{
	return imaginary_;
}

char* ComplexNum::GetName()
{
	return name_;
}

void ComplexNum::CheckArraySize(const char* array)
{
	if (array == nullptr)
	{
		cout << "Не було успішно створено масив! Екстрене завершення програми!" << endl;
		exit(0);
	}
}

void ComplexNum::PrintMaterial()
{
	cout << "Дійсна: " << material_ << endl;
}

void ComplexNum::PrintImaginary()
{
	cout << "Уявна: " << imaginary_ << endl;
}

void ComplexNum::PrintName()
{
	if (name_ != nullptr)
	{
		cout << "Назва числа: " << name_ << endl;
	}
	else
	{
		cout << "Назва не задана" << endl;
	}
}

void ComplexNum::PrintComplexNum()
{
	if (name_ != nullptr)
	{
		cout << name_ << endl;
	}
	else
	{
		cout << "Назва не задана" << endl;
	}

	if (material_ != 0 && imaginary_ != 0)
	{
		cout << material_ << " + " << imaginary_ << "i" << endl;
	}
	else if (material_ == 0)
	{
		cout << imaginary_ << "i" << endl;
	}
	else if (imaginary_ == 0)
	{
		cout << material_ << endl;
	}
	else
	{
		cout << "Всі значення рівні 0!";
	}
}

ComplexNum& ComplexNum::operator+(ComplexNum object)
{
	this->material_ += object.GetMaterial();
	this->imaginary_ += object.GetImaginary();

	/*int length = strlen(this->GetName());
	this->name_ = new char[length + strlen(object.GetName()) + 1];
	strcat(result.name_, object.GetName());*/

	return *this;
}

ComplexNum& ComplexNum::operator*(ComplexNum object)
{
	int material = this->material_;
	int imaginary = this->imaginary_;

	this->material_ = material * object.GetMaterial() - imaginary * object.GetImaginary();

	this->imaginary_ = material * object.GetImaginary() + imaginary * object.GetMaterial();

	return *this;
}

ComplexNum& ComplexNum::operator/(ComplexNum object)
{
	int material = this->material_;
	int imaginary = this->imaginary_;

	this->material_ = (material * object.GetMaterial() + imaginary * object.GetImaginary()) / (pow(object.GetMaterial(), 2) + pow(object.GetImaginary(), 2));

	this->imaginary_ = (imaginary * object.GetMaterial() - material * object.GetImaginary()) / (pow(object.GetMaterial(), 2) + pow(object.GetImaginary(), 2));

	return *this;
}

bool ComplexNum::operator==(ComplexNum object)
{
	if (name_ != nullptr && object.GetName() != nullptr)
	{
		if (material_ == object.GetMaterial() && imaginary_ == object.GetImaginary() && strcmp(name_, object.GetName()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (name_ == nullptr && object.GetName() == nullptr)
	{
		if (material_ == object.GetMaterial() && imaginary_ == object.GetImaginary())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}