#pragma once
#include "pch.h"
//#include "polyFills/CPoint.h"
//#include "polyFills/CObject.h"
//#include "polyFills/CDC.h"
//#include "polyFills/COLORREF.h"
//#include "polyFills/CD2DPointF.h"
#include <cmath>
#ifndef __APPLE__
#include <corecrt_math_defines.h>
#include <cstdlib>
#endif

class Figure : public CObject {
protected:
	CPoint origin;
	double radius;
	double rotation;
	
public:
	COLORREF clr;
	Figure(CPoint origin = { 0,0 }, double radius = 0, COLORREF clr = RGB(0, 0, 0), double rotation = 0) :
		origin(origin), radius(radius), clr(clr), rotation(rotation) {}
	virtual void draw(CDC* dc) {
		COLORREF oldclr = dc->SetDCBrushColor(clr);
		dc->EndPath();
		dc->FillPath();
		dc->SetDCBrushColor(oldclr);
	};
	void moveAbs(CPoint newOrigin) { origin = newOrigin; }
	void resizeAbs(double newRadius) { radius = newRadius; }
	void rotateAbs(double newRotation) { rotation = std::fmod(newRotation, M_PI * 2); }

	void moveRel(CPoint delta) { origin += delta; }
	void resizeRel(double cooef) { radius *= cooef; }
	void rotateRel(double r) { rotation = std::fmod(rotation + r, M_PI * 2); }
	void updateFig(){
		this->resizeRel(1.5);
		this->rotateRel(1.2);
		CPoint p;
		if (this->isInside(GetCursorPos(&p))) {
			 
		}
	}

	virtual double area() const = 0;
	virtual bool isInside(const CPoint& P) const = 0;
	CD2DPointF pointInLocalCoordinates(const CPoint& P) const {
		CPoint vec = P - origin;
		return { static_cast<float>(cos(-rotation) * vec.x - sin(-rotation) * vec.y), static_cast<float>(sin(-rotation) * vec.x + cos(-rotation) * vec.y) };
	}
};

