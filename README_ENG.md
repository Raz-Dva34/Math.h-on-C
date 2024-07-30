# s21_math

Implementing a custom version of the math.h math library.

## Chapter I

## Introduction

This project develops a custom version of the math.h standard library in the C programming language. This library implements basic mathematical operations that are then used in various algorithms. This project is intended to introduce the basics of computational methods and reinforce the approaches of structured programming.

## Chapter II

## Information

The C math operations are a group of functions in the C standard library that implement basic mathematical functions. All functions use floating-point numbers in some way. Different C standards provide different, although backward-compatible, sets of functions. Any function that works with angles uses radians as the unit of measurement for an angle.

### Overview of some "math.h" functions

| No. | Function | Description |
| --- | -------- | ---------- |
| 1 | `int abs(int x)` | calculates the absolute value of an integer |
| 2 | `long double acos(double x)` | calculates the arc cosine |
| 3 | `long double asin(double x)` | calculates the arc sine |
| 4 | `long double atan(double x)` | calculates the arc tangent |
| 5 | `long double ceil(double x)` | returns the nearest integer not less than the given value |
| 6 | `long double cos(double x)` | calculates the cosine |
| 7 | `long double exp(double x)` | returns the value of e raised to the given power |
| 8 | `long double fabs(double x)` | calculates the absolute value of a floating-point number |
| 9 | `long double floor(double x)` | returns the nearest integer not greater than the given value |
| 10 | `long double fmod(double x, double y)` | remainder of a floating-point division operation |
| 11 | `long double log(double x)` | calculates the natural logarithm |
| 12 | `long double pow(double base, double exp)` | raises a number to a given power |
| 13 | `long double sin(double x)` | calculates the sine |
| 14 | `long double sqrt(double x)` | calculates the square root |
| 15 | `long double tan(double x)` | calculates the tangent |

## Chapter III

## Part 1. Implementation of math.h library functions

- The library is developed in the C11 standard using the gcc compiler;
- Full coverage of the library functions with unit tests using the Check library;
- Unit tests check the results of the implementation by comparing it with the implementation of the standard math.h library;
- The gcov_report target should generate a gcov report as an html page. For this, unit tests should be run with gcov flags;
- A Makefile is provided for building the library and tests (with the all, clean, test, s21_math.a, gcov_report targets);
- The overall accuracy to be checked is 16 significant digits;
- The accuracy to be checked of the fractional part is a maximum of 6 decimal places.
