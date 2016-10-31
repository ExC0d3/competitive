// left side of a->b
vector<Point> cut_polygon(const vector<Point>& polygon, Line line) {
	if (!polygon.size()) return polygon;
	typedef vector<Point>::const_iterator piter;
	piter la, lan, fi, fip, i, j;
	la = lan = fi = fip = polygon.end();
	i = polygon.end() - 1;
	bool lastin = diff(ccw_line(line, polygon[polygon.size() - 1]), 0) > 0;
	for (j = polygon.begin() ; j != polygon.end() ; j++) {
		bool thisin = diff(ccw_line(line, *j), 0) > 0;
		if (lastin && !thisin) {
			la = i;
			lan = j;
		}
		if (!lastin && thisin) {
			fi = j;
			fip = i;
		}
		i = j;
		lastin = thisin;
	}
	if (fi == polygon.end()) {
		if (!lastin) return vector<Point>();
		return polygon;
	}
	vector<Point> result;
	for (i = fi ; i != lan ; i++) {
		if (i == polygon.end()) {
			i = polygon.begin();
			if (i == lan) break;
		}
		result.push_back(*i);
		Seoul National University 21

	}
	Point lc, fc;
	get_cross(Line(*la, *lan
	               - *la), line, lc);
	get_cross(Line(*fip, *fi
	               - *fip), line, fc);
	result.push_back(lc);
	if (diff(dist2(lc, fc), 0) != 0) result.push_back(fc);
	return result;
}


