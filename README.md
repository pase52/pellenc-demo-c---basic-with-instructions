# C++ Demo

These exercises demonstrate usage of GitHub Copilot for C++. The app is a simple CLI Tool that allows users to convert in between different units.

## Features

OctoConverter supports the following conversion types:

- **Temperature**: Convert between Celsius, Fahrenheit, and Kelvin
- **Distance**: Convert between Meters, Feet, and Yards
- **Weight**: Convert between Kilograms, Pounds, and Ounces

## Getting Started

### Build

`cd` to the `exercisefiles/c++` directory. Run the following two commands to prepare the make file and then build the project:

```bash
cmake -S . -B build
cmake --build build
```

### Run & Test

- To run the main program:

    ```bash
      ./build/main
    ```

- To execute the tests:

    ```bash
      ./build/run-tests
    ```

## Exercises

Use GitHub Copilot to assist with the following tasks:

- [x] Finish the `Distance` Conversion Class and include it in the `main.cpp` (optionally, first implement tests and do a TDD approach)
- [x] Add some Tests for the `Distance::convertDistance`
- [ ] Refactor all `printf` and `scanf` and use `std::cout` and `std::cin` instead
- [x] Add a new Conversion Class for `Weight` to convert in between Kilograms, Pounds, and Ounces