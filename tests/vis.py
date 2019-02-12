from os import path
import json
from shapely.geometry import Polygon, Point
from polylabelfast import polylabelfast
from helpers import load_fixture

def tuple_to_list(tuplelist):
    return [list(row) for row in tuplelist]


data = load_fixture("water1.json")
point, dist = polylabelfast(data)

print(point, dist)
