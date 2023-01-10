#pragma once
#include <string>

void computeLPS(std::string pat, int* lps);

size_t KMPSearch(const std::string& pat, const std::string& txt, size_t k);

bool IsKPeriodic(const std::string& txt, size_t k);