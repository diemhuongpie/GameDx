/*********************************************/
/* CREATE BY MICHAEL LE AND SHIN XINH NHAT THE GIOI*/
/* 13/07/2015*/
/********************************************/

/*********************************************/
/* WARING : TOO MANY GET/SET FUNCTION. FIX BOX2D*/
/*********************************************/

#ifndef __SWEPTAABB_H__
#define __SWEPTAABB_H__

#include "Box2D.h"


bool AABBCheck(CBox2D box1, CBox2D box2)
{
	return !(	box1.getX() + box1.getWidth() < box2.getX()	
			||	box1.getX() > box2.getX() + box2.getWidth() 
			||	box1.getY() + box1.getHeight() < box2.getY() 
			||	box1.getY() > box2.getY() + box2.getHeight());

}


CBox2D GetSweptBroadPhaseBox(CBox2D box)
{
	CBox2D boundingBox(0, 0, 0, 0);

	box.getVelocityX() > 0 ? boundingBox.setX(box.getX())									: boundingBox.setX(box.getX()			+ box.getVelocityX());
	box.getVelocityY() > 0 ? boundingBox.setY(box.getY())									: boundingBox.setY(box.getY()			+ box.getVelocityY());
	box.getVelocityX() > 0 ? boundingBox.setWidth(box.getWidth()	+ box.getVelocityX())	: boundingBox.setWidth(box.getWidth()	- box.getVelocityX());
	box.getVelocityY() > 0 ? boundingBox.setHeight(box.getHeight()	+ box.getVelocityY())	: boundingBox.setWidth(box.getHeight()	- box.getVelocityY());

	return boundingBox;
}


bool AABB(CBox2D box1, CBox2D box2, float& moveX, float& moveY)
{
	moveX	=	moveY	=	0.0f;

	float left		= box2.getX() - (box1.getX()	 + box1.getWidth());
	float right		= box2.getX() + box2.getWidth()  - box1.getX();
	float bottom	= box2.getY() - box2.getHeight() - box1.getY();
	float top		= box2.getY() - box1.getY()		 + box1.getHeight();

	// check that there was a collision
	if (left > 0 || right < 0 || bottom > 0 || top < 0)
		return false;

	// find the offset of both sides
	moveX = abs(left)	< right ?	left	: right;
	moveY = abs(bottom)	< top	?	bottom	: top;

	// only use whichever offset is the smallest
	if (abs(moveX) < abs(moveY))
		moveY = 0.0f;
	else
		moveX = 0.0f;

	return true;

}





#endif