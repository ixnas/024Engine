#ifndef CAMERA_H
#define CAMERA_H

class Camera {
	private:
		int x, y, targetx, targety, speedx, speedy;
	public:
		Camera (const int x, const int y, const int speedX, const int speedY);
		~Camera ();
		void setSpeed (const int speedX, const int speedY);
		void setPosition (const int x, const int y);
		void setTarget (const int x, const int y);
		void moveToTarget ();
		void shiftH (const int offset);
		void shiftV (const int offset);
		int getOffsetX ();
		int getOffsetY ();
};

#endif
