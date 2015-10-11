#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
const double eps = 1e-9;

inline int diff(double lhs, double rhs) {
	if (lhs - eps < rhs && rhs < lhs + eps) return 0;
	return (lhs < rhs) ? -1 : 1;
}

struct Point {
	double x, y;
	Point() {}
	Point(double x_, double y_): x(x_), y(y_) {}

};

inline int ccw(const Point& a, const Point& b, const Point& c) {
	return diff(a.x * b.y + b.x * c.y + c.x * a.y
	            - a.y * b.x - b.y * c.x - c.y * a.x, 0);
}

inline double dist2(const Point &a, const Point &b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return dx * dx + dy * dy;
}

struct PointSorter {
	Point origin;
	PointSorter(const vector<Point>& points) {
		origin = points[0];
		for (int i = 1 ; i < points.size() ; i++) {
			int det = diff(origin.x, points[i].x);
			if (det > 0)
				origin = points[i];
			else if (det == 0 && diff(origin.y, points[i].y) > 0)
				origin = points[i];
		}
	}
	bool operator()(const Point &a, const Point &b) {
		if (diff(b.x, origin.x) == 0 && diff(b.y, origin.y) == 0) return false;
		if (diff(a.x, origin.x) == 0 && diff(a.y, origin.y) == 0) return true;
		int det = ccw(origin, a, b);
		if (det == 0) return dist2(a, origin) < dist2(b, origin);
		return det < 0;
	}
};

vector<Point> convex_hull(vector<Point> points) {
	if (points.size() <= 3)
		return points;
	PointSorter cmp(points);
	sort(points.begin(), points.end(), cmp);
	vector<Point> ans;
	ans.push_back(points[0]);
	ans.push_back(points[1]);
	for (int i = 2 ; i < points.size() ; i++) {
		while (ans.size() > 1 &&
		        ccw(ans[ans.size() - 2], ans[ans.size() - 1], points[i]) >= 0)
			ans.pop_back();
		ans.push_back(points[i]);
	}
	return ans;
}
