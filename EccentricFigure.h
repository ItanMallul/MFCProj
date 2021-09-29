
#ifndef MFCPROJECTSHAPES_ECCENTRICFIGURE_H
#define MFCPROJECTSHAPES_ECCENTRICFIGURE_H
#include "Figure.h"


class EccentricFigure : public Figure {
protected:
	double eccentricity;
	double semiRadius() const {
		return radius * (1 - eccentricity);
	}
public:
	EccentricFigure(CPoint origin = { 0,0 }, double radius = 0, COLORREF clr = RGB(0, 0, 0), double rotation = 0, double eccentricity = 0) :
		eccentricity(eccentricity), Figure(origin, radius, clr, rotation) {}
};


#endif //MFCPROJECTSHAPES_ECCENTRICFIGURE_H
