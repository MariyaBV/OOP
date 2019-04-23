#include "pch.h"
#include "../ComplexNumber/CComplex.h"

//void VerifyComplexNumber(const CComplex & compl, double expectedReal, double expectedImage)
//{
//	CHECK(compl.Re() == expectedReal);
//	CHECK(compl.Im() == expectedImage);
//}

SCENARIO("complex number")
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
				CHECK_THROWS_WITH(complexNumber.GetArgument(), "Error. Argument zero is undefined.\n");
			}
		}
		AND_WHEN("real not 0, image = 0")
		{
			CComplex complexNumber(0, 12.3);

			THEN("return 0")
			{
				CHECK(complexNumber.GetArgument() == 0);
			}
		}
		AND_WHEN("real = 0, image not 0")
		{
			CComplex complexNumber(0, 12.3);

			THEN("return argument")
			{
				CHECK_THROWS_WITH(complexNumber.GetArgument(), "Error. Usage argumet (real != 0).\n");
			}
		}
		AND_WHEN("real and image not 0, all parameters > 0")
		{
			CComplex complexNumber(5.2, 12.3);

			THEN("return argument")
			{
				CHECK(complexNumber.GetArgument() == Approx(67.083).epsilon(0.0001));
			}
		}
		AND_WHEN("real and image not 0, all parameters < 0")
		{
			CComplex complexNumber(-5.2, -12.3);

			THEN("return argument")
			{
				CHECK(complexNumber.GetArgument() == Approx(63.941528).epsilon(0.0001));
			}
		}
		AND_WHEN("real < 0 and image > 0")
		{
			CComplex complexNumber(-5.2, 12.3);

			THEN("return argument")
			{
				CHECK(complexNumber.GetArgument() == Approx(-63.941528).epsilon(0.0001));
			}
		}
		AND_WHEN("real > 0 and image < 0")
		{
			CComplex complexNumber(5.2, -12.3);

			THEN("return argument")
			{
				CHECK(complexNumber.GetArgument() == Approx(-67.0831).epsilon(0.0001));
			}
		}
	}
}
