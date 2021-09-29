#ifndef MFCPROJECTSHAPES_RECTANGLE_H
#define MFCPROJECTSHAPES_RECTANGLE_H
#include "EccentricFigure.h"

class MyRectangle : public EccentricFigure {
public:
	MyRectangle(CPoint origin = { 0,0 }, double radius = 0, COLORREF clr = RGB(0, 0, 0), double rotation = 0, double eccentricity = 0) :
		EccentricFigure(origin, radius, clr, rotation, eccentricity) {}
	virtual void draw(CDC* dc);
	virtual double area() const;
	virtual bool isInside(const CPoint& P) const;
};


#endif //MFCPROJECTSHAPES_RECTANGLE_H

