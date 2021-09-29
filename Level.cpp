#include "pch.h"
#include "Level.h"

void Level::addFigure(Figure& fig)
{
	
}

void Level::updateFigure(Figure& fig)
{
	fig.resizeRel(this->resizeFactor);
	fig.rotateRel(this->rotationSpeed);
}
