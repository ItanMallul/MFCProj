#pragma once
#ifndef LEVEL_H

#include "Figure.h"

class Level{
private:
	
	float resizeFactor = 1.5;
	float rotationSpeed = 1.2;

public:
	void addFigure(Figure& fig);
	void updateFigure(Figure &);
};

#endif // !LEVEL_H
