from os import path
import json

from shapely.geometry import Polygon, Point

DIR_NAME =path.dirname(path.dirname(__file__))
FIXTURES_DIR = path.join(DIR_NAME, 'fixtures')


def load_fixture(file):
    fname = path.join(FIXTURES_DIR, file)
    with open(fname, 'r') as f:
        fixture = json.load(f)
    return fixture

def tuple_to_list(tuplelist):
    return [list(row) for row in list(tuplelist)]

def poly_to_rings(poly):
    ext_coord = tuple_to_list(list(poly.exterior.coords))
    holes = [tuple_to_list(ring.coords) for ring in poly.interiors]
    holes.insert(0, ext_coord)
    return holes

def create_circle(center, radius):
    poly = Point(*center).buffer(radius)
    return poly_to_rings(poly)