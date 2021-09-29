#ifndef MFCPROJECTSHAPES_MAGENDAVID_H
#define MFCPROJECTSHAPES_MAGENDAVID_H


#include "Triangle.h"

class MagenDavid : public Triangle {
public:
	MagenDavid(CPoint origin = { 0,0 }, double radius = 0, COLORREF clr = RGB(0, 0, 0), double rotation = 0) :
		Triangle(origin, radius, clr, rotation) {}
	virtual void draw(CDC* dc);
	virtual double area() const;
	virtual bool isInside(const CPoint& P);
};


#endif //MFCPROJECTSHAPES_MAGENDAVID_H

