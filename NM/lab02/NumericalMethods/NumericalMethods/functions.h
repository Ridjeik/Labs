#ifndef FUNCTIONS_H
#define FUNCTIONS_H

double f(double x);
double df(double x);
double d2f(double x);
double phi(double x);

double findDyhotomea(double start, double end, double precision, int& iterations);
double findHordes(double start, double end, double precision, int& iterations);
double findSimpleIteration(double x0, double precision, int& iterations);
double findTangents(double start, double end, double precision, int& iterations);

#endif // FUNCTIONS_H
