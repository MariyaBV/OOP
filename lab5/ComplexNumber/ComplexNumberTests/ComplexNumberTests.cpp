#include "pch.h"
#include "../ComplexNumber/CComplex.h"

SCENARIO("methods of complex number")
{
	GIVEN("real and image")
	{
		WHEN("real and image not 0")
		{
			CComplex complexNumber(15.2, 4.369);

			THEN("can find out real and image")
			{
				CHECK(complexNumber.Re() == Approx(15.2));
				CHECK(complexNumber.Im() == Approx(4.369));
			}
		}
		AND_WHEN("real and image negative")
		{
			CComplex complexNumber(-10.25, -4.369);

			THEN("can find out real and image")
			{
				CHECK(complexNumber.Re() == Approx(-10.25));
				CHECK(complexNumber.Im() == Approx(-4.369));
			}
		}
	}

	GIVEN("Get Magnitude")
	{
		WHEN("real and image exists")
		{
			CComplex complexNumber(1.2, 5.6);

			THEN("get magnitude")
			{
				CHECK(complexNumber.GetMagnitude() == Approx(5.727).epsilon(0.0001));
			}
		}
		AND_WHEN("real or image negative")
		{
			CComplex complexNumber(-1.2, -5.6);

			THEN("get magnitude")
			{
				CHECK(complexNumber.GetMagnitude() == Approx(5.727).epsilon(0.0001));
			}
		}
	}

	GIVEN("get argument")
	{
		WHEN("real and image = 0")
		{
			CComplex complexNumber(0, 0);
			THEN("return error")
			{
				CHECK_THROWS_WITH(complexNumber.GetArgument(), "Error. Usage: argument from real != 0.\n");
			}
		}
		AND_WHEN("real = 0, image not 0")
		{
			CComplex complexNumber(0, 0.5);

			THEN("return argument")
			{
				CHECK_THROWS_WITH(complexNumber.GetArgument(), "Error. Usage: argument from real != 0.\n");
			}
		}
		AND_WHEN("real not 0, image = 0")
		{
			CComplex complexNumber(0.5, 0);

			THEN("return 0")
			{
				CHECK(complexNumber.GetArgument() == 0);
			}
		}
		AND_WHEN("real and image not 0, all parameters > 0")
		{
			CComplex complexNumber(0.5, 0.5);

			THEN("return argument")
			{
				CHECK(complexNumber.GetArgument() == Approx(0.785398).epsilon(0.0001));
			}
		}
		AND_WHEN("real and image not 0, all parameters < 0")
		{
			CComplex complexNumber(-0.5, -0.5);

			THEN("return argument")
			{
				CHECK(complexNumber.GetArgument() == Approx(-2.35619449).epsilon(0.0001));
			}
		}
		AND_WHEN("real < 0 and image > 0")
		{
			CComplex complexNumber(-0.5, 0.5);

			THEN("return argument")
			{
				CHECK(complexNumber.GetArgument() == Approx(2.35619449).epsilon(0.0001));
			}
		}
		AND_WHEN("real > 0 and image < 0")
		{ 
			CComplex complexNumber(0.5, -0.5);

			THEN("return argument")
			{
				CHECK(complexNumber.GetArgument() == Approx(-0.78539816).epsilon(0.0001));
			}
		}
	}
}

SCENARIO("opertors + and - of complex number")
{
	GIVEN("two complex number")
	{
		CComplex complexNumber1(0.5, 2.5);
		CComplex complexNumber2(0.5, -0.5);

		WHEN("operator +")
		{
			CComplex sum(1, 2);

			THEN("return sum of complex numbers")
			{
				CHECK(sum.Re() == (complexNumber1 + complexNumber2).Re());
				CHECK(sum.Im() == (complexNumber1 + complexNumber2).Im());
			}
		}
		AND_WHEN("operator -")
		{
			CComplex diff(0, 3);

			THEN("return diff of complex numbers")
			{
				CHECK(diff.Re() == (complexNumber1 - complexNumber2).Re());
				CHECK(diff.Im() == (complexNumber1 - complexNumber2).Im());
			}
		}
		AND_WHEN("unary -")
		{
			CComplex opposite(-0.5, 0.5);

			THEN("return opposite complex number")
			{
				CComplex complNegative = -complexNumber2;
				CHECK(complNegative.Im() == opposite.Im());
				CHECK(complNegative.Re() == opposite.Re());
			}
		}
		AND_WHEN("unary +")
		{
			CComplex copy(0.5, 2.5);

			THEN("return copy complex number")
			{
				CComplex copyComplex = +complexNumber1;
				CHECK(copyComplex.Im() == copy.Im());
				CHECK(copyComplex.Re() == copy.Re());
			}
		}
	}

	GIVEN("complex and real")
	{
		WHEN("operator +")
		{
			THEN("return sum of complex and real numbers")
			{
				CComplex sum = CComplex(0.5, 2.5) + 1.25;
				CHECK(sum.Re() == 1.75);
				CHECK(sum.Im() == 2.5);
			}
			AND_THEN("return sum of real and complex numbers")
			{
				CComplex sum = 1.25 + CComplex(0.5, 2.5);
				CHECK(sum.Re() == 1.75);
				CHECK(sum.Im() == 2.5);
			}
		}
		AND_WHEN("operator -")
		{
			THEN("return diff of complex and real numbers")
			{
				CComplex diff = CComplex(0.5, 2.5) - 1.25;
				CHECK(diff.Re() == -0.75);
				CHECK(diff.Im() == 2.5);
			}
			AND_THEN("return diff of real and complex numbers")
			{
				CComplex diff = 1.25 - CComplex(0.5, 2.5);
				CHECK(diff.Re() == 0.75);
				CHECK(diff.Im() == -2.5);
			}
		}
	}
}

