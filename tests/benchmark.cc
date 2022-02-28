#include <benchmark/benchmark.h>
#include "Polynomial.h"
#include "EllipticCurve.h"
#include <iostream>
#include <cmath>
#include <vector>

static void BM_PolynomialCreation(benchmark::State& state) {
  for (auto _ : state){
      Polynomial p1(0b10010101, 16);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_PolynomialCreation);

static void BM_inverses_2_16(benchmark::State& state){
  long f_size = std::pow(2, 16);
  //long f_size = 1024;
  for(auto _ : state){
    for(int i = 0; i < f_size; i++){
        Polynomial cur(i, f_size);
        Polynomial cur_inv = cur.inverse();
    }
  }
}

BENCHMARK(BM_inverses_2_16)->Unit(benchmark::kMillisecond);

static void BM_inverses_2_30(benchmark::State& state){
  long f_size = std::pow(2, 30);
  //long f_size = 1024;
  for(auto _ : state){
    for(long i = 0; i < f_size/2; i++){
        Polynomial cur(i, f_size);
        cur.inverse();
    }
  }
}

//BENCHMARK(BM_inverses_2_30)->Unit(benchmark::kMillisecond);

static void BM_pow_mod(benchmark::State& state){
  //long f_size = std::pow(2, 30);
  //long f_size = 1024;
  Polynomial p1(std::pow(2,30)-459, std::pow(2,30));
  for(auto _ : state){
    p1.pow(125467);
  }
}

BENCHMARK(BM_pow_mod);


static void BM_EllipticCurves(benchmark::State& state){
  long f_size = std::pow(2, 16);
 
  for(auto _ : state){
      getAllECPoints(f_size);
  }
}

BENCHMARK(BM_EllipticCurves)->Unit(benchmark::kMillisecond);

static void BM_AdditionTable(benchmark::State& state){
  int k = 8;
  long f_size = std::pow(2, k);
 
  for(auto _ : state){
      std::vector<Polynomial> all_elements;
      //generate all elements < 2^k
      for(int i = 0; i < f_size; ++i){
          Polynomial p(i,f_size);
          all_elements.push_back(p);
      }

      for(Polynomial& outer : all_elements){
        for(Polynomial& inner : all_elements){
            Polynomial pairwise = outer + inner;
        }
      }
  }
}

BENCHMARK(BM_AdditionTable)->Unit(benchmark::kMillisecond);


static void BM_MultiplicationTable(benchmark::State& state){
  int k = 4;
  long f_size = std::pow(2, k);
 
  for(auto _ : state){
      std::vector<Polynomial> all_elements;
      //generate all elements < 2^k
      for(int i = 0; i < f_size; ++i){
          Polynomial p(i,f_size);
          all_elements.push_back(p);
      }

      for(Polynomial& outer : all_elements){
        for(Polynomial& inner : all_elements){
            Polynomial pairwise = outer * inner;
        }
      }
  }
}

BENCHMARK(BM_MultiplicationTable)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();