#ifndef WEIGHT_H_
#define WEIGHT_H_

#include <string>

enum class WeightUnit
{
	Kilogram,
	Pound,
	Ounce
};

namespace WeightConversion
{
	void startFlow();
	double getSourceValue();
	WeightUnit getWeightUnit(const std::string_view& sourceOrTarget);
	double convertWeight(double value, WeightUnit from, WeightUnit to);
}

#endif
