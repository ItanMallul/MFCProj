#include "pch.h"
#include "MagenDavid.h"

void MagenDavid::draw(CDC* dc) {
	Triangle::draw(dc);
	Figure::rotateRel(M_PI);
	Triangle::draw(dc);
}

double MagenDavid::area() const {
	return Triangle::area() + Triangle(origin, radius / 4).area();
}

bool MagenDavid::isInside(const CPoint& P) {
	if (Triangle::isInside(P))
		return true;
	Figure::rotateRel(M_PI);
	return Triangle::isInside(P);
}
