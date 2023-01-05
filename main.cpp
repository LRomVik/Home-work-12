#include<iostream>
#include <cstring>

bool isPrefix(const char* str, int len, int i, int k)
{
    if (i + k > len)
        return false;
    for (int j = 0; j < k; j++)
    {

        if (str[i] != str[j])
            return false;
        i++;
    }
    return true;
}

bool isKPeriodic(const char* str, int len, int k)
{
    for (int i = k; i < len; i += k)
        if (!isPrefix(str, len, i, k))
            return false;
    return true;
}

int main()
{
    const char *str = "abcdabcdabcdabcdabcd";
    int len = strlen(str);
    int k = 4;

    if (isKPeriodic(str, len, k))
        std::cout << "Multiple - " << k;
    else
        std::cout << "Non-multiple - " << k;
}