#ifndef INPUT_HPP
#define INPUT_HPP
#include <utility>

class Input
{
private:
	//use pairs of bools, one for if the input is happening, and one to "lock" the variable so it only gets set on initial keypress or on keyrelease
	bool forward = false;
	bool backward = false;
	bool turnLeft = false;
	bool turnRight = false;
	bool strafeLeft = false;
	bool strafeRight = false;
	bool sprint = false;
	bool interact = false;
public:
	Input(void) = default;
	~Input(void) = default;
	bool isForward(void);
	bool isBackward(void);
	bool isTurnLeft(void);
	bool isTurnRight(void);
	bool isStrafeLeft(void);
	bool isStrafeRight(void);
	bool isSprint(void);
	bool isInteract(void);
	void setForward(bool b);
	void setBackward(bool b);
	void setTurnLeft(bool b);
	void setTurnRight(bool b);
	void setStrafeLeft(bool b);
	void setStrafeRight(bool b);
	void setSprint(bool b);
	void setInteract(bool b);
	
};

#endif
