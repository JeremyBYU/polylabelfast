# Polylabelfast
 
TODO 



This work is a port possible because of the amazing library called [polylabel](https://github.com/mapbox/polylabel).  It provides a very fast 2D delaunay triangulation that outputs a data structure that is perfectly suitable for this work. All the triangles are indexed by [half-edges](https://mapbox.github.io/delaunator/) allowing the quick extraction and polygon generation of any planar meshes.

## Installing

1. Install [conda](https://conda.io/projects/conda/en/latest/) - [Why?](https://medium.freecodecamp.org/why-you-need-python-environments-and-how-to-manage-them-with-conda-85f155f4353c)
2. `conda install -c conda-forge pybind11`
3. `conda install shapely` - Only needed for windows binary dependency
3. `python setup.py build install`

Please run the tests to ensure everything is working. Pytest should be installed as it is listed as a dependency.

1. Simply type `pytest` to run tests

## Demo



## API

`delaunay, planes, polygons = extractPlanesAndPolygons(point_cloud:ndarray`)

## Benchmark

| # Points | Time (ms) |
|----------|-----------|
| 10,000   | 5         |
|          |           |

## Issues

* If there are coincident points then it seems the delaunator cpp library gets stuck in an infinite loop. Add a very small amount of noise to the data to ensure this doesn't happen.



