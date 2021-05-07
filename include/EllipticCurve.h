#ifndef ELLIPTICCURVE_IRREDUCIBLEPOLYNOMIAL_H
#define ELLIPTICCURVE_IRREDUCIBLEPOLYNOMIAL_H

#include <set>
#include "Polynomial.h"

struct PolynomialComp {
  bool operator() (const Polynomial& lhs, const Polynomial& rhs) const
  {return lhs.value() < rhs.value();}
};

std::set<Polynomial, PolynomialComp>& getECPointSet();

void getAllECPoints(long long);
#endif