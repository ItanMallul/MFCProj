#include "pch.h"
#include "Triangle.h"

void Triangle::draw(CDC* dc) {
	dc->BeginPath();
	POINT lp[] = { (CPoint)CD2DPointF(radius * cos(rotation + 3 * M_PI / 6.0), radius * sin(rotation + 3 * M_PI / 6.0)) + origin,
				   (CPoint)CD2DPointF(radius * cos(rotation + 7 * M_PI / 6.0), radius * sin(rotation + 7 * M_PI / 6.0)) + origin,
				   (CPoint)CD2DPointF(radius * cos(rotation + 11 * M_PI / 6.0), radius * sin(rotation + 11 * M_PI / 6.0)) + origin };
	dc->Polygon(lp, 3);
	Figure::draw(dc);
}

double Triangle::area() const {
	return 3 * sqrt(3) * radius * radius / 4;
}

bool Triangle::isInside(const CPoint& P) const {
	CD2DPointF localP = pointInLocalCoordinates(P);
	return 2 * localP.y >= -radius
		&& sqrt(3) * localP.x + localP.y <= radius
		&& -sqrt(3) * localP.x + localP.y <= radius;
}
