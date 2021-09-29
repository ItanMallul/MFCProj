#include "pch.h"
#include "Rectangle.h"

void MyRectangle::draw(CDC* dc) {
	dc->BeginPath();
	POINT lp[] = { (CPoint)CD2DPointF(+radius * cos(rotation) - semiRadius() * sin(rotation), +radius * sin(rotation) + semiRadius() * cos(rotation)) + origin,
				   (CPoint)CD2DPointF(+radius * cos(rotation) + semiRadius() * sin(rotation), +radius * sin(rotation) - semiRadius() * cos(rotation)) + origin,
				   (CPoint)CD2DPointF(-radius * cos(rotation) + semiRadius() * sin(rotation), -radius * sin(rotation) - semiRadius() * cos(rotation)) + origin,
				   (CPoint)CD2DPointF(-radius * cos(rotation) - semiRadius() * sin(rotation), -radius * sin(rotation) + semiRadius() * cos(rotation)) + origin };
	dc->Polygon(lp, 4);
	Figure::draw(dc);
}

double MyRectangle::area() const {
	return 4 * radius * semiRadius();
}

bool MyRectangle::isInside(const CPoint& P) const {
	CD2DPointF localP = pointInLocalCoordinates(P);
	//	cout << '(' << localP.x << ',' << localP.y << ')';
	//	cout << radius << "   " << semiRadius();
	return -radius <= localP.x && localP.x <= radius && -semiRadius() <= localP.y && localP.y <= semiRadius();

}


