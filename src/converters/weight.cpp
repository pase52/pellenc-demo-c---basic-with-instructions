#include "weight.h"
#include <cstdio>
#include <unordered_map>

namespace /* private */
{
	static constexpr double KG_TO_LBS = 2.20462;
	static constexpr double LB_TO_OZ = 16.0;

	std::string getWeightUnitSign(WeightUnit unit)
	{
		std::unordered_map<WeightUnit, std::string> unitSigns = {
			{WeightUnit::kilogram, "kg"},
			{WeightUnit::pound, "lbs"},
			{WeightUnit::ounce, "oz"}
		};

		return unitSigns.at(unit);
	}
} // namespace private

namespace WeightConversion
{
	void startFlow()
	{
		double sourceValue = getSourceValue();
		WeightUnit from = getWeightUnit("source");
		WeightUnit to = getWeightUnit("target");

		double targetValue = convertWeight(sourceValue, from, to);

		printf("%.2f%s is %.2f%s\n", sourceValue, getWeightUnitSign(from).c_str(), targetValue, getWeightUnitSign(to).c_str());
	}

	double getSourceValue()
	{
		double value;
		printf("Enter the value to be converted: ");
		scanf("%lf", &value);
		return value;
	}

	WeightUnit getWeightUnit(const std::string_view& sourceOrTarget)
	{
		int choice;
		printf("Select %s weight unit:\n", std::string(sourceOrTarget).c_str());
		printf("[1] Kilogram\n");
		printf("[2] Pound\n");
		printf("[3] Ounce\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			return WeightUnit::kilogram;
		case 2:
			return WeightUnit::pound;
		case 3:
			return WeightUnit::ounce;
		default:
			return WeightUnit::kilogram;
		}
	}

	double convertWeight(double value, WeightUnit from, WeightUnit to)
	{
		if (from == to)
		{
			return value;
		}

		// Convert everything to Kilograms first
		if (from == WeightUnit::pound)
		{
			value = value / KG_TO_LBS;
		}
		else if (from == WeightUnit::ounce)
		{
			value = value / (KG_TO_LBS * LB_TO_OZ);
		}

		// Then convert to the target unit
		if (to == WeightUnit::pound)
		{
			value = value * KG_TO_LBS;
		}
		else if (to == WeightUnit::ounce)
		{
			value = value * KG_TO_LBS * LB_TO_OZ;
		}

		return value;
	}
}
