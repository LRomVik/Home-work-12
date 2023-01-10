#include "multiply.h"

void computeLPS(std::string pat, int* lps) {

    int j = 0;
    lps[0] = 0;

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
size_t KMPSearch(const std::string& pat, const std::string& txt, size_t k) {

    int* lps = new int[pat.size()];

    computeLPS(pat, lps);

    int count = 0; // для подсчета длины подстроки
    int i = 0;
    int j = 0;
    while (i < txt.size()) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == pat.size()) {
            if ((i - j) % k == 0) {
                ++count;
            }
            j = lps[j - 1];
        }
        else if (i < txt.size() && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i = i + 1;
            }
        }
    }
    delete[] lps;
    return count;
}

bool IsKPeriodic(const std::string& txt, size_t k) {
    if (k > (txt.size() / 2) && k <= 0) {
        return false;
    }
    std::string s = txt.substr(0, k);
    size_t count = KMPSearch(s, txt, k);

    if (count * k == txt.size()) {
        return true;
    }
    return false;
}