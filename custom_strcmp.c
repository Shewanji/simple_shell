#include "shell.h"

/**
 * _strcmp - Compare two strings character by character
 * @str1: Pointer to the first string to be compared
 * @str2: Pointer to the second string to be compared
 *
 * Return: An integer value indicating the relationship between the strings:
 *         - Negative value if str1 is less than str2
 *         - Zero if str1 and str2 are equal
 *         - Positive value if str1 is greater than str2
 */

int _strcmp(const char *str1, const char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (str1[i] - str2[i]);
        }
        i++;
    }

    return (str1[i] - str2[i]);
}
