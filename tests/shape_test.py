from os import path
import warnings
import pytest

from shapely.geometry import Polygon, Point, box
from shapely.algorithms.polylabel import polylabel

from tests.helpers import load_fixture, poly_to_rings, create_circle
from polylabelfast import polylabelfast


@pytest.fixture
def water1():
    return load_fixture('water1.json')

@pytest.fixture
def water2():
    return load_fixture("water2.json")


def test_verify_water1(benchmark, water1):
    point, dist = benchmark(polylabelfast, water1)
    # point, dist = polylabelfast(water1)
    assert point == [3865.85009765625, 2124.87841796875]

def test_verify_water2(benchmark, water2):
    point, dist = benchmark(polylabelfast, water2)
    assert point == [3263.5, 3263.5]

def test_verify_simple_circle():
    circle = create_circle([0,0], 10)
    point, dist = polylabelfast(circle)
    assert point == [0.0, 0.0]

def test_shapely_algorithm_large_circle(benchmark):
    circle = Point(0,0).buffer(1000, resolution=256)

    point = benchmark(polylabel, circle)

    assert [point.x, point.y] == [0.0, 0.0]

def test_verify_large_circle(benchmark):
    circle = Point(0,0).buffer(1000, resolution=256)
    poly = poly_to_rings(circle)

    point, dist = benchmark(polylabelfast, poly)
    assert point == [0.0, 0.0]

def test_verify_simple_circle_with_holes(benchmark):
    outer_circle = Point(0,0).buffer(100)
    small_circle = Point(10,10).buffer(10)
    hole_circle = outer_circle.difference(small_circle)
    poly = poly_to_rings(hole_circle)

    point, dist = benchmark(polylabelfast, poly)
    assert point == [-29.296875, -37.890625]






