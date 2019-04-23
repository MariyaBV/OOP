#pragma once
class CComplex
{
public:
	CComplex(double real, double image);
	~CComplex();

	double Re() const;
	double Im() const;
	double GetMagnitude() const;

private:
	double m_real = 0;
	double m_image = 0;
};
