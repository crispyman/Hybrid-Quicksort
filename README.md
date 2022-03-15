# Hybrid-Quicksort
![build status](https://github.com/crispyman/Hybrid-Quicksort/actions/workflows/cmake.yml/badge.svg)

Source Paper for most algorithms
https://www.researchgate.net/publication/305229647_HYBRID_QUICKSORT_AN_EMPIRICAL_STUDY

Timsort can be found here
https://github.com/swenson/sort

To use uncomment compare size or compare unique and set the array size in that function to the dataset size you want to
test on.

Code was compiled to C++ 14 using GCC 9.3.0, flags used were `--Wl, --stack,116777216`
to increase memory available for stack.
