#ifndef MFCPROJECTSHAPES_TRIANGLE_H
#define MFCPROJECTSHAPES_TRIANGLE_H


#include "Figure.h"

class Triangle : public Figure {
public:
	Triangle(CPoint origin = { 0,0 }, double radius = 0, COLORREF clr = RGB(0, 0, 0), double rotation = 0) :
		Figure(origin, radius, clr, rotation) {}
	virtual void draw(CDC* dc);
	virtual double area() const;
	virtual bool isInside(const CPoint& P) const;
};


#endif //MFCPROJECTSHAPES_TRIANGLE_H
