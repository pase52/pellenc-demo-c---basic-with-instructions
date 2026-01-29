#include "converters/types.h"
#include "converters/temperature.h"
#include "converters/distance.h"
#include <iostream>
#include <array>
#include <cstdlib>

void clearScreen()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void displayHeader()
{
  printf("========================================\n");
  printf("       OCTO CONVERTER v1.0.0           \n");
  printf("   Unit Conversion Tool by Pellenc     \n");
  printf("========================================\n\n");
}

ConversionType getConversionType()
{
  int choice;
  std::array<ConversionType, 2> conversionTypes = {
      ConversionType::Temperature,
      ConversionType::Distance};

  while (true)
  {
    clearScreen();
    displayHeader();
    printf("Select type of conversion:\n\n");
    printf("  [1] Temperature Conversion\n");
    printf("  [2] Distance Conversion\n");
    printf("  [0] Exit\n\n");
    printf("Enter your choice: ");
    
    if (scanf("%d", &choice) != 1)
    {
      while (getchar() != '\n');
      printf("\nInvalid input. Please enter a number.\n");
      printf("Press Enter to continue...");
      getchar();
      continue;
    }

    if (choice == 0)
    {
      clearScreen();
      printf("\nThank you for using OctoConverter!\n\n");
      exit(0);
    }

    if (choice > 0 && choice <= conversionTypes.size())
    {
      return conversionTypes[choice - 1];
    }

    printf("\nInvalid choice. Please try again.\n");
    printf("Press Enter to continue...");
    while (getchar() != '\n');
    getchar();
  }
}

int main()
{
  while (true)
  {
    ConversionType type = getConversionType();
    clearScreen();
    displayHeader();
    
    switch (type)
    {
    case ConversionType::Temperature:
      {
        TemperatureConversion::startFlow();
        break;
      }
    case ConversionType::Distance:
      {
        DistanceConversion::startFlow();
        break;
      }
    }
    
    printf("\n\nPress Enter to return to main menu...");
    while (getchar() != '\n');
    getchar();
  }
  
  return 0;
}
