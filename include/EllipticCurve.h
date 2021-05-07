#ifndef ELLIPTICCURVE_IRREDUCIBLEPOLYNOMIAL_H
#define ELLIPTICCURVE_IRREDUCIBLEPOLYNOMIAL_H

#include <vector>
#include <utility>
#include "Polynomial.h"

struct PolynomialComp {
  bool operator() (const std::pair<Polynomial, Polynomial>& lhs, const std::pair<Polynomial, Polynomial>& rhs) const{
      if(lhs.first.value() != rhs.first.value()){
          return lhs.first.value() < rhs.first.value();
      }
     return lhs.second.value() < rhs.second.value();
  }
};

void getECPointSet();

void getAllECPoints(long long);
#endif