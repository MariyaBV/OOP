#include "pch.h"
#include "../ComplexNumber/CComplex.h"

//void VerifyComplexNumber(const CComplex & compl, double expectedReal, double expectedImage)
//{
//	CHECK(compl.Re() == expectedReal);
//	CHECK(compl.Im() == expectedImage);
//}

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
				CHECK(complexNumber.GetArgument() == Approx(3.92699).epsilon(0.0001));
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
				CHECK(complexNumber.GetArgument() == Approx(5.497787).epsilon(0.0001));
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
				CHECK(-complexNumber2.Im() == opposite.Im());
				CHECK(-complexNumber2.Re() == opposite.Re());
			}
		}
		AND_WHEN("unary +")
		{
			CComplex copy(0.5, 2.5);

			THEN("return copy complex number")
			{
				CHECK(+complexNumber1.Im() == copy.Im());
				CHECK(+complexNumber1.Re() == copy.Re());
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
				CHECK_THROWS_WITH(CComplex(1, -1) / CComplex(0,0), "Error: division by zero!\n");
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
			THEN("return division of complex number")
			{
				CComplex num(0.5, -1.5);
				num -= 1.5;
				CHECK(num.Re() == -1);
				CHECK(num.Im() == -1.5);
			}
		}
		AND_WHEN("operator *=")
		{
			THEN("return composition of complex number")
			{
				CComplex num(-1, 0.5);
				num *= 2;
				CHECK(num.Re() == -2);
				CHECK(num.Im() == 1);
			}
		}
		AND_WHEN("operator /=")
		{
			THEN("return division of complex number")
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
