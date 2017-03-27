#include <stdio.h>

char* reverseString(char* s)
{
    int i = 0, n = strlen(s) - 1;
    while (i < n)
    {
        char temp = s[i];
        s[i++] = s[n];
        s[n--] = temp;
    }
    
    return s;
}
