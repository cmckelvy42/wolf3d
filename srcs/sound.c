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

#include "wolf.h"

t_sound		*initsound(void)
{
	t_sound	*sound;

	sound = ft_memalloc(sizeof(t_sound));
	sound->on = 1;
	sound->possible = 1;
	sound->result = FMOD_System_Create(&sound->fmodsystem);
	if (sound->result != FMOD_OK)
		sound->possible = 0;
	else
		sound->result = FMOD_System_Init(sound->fmodsystem, 2,
			FMOD_INIT_NORMAL, 0);
	if (sound->result != FMOD_OK)
		sound->possible = 0;
	else
	{
		FMOD_Channel_SetVolume(sound->channel, 1.0f);
		sound->result = FMOD_System_CreateChannelGroup(sound->fmodsystem,
			"MUSIC", &sound->music);
	}
	return (sound);
}

void		loadsound(t_sound *sound, const char *filename)
{
	sound->currentsound = (char*)filename;
	sound->result = FMOD_Sound_Release(sound->sound);
	sound->result = FMOD_System_CreateStream(sound->fmodsystem,
		sound->currentsound, FMOD_DEFAULT, 0, &sound->sound);
}

void		playsound(t_sound *sound, int pause)
{
	sound->result = FMOD_System_PlaySound(sound->fmodsystem,
		sound->sound, sound->music, pause, &sound->channel);
	FMOD_Channel_SetMode(sound->channel, FMOD_LOOP_NORMAL);
}
