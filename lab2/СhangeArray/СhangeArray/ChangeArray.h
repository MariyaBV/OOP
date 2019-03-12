#pragma once

#include <iostream>
#include <vector>

void ReadVectorFromStream(std::istream& input, std::vector<double>& vector);
double FindMinElement(const std::vector<double>& vector);
void ProcessVector(std::vector<double>& vector);
void PrintVector(const std::vector<double> vector);
