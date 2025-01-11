/**
 * Input Validation Header
 * Contains utility functions for validating user input
 */

#ifndef VALIDATION_H
#define VALIDATION_H

#include <cctype>
#include <cstring>

/**
 * Validates if string contains only letters and spaces
 * @param str String to validate
 * @return true if string contains only letters and spaces
 */
inline bool isAlphaSpace(const char* str) {
    while (*str) {
        if (!isalpha(*str) && *str != ' ')
            return false;
        str++;
    }
    return true;
}

/**
 * Validates string length is within specified range
 * @param str String to check
 * @param minLen Minimum acceptable length
 * @param maxLen Maximum acceptable length
 * @return true if length is within range
 */
inline bool isValidLength(const char* str, int minLen, int maxLen) {
    int len = strlen(str);
    return (len >= minLen && len <= maxLen);
}

/**
 * Checks if number is positive
 * @param num Number to check
 * @return true if number is greater than zero
 */
inline bool isPositiveNumber(float num) {
    return num > 0;
}

/**
 * Validates price is within acceptable range
 * @param price Price to validate
 * @return true if price is between 0.01 and 9999.99
 */
inline bool isValidPrice(float price) {
    return price > 0 && price <= 9999.99;
}

/**
 * Validates quantity is within acceptable range
 * @param qty Quantity to validate
 * @return true if quantity is between 0 and 999
 */
inline bool isValidQuantity(int qty) {
    return qty >= 0 && qty <= 999;
}

#endif