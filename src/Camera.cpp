#include "../include/Camera.h"
#include <iostream>

Camera::Camera (const int x, const int y, const int speedX, const int speedY) {
	setSpeed (speedX, speedY);
	setPosition (x, y);
	std::cout << "New camera added" << std::endl;
}

Camera::~Camera () {
	std::cout << "Camera deleted" << std::endl;
}

void Camera::setSpeed (const int speedX, const int speedY) {
	this->speedX = speedX;
	this->speedY = speedY;
}

void Camera::setPosition (const int x, const int y) {
	this->x = x;
	this->y = y;
	this->targetX = x;
	this->targetY = y;
}

void Camera::setTarget (const int x, const int y) {
	this->targetX = x;
	this->targetY = y;
}

void Camera::moveToTarget () {
	for (int i = 0; i < speedX; i++) {
		if (x < targetX) {
			x++;
		} else if (x > targetX) {
			x--;
		}
	}

	for (int i = 0; i < speedY; i++) {
		if (y < targetY) {
			y++;
		} else if (y > targetY) {
			y--;
		}
	}
}

void Camera::shiftH (const int offset) {
	x = x + offset;
}

void Camera::shiftV (const int offset) {
	y = y + offset;
}

int Camera::getOffsetX () {
	return -x;
}

int Camera::getOffsetY () {
	return -y;
}
