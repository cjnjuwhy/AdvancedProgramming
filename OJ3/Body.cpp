#include "Body.h"



Body::Body()
{
	this->height = 0;
}

Body::Body(double height)
{
	this->height = height;
}


Body::~Body()
{
}

void Body::printHeight()
{
	printf("%.3f\n",height);
}

double Body::getHeight()
{
	return height;
}
