#include "pch.h"
#include "MyEllipse.h"

void MyEllipse::draw(CDC* dc) {
	dc->BeginPath();

	// code adapted from https://stackoverflow.com/a/22035723
	// I probably *could* have figured this out on my own, but this is a course about cpp, not Bezier curves
	CD2DPointF topCenter, topRight, topLeft, bottomCenter, bottomRight, bottomLeft;
	{
		double width_two_thirds = radius * 4 / 3;

		double dx1 = sin(rotation) * semiRadius();
		double dy1 = cos(rotation) * semiRadius();
		double dx2 = cos(rotation) * width_two_thirds;
		double dy2 = sin(rotation) * width_two_thirds;

		double topCenterX = origin.x - dx1;
		double topCenterY = origin.y + dy1;
		double topRightX = topCenterX + dx2;
		double topRightY = topCenterY + dy2;
		double topLeftX = topCenterX - dx2;
		double topLeftY = topCenterY - dy2;

		double bottomCenterX = origin.x + dx1;
		double bottomCenterY = origin.y - dy1;
		double bottomRightX = bottomCenterX + dx2;
		double bottomRightY = bottomCenterY + dy2;
		double bottomLeftX = bottomCenterX - dx2;
		double bottomLeftY = bottomCenterY - dy2;

		topCenter = { static_cast<float>(topCenterX),    static_cast<float>(topCenterY) };
		topRight = { static_cast<float>(topRightX),     static_cast<float>(topRightY) };
		topLeft = { static_cast<float>(topLeftX),      static_cast<float>(topLeftY) };
		bottomCenter = { static_cast<float>(bottomCenterX), static_cast<float>(bottomCenterY) };
		bottomRight = { static_cast<float>(bottomRightX),  static_cast<float>(bottomRightY) };
		bottomLeft = { static_cast<float>(bottomLeftX),   static_cast<float>(bottomLeftY) };
	}
	POINT lp[] = { (CPoint)bottomCenter,
				   (CPoint)bottomRight,
				   (CPoint)topRight,
				   (CPoint)topCenter,
				   (CPoint)topLeft,
				   (CPoint)bottomLeft,
				   (CPoint)bottomCenter };
	dc->PolyBezier(lp, 7);
	Figure::draw(dc);
}

double MyEllipse::area() const {
	return M_PI * radius * semiRadius();
}

bool MyEllipse::isInside(const CPoint& P) const {
	CD2DPointF localP = pointInLocalCoordinates(P);
	return localP.x * localP.x / radius / radius + localP.y * localP.y / semiRadius() / semiRadius() < 1;
}
