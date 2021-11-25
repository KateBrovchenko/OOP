#pragma once

class ComplexNum
{
public:
	ComplexNum();
	ComplexNum(double material, double imaginary, const char* name);
	ComplexNum(ComplexNum& object);
	~ComplexNum();

	void SetMaterial(double material);
	void SetImaginary(double imaginary);
	void SetName(const char* name);
	void SetComplexNum(double material, double imaginary, const char* name);

	double GetMaterial();
	double GetImaginary();
	char* GetName();

	void CheckArraySize(const char* array);

	void PrintMaterial();
	void PrintImaginary();
	void PrintName();
	void PrintComplexNum();
private:
	double material_;
	double imaginary_;
	char* name_;
};