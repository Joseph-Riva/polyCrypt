#include <benchmark/benchmark.h>
#include "Polynomial.h"
#include <cmath>

static void BM_PolynomialCreation(benchmark::State& state) {
  for (auto _ : state){
      Polynomial p1(0b10010101, 16);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_PolynomialCreation);

static void BM_inverses(benchmark::State& state){
  //long f_size = std::pow(2, 50);
  long f_size = 1024;
  for(auto _ : state){
    for(int i = 0; i < f_size; i++){
        Polynomial cur(i, f_size);
        Polynomial cur_inv = cur.inverse();
    }
  }
}

BENCHMARK(BM_inverses);

BENCHMARK_MAIN();