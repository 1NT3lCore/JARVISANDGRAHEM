#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> 

using namespace std;

struct point2d {
    long long x, y;
};

struct vector2d {
    long long x, y;
    vector2d(point2d a, point2d b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

long long cross(vector2d a, vector2d b);

vector<point2d> graham_scan(vector<point2d> points);

vector<point2d> jarvis_march(vector<point2d> points);

bool is_int(const string& s);