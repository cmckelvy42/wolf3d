#include "Input.hpp"
bool Input::isForward(void) { return forward; }
bool Input::isBackward(void) { return backward; }
bool Input::isTurnLeft(void) { return turnLeft; }
bool Input::isTurnRight(void) { return turnRight; }
bool Input::isStrafeLeft(void) { return strafeLeft; }
bool Input::isStrafeRight(void) { return strafeRight; }
bool Input::isSprint(void) { return sprint; }
bool Input::isInteract(void) { return interact; }
void Input::setForward(bool b)
{ 
	if (forward != b)
		forward = b;
}
void Input::setBackward(bool b)
{
	if (backward != b)
		backward = b;
}
void Input::setTurnLeft(bool b)
{
	if (turnLeft != b)
		turnLeft = b;
}
void Input::setTurnRight(bool b)
{
	if (turnRight != b)
		turnRight = b;
}
void Input::setStrafeLeft(bool b)
{
	if (strafeLeft != b)
		strafeLeft = b;
}
void Input::setStrafeRight(bool b)
{
	if (strafeRight != b)
		strafeRight = b;
}
void Input::setSprint(bool b)
{
	if (sprint != b)
		sprint = b;
}
void Input::setInteract(bool b)
{
	if (interact != b)
		interact = b;
}
