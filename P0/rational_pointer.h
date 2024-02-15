/*TITLE: PROGRAMMING II LABS                   SUBTITLE: P0

        AUTHOR 1: Ángela Fouz Suárez    LOGIN 1: angela.fouz

        AUTHOR 2: Nolan Duteil          LOGIN 2: nolan.duteil

GROUP: 3.1                                                          DATE: 01/02/2024
 */
#ifndef P0_RATIONAL_POINTER_H
#define P0_RATIONAL_POINTER_H
typedef struct Data* Rational;
struct Data {
    int num;
    int den;
};
Rational createRational(int n, int d);
int numerator(Rational r);
int denominator(Rational r);
Rational sum(Rational r1, Rational r2);
#endif //P0_RATIONAL_POINTER_H
