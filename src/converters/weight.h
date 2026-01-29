#ifndef CONVERTERS_WEIGHT_H_
#define CONVERTERS_WEIGHT_H_

#include <string>

enum class WeightUnit
{
	kilogram,
	pound,
	ounce
};

namespace WeightConversion
{
	void startFlow();
	double getSourceValue();
	WeightUnit getWeightUnit(const std::string_view& sourceOrTarget);
	double convertWeight(double value, WeightUnit from, WeightUnit to);
}

#endif
