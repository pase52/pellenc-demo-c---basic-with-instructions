#include "weight.h"
#include <gtest/gtest.h>

TEST(WeightConverterTest, KilogramToPound)
{
	double result = WeightConversion::convertWeight(1.0, WeightUnit::kilogram, WeightUnit::pound);
	ASSERT_NEAR(result, 2.20462, 0.00001);
}

TEST(WeightConverterTest, PoundToKilogram)
{
	double result = WeightConversion::convertWeight(2.20462, WeightUnit::pound, WeightUnit::kilogram);
	ASSERT_NEAR(result, 1.0, 0.00001);
}

TEST(WeightConverterTest, KilogramToOunce)
{
	double result = WeightConversion::convertWeight(1.0, WeightUnit::kilogram, WeightUnit::ounce);
	ASSERT_NEAR(result, 35.27392, 0.00001);
}

TEST(WeightConverterTest, OunceToKilogram)
{
	double result = WeightConversion::convertWeight(35.27392, WeightUnit::ounce, WeightUnit::kilogram);
	ASSERT_NEAR(result, 1.0, 0.00001);
}

TEST(WeightConverterTest, PoundToOunce)
{
	double result = WeightConversion::convertWeight(1.0, WeightUnit::pound, WeightUnit::ounce);
	ASSERT_NEAR(result, 16.0, 0.00001);
}

TEST(WeightConverterTest, OunceToPound)
{
	double result = WeightConversion::convertWeight(16.0, WeightUnit::ounce, WeightUnit::pound);
	ASSERT_NEAR(result, 1.0, 0.00001);
}

TEST(WeightConverterTest, SameUnitConversion)
{
	double result = WeightConversion::convertWeight(5.0, WeightUnit::kilogram, WeightUnit::kilogram);
	ASSERT_DOUBLE_EQ(result, 5.0);
}