SCENARIO("operators * and / of complex numbers")
{
	GIVEN("complex numbers")
	{
		WHEN("operator *")
		{
			THEN("return composition of complex numbers")
			{
				CComplex composition = CComplex(-1, 0.5) * CComplex(2, -1);
				CHECK(composition.Re() == -1.5);
				CHECK(composition.Im() == 2);
			}
		}
		AND_WHEN("operator /")
		{
			THEN("return quotient of complex numbers")
			{
				CComplex quotient = CComplex(-2, 1) / CComplex(1, -1);
				CHECK(quotient.Re() == -1.5);
				CHECK(quotient.Im() == -0.5);
			}
			AND_THEN("return error div on zero")
			{
				CHECK_THROWS_WITH(CComplex(1, -1) / CComplex(0, 0), "Error: division by zero!\n");
			}
		}
	}
	GIVEN("complex and real numbers")
	{
		WHEN("operator *")
		{
			THEN("return composition of complex and real numbers")
			{
				CComplex composition = CComplex(-1, 0.5) * 2.5;
				CHECK(composition.Re() == -2.5);
				CHECK(composition.Im() == 1.25);
			}
			AND_THEN("return composition of real and complex numbers")
			{
				CComplex composition = 2.5 * CComplex(-1, 0.5);
				CHECK(composition.Re() == -2.5);
				CHECK(composition.Im() == 1.25);
			}
		}
		AND_WHEN("operator /")
		{
			THEN("return quotient of complex and real numbers")
			{
				CComplex quotient = CComplex(-1.5, 0.5) / 0.5;
				CHECK(quotient.Re() == -3);
				CHECK(quotient.Im() == 1);
			}
			AND_THEN("return quotient of real and complex numbers")
			{
				CComplex quotient = 2.5 / CComplex(1, -1);
				CHECK(quotient.Re() == 1.25);
				CHECK(quotient.Im() == 1.25);
			}
			AND_THEN("return error div on zero")
			{
				CHECK_THROWS_WITH(CComplex(1, -1) / 0, "Error: division by zero!\n");
			}
		}
	}
}

SCENARIO("operators +=, -=, *=, /= of complex numbers")
{
	GIVEN("complex numbers")
	{
		WHEN("operator +=")
		{
			THEN("return addition of complex number")
			{
				CComplex num(0.5, -1.5);
				num += CComplex(1.5, 2);
				CHECK(num.Re() == 2);
				CHECK(num.Im() == 0.5);
			}
		}
		AND_WHEN("operator -=")
		{
			THEN("return division of complex number")
			{
				CComplex num(0.5, -1.5);
				num -= CComplex(1.5, 2);
				CHECK(num.Re() == -1);
				CHECK(num.Im() == -3.5);
			}
		}
		AND_WHEN("operator *=")
		{
			THEN("return composition of complex number")
			{
				CComplex num(-1, 0.5);
				num *= CComplex(2, -1);
				CHECK(num.Re() == -1.5);
				CHECK(num.Im() == 2);
			}
		}
		AND_WHEN("operator /=")
		{
			THEN("return division of complex number")
			{
				CComplex num(-2, 1);
				num /= CComplex(1, -1);
				CHECK(num.Re() == -1.5);
				CHECK(num.Im() == -0.5);
			}
			AND_THEN("return error div on zero")
			{
				CHECK_THROWS_WITH(CComplex(1, -1) /= CComplex(0, 0), "Error: division by zero!\n");
			}
		}
	}
	GIVEN("complex and real numbers")
	{
		WHEN("operator +=")
		{
			THEN("return addition of complex and real number")
			{
				CComplex num(0.5, -1.5);
				num += 1.5;
				CHECK(num.Re() == 2);
				CHECK(num.Im() == -1.5);
			}
		}
		AND_WHEN("operator -=")
		{
			THEN("return division of complex and real number")
			{
				CComplex num(0.5, -1.5);
				num -= 1.5;
				CHECK(num.Re() == -1);
				CHECK(num.Im() == -1.5);
			}
		}
		AND_WHEN("operator *=")
		{
			THEN("return composition of complex and real number")
			{
				CComplex num(-1, 0.5);
				num *= 2;
				CHECK(num.Re() == -2);
				CHECK(num.Im() == 1);
			}
		}
		AND_WHEN("operator /=")
		{
			THEN("return division of complex and real number")
			{
				CComplex num(-2, 1);
				num /= -0.5;
				CHECK(num.Re() == 4);
				CHECK(num.Im() == -2);
			}
			AND_THEN("return error div on zero")
			{
				CHECK_THROWS_WITH(CComplex(1, -1) /= 0, "Error: division by zero!\n");
			}
		}
	}
}

