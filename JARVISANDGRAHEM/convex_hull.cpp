#include "convex_hull.h"

long long cross(vector2d a, vector2d b) {
    return a.x * b.y - b.x * a.y;
}

vector<point2d> graham_scan(vector<point2d> points) {
    /* F */
    for (int i = 1; i < points.size(); ++i) {
        if (points[i].x < points[0].x || (points[i].x == points[0].x && points[i].y < points[0].y)) {
            swap(points[0], points[i]);
        }
    }

    sort(
        points.begin() + 1,
        points.end(),
        [&points](point2d a, point2d b) {
            return cross(
                vector2d(points[0], a),
                vector2d(points[0], b)
            ) > 0;
        }
    );

    /* S */
    vector<point2d> ch = { points[0], points[1] };

    for (int i = 2; i < points.size(); ++i) {
        while (ch.size() >= 2 && cross(
            vector2d(ch[ch.size() - 2], ch[ch.size() - 1]),
            vector2d(ch[ch.size() - 1], points[i])
        ) < 0)
        {
            ch.pop_back();
        }
        ch.push_back(points[i]);
    }
    return ch;
}

vector<point2d> jarvis_march(vector<point2d> points) {
    for (int i = 1; i < points.size(); ++i) {
        if (points[i].x < points[0].x || (points[i].x == points[0].x && points[i].y < points[0].y)) {
            swap(points[0], points[i]);
        }
    }

    /* Jarvis Scan algorithm */
    vector<point2d> ch;
    int cur = 0;

    while (true) {
        ch.push_back(points[cur]);
        int id = -1;

        for (int i = 0; i < points.size(); ++i) {
            if (i != cur && (id == -1 || cross(
                vector2d(points[cur], points[i]),
                vector2d(points[cur], points[id])
            ) > 0))
            {
                id = i;
            }
        }

        if (id == 0) {
            break;
        }

        cur = id;
    }
    return ch;
}

bool is_int(const string& s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        return false;

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}
