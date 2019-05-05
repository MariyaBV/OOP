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

SCENARIO("opertors of complex number")
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
}