SCENARIO("operators ==, != of complex numbers")
{
	GIVEN("complex numbers")
	{
		WHEN("operator ==")
		{
			THEN("return false, complex number not ==")
			{
				CComplex num1(-2.256, 1.369);
				CComplex num2(-2.257, 1.369);
				CHECK_FALSE(num1 == num2);
			}
			AND_THEN("true, complex number ==")
			{
				CComplex num1(-2.256789, 1.369);
				CComplex num2(-2.256789, 1.369);
				CHECK(num1 == num2);
			}
		}
		AND_WHEN("operator !=")
		{
			THEN("return false, complex number ==")
			{
				CComplex num1(-2.256789, 1.369);
				CComplex num2(-2.256789, 1.369);
				CHECK_FALSE(num1 != num2);
			}
			AND_THEN("true, complex number !=")
			{
				CComplex num1(-2.2567891, 1.369);
				CComplex num2(-2.256789, 1.369);
				CHECK(num1 != num2);
			}
		}
	}
	GIVEN("complex and real numbers")
	{
		WHEN("operator ==")
		{
			THEN("return false, complex number not == real")
			{
				CHECK_FALSE(CComplex(-2.256789, 1.369) == -2.256789);
				CHECK_FALSE(-2.256789 == CComplex(-2.256789, 1.369));
			}
		}
		AND_WHEN("operator !=")
		{
			THEN("return true, complex number != real")
			{
				CHECK(CComplex(-2.256789, 1.369) != -2.256789);
				CHECK(-2.256789 != CComplex(-2.256789, 1.369));
			}
		}
	}
}

SCENARIO("operators << and >>")
{
	std::stringstream input;
	std::ostringstream output;

	GIVEN("complex numbers")
	{
		WHEN("operator <<")
		{
			output << CComplex(-1.24, -2.5) << std::endl;
			output << CComplex(1.24, 2.5) << std::endl;
			output << CComplex(-3, 2.5) << std::endl;
			output << CComplex(3, -2.5) << std::endl;
			output << CComplex(3, 0) << std::endl;
			output << CComplex(0, 6.2) << std::endl;
			output << CComplex(0, 0) << std::endl;
			output << "Complex number: " << CComplex(1.25, -2.5) << " with negative Image.";

			CHECK(output.str() == "-1.24-2.5i\n"
								  "1.24+2.5i\n"
								  "-3+2.5i\n"
								  "3-2.5i\n"
								  "3\n"
								  "6.2i\n"
								  "0\n"
								  "Complex number: 1.25-2.5i with negative Image.");
		}
		AND_WHEN("operator >>")
		{
			THEN("Re > 0, Im < 0")
			{
				CComplex complexNumber;
				input << "1.2-2.3i";
				input >> complexNumber;
				CHECK(complexNumber.Re() == 1.2);
				CHECK(complexNumber.Im() == -2.3);
			}
			AND_THEN("Re < 0, Im > 0")
			{
				CComplex complexNumber;
				input << "-1.2+2.3i";
				input >> complexNumber;
				CHECK(complexNumber.Re() == -1.2);
				CHECK(complexNumber.Im() == 2.3);
			}
			AND_THEN("no complex number")
			{
				CComplex complexNumber;
				input << "-1.2";
				input >> complexNumber;
				CHECK(complexNumber.Re() == 0);
				CHECK(complexNumber.Im() == 0);
			}
			AND_THEN("Im = 0, Re !=0")
			{
				CComplex complexNumber;
				input << "-1.2+0i";
				input >> complexNumber;
				CHECK(complexNumber.Re() == -1.2);
				CHECK(complexNumber.Im() == 0);
			}
			AND_THEN("Im != 0, Re =0")
			{
				CComplex complexNumber;
				input << "0+2.5i";
				input >> complexNumber;
				CHECK(complexNumber.Re() == 0);
				CHECK(complexNumber.Im() == 2.5);
			}
		}
	}
}
