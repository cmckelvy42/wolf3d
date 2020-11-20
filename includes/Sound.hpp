#ifndef SOUND_HPP
#define SOUND_HPP
#include "fmod.hpp"
#include <string>

class Sound
{
private:
	std::string			currentSound;
	FMOD_RESULT			result;
	FMOD::System		*system;
	FMOD::Sound			*sound;
	FMOD::Channel		*channel;
	FMOD::ChannelGroup	*channelGroup;
	bool				paused = true;

public:
	Sound(void);
	~Sound();

	void	loadSound(const char *filename);
	void	playSound(void);
};

#endif
