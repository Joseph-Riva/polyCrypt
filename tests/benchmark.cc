#include <benchmark/benchmark.h>
#include "Polynomial.h"

static void BM_PolynomialCreation(benchmark::State& state) {
  for (auto _ : state){
      Polynomial p1(0b10010101, 16);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_PolynomialCreation);


BENCHMARK_MAIN();