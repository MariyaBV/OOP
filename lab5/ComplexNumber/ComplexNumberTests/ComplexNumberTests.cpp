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
}