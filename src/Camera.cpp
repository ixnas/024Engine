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
	this->speedx = speedX;
	this->speedy = speedY;
}

void Camera::setPosition (const int x, const int y) {
	this->x = x;
	this->y = y;
	this->targetx = x;
	this->targety = y;
}

void Camera::setTarget (const int x, const int y) {
	this->targetx = x;
	this->targety = y;
}

void Camera::moveToTarget () {
	for (int i = 0; i < speedx; i++) {
		if (x < targetx) {
			x++;
		} else if (x > targetx) {
			x--;
		}
	}

	for (int i = 0; i < speedy; i++) {
		if (y < targety) {
			y++;
		} else if (y > targety) {
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
