/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:51:08 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/09/09 18:05:39 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sound.hpp"

Sound::Sound(void)
{
	if (result = FMOD::System_Create(&system))
		throw(std::runtime_error("FMOD Error " + std::to_string(result)));
	if (result = system->init(2, FMOD_INIT_NORMAL, 0))
		throw(std::runtime_error("FMOD Error " + std::to_string(result)));
	if (result = system->createChannelGroup("MUSIC", &channelGroup))
		throw(std::runtime_error("FMOD Error " + std::to_string(result)));
}

Sound::~Sound(void)
{
	system->release();
	sound->release();
	channelGroup->release();
}

void		Sound::loadSound(const char *filename)
{
	if (result = sound->release())
		throw(std::runtime_error("FMOD Error " + std::to_string(result)));
	if (result = system->createStream(currentSound.c_str(), FMOD_DEFAULT, 0, &sound))
		throw(std::runtime_error("FMOD Error " + std::to_string(result)));
}

void		Sound::playSound(void)
{
	paused = !paused;
	if(result = system->playSound(sound, channelGroup, paused, &channel))
		throw(std::runtime_error("FMOD Error " + std::to_string(result)));
	if (result = channel->setVolume(1.0f))
		throw(std::runtime_error("FMOD Error " + std::to_string(result)));
	if(result = channel->setMode(FMOD_LOOP_NORMAL))
		throw(std::runtime_error("FMOD Error " + std::to_string(result)));
}
