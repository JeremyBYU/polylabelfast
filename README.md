# Polylabelfast
 
This is a python module that provides bindings to the C++ [polylabel](https://github.com/mapbox/polylabel) algorithm. Binding is done through pybind11. 
A small modification of polylabel was performed: a tuple is returned that includes the the point **and** distance to the edge of the polygon. This code works with holes inside the polygon.

Note the shapely polylabel algorithm does not work with holes and is ~30X slower.

This work is possible because of the amazing library called [polylabel](https://github.com/mapbox/polylabel).  
## Installing

1. Install [conda](https://conda.io/projects/conda/en/latest/) - [Why?](https://medium.freecodecamp.org/why-you-need-python-environments-and-how-to-manage-them-with-conda-85f155f4353c)
2. `conda install -c conda-forge pybind11`
3. `conda install shapely` - Only needed for testing
3. `python setup.py build install`

Please run the tests to ensure everything is working. Pytest should be installed as it is listed as a dependency.

1. Simply type `pytest` to run tests

## API

`point, dist = polylabelfast(rings)`)

## Benchmark

```
------------------------------------------------------------------------------------------------------- benchmark: 5 tests -------------------------------------------------------------------------------------------------------
Name (time in us)                                Min                    Max                   Mean              StdDev                 Median                   IQR            Outliers          OPS            Rounds  Iterations
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
test_verify_large_circle                     59.2592 (1.0)         676.3449 (1.0)          73.1986 (1.0)       29.0197 (1.0)          62.0246 (1.0)          3.1605 (1.0)      722;1325  13,661.4711 (1.0)        6266           1
test_verify_simple_circle_with_holes        185.6788 (3.13)      1,063.1099 (1.57)        241.7050 (3.30)      87.3711 (3.01)        195.1603 (3.15)        74.7653 (23.66)     751;430   4,137.2754 (0.30)       4521           1
test_shapely_algorithm_large_circle       1,706.6646 (28.80)     4,202.6617 (6.21)      2,115.3367 (28.90)    419.4543 (14.45)     1,921.5780 (30.98)      534.9129 (169.25)      82;13     472.7380 (0.03)        473           1
test_verify_water2                        4,641.1797 (78.32)     7,415.6949 (10.96)     5,487.0484 (74.96)    606.5855 (20.90)     5,413.1294 (87.27)      883.7520 (279.62)       54;2     182.2473 (0.01)        167           1
test_verify_water1                       11,403.0482 (192.43)   14,787.9331 (21.86)    12,676.9948 (173.19)   836.2340 (28.82)    12,634.0591 (203.69)   1,278.2207 (404.44)       25;0      78.8830 (0.01)         69           1
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

```

## Issues





