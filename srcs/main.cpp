/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:25:32 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/09/10 15:39:28 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf.hpp"
#include "shared.hpp"
#include "SDL.h"
#include "SDL_Image.h"
#include "Input.hpp"
#undef main

void		SDLdie(const char *str)
{
std::cerr << str << SDL_GetError() << '\n';
std::exit(1);
}

void		keyPress(SDL_Keycode key, Wolf &wolf)
{
	Input &input = wolf.getInput();
	switch (key)
	{
		case SDLK_ESCAPE:
		{
			wolf.exit();
			break;
		}
		case SDLK_z:
		{
			input.setSprint(true);
			break;
		}
		case SDLK_LEFT:
		case SDLK_a:
		{
			input.setTurnLeft(true);
			break;
		}
		case SDLK_RIGHT:
		case SDLK_d:
		{
			//wolf.getPlayer().rotate(DEGTORAD(5.0f));
			input.setTurnRight(true);
			break;
		}
		case SDLK_w:
		case SDLK_UP:
		{
			//wolf.getPlayer().move(0.1f);
			input.setForward(true);
			break;
		}
		case SDLK_DOWN:
		case SDLK_s:
		{
			input.setBackward(true);
			break;
		}
		case SDLK_SPACE:
		{
			input.setInteract(true);
			break;
		}
		case SDLK_e:
		{
			input.setStrafeRight(true);
			break;
		}
		case SDLK_q:
		{
			input.setStrafeLeft(true);
			break;
		}
		default:
			break;
	}
}

void		keyRelease(SDL_Keycode key, Wolf &wolf)
{
	Input &input = wolf.getInput();
	switch (key)
	{
		case SDLK_z:
		{
			input.setSprint(false);
			break;
		}
		case SDLK_LEFT:
		case SDLK_a:
		{
			input.setTurnLeft(false);
			break;
		}
		case SDLK_RIGHT:
		case SDLK_d:
		{	
			input.setTurnRight(false);
			break;
		}
		case SDLK_w:
		case SDLK_UP:
		{
			input.setForward(false);
			break;
		}
		case SDLK_DOWN: 
		case SDLK_s:
		{
			input.setBackward(false);
			break;
		}
		case SDLK_SPACE:
		{
			input.setInteract(false);
			break;
		}
		case SDLK_e:
		{
			input.setStrafeRight(false);
			break;
		}
		case SDLK_q:
		{
			input.setStrafeLeft(false);
			break;
		}
		default:
			break;
	}
}

void		keyHook(Wolf &wolf)
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
			{
				wolf.exit();
				break;
			}
			case SDL_KEYDOWN:
			{
				keyPress(event.key.keysym.sym, wolf);
				break;
			}
			case SDL_KEYUP:
			{
				keyRelease(event.key.keysym.sym, wolf);
				break;
			}
			default:
				break;
		}
	}
}

/*
in a more complicated game, other game logic like AI/other object movements would be handled here,
but everything that happens is tied to player input so that's all that's here
*/


int			main(void)
{
	SDL_Event event;
	//unsigned int oldTicks = 0;
	//int newTicks = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		SDLdie("SDL Init failed: ");
	if (IMG_Init(IMG_INIT_PNG) < 0)
		SDLdie("SDL_IMG Init failed: ");
	Wolf		wolf;

	while (wolf.isRunning())
	{
		keyHook(wolf);
		wolf.renderClear();
		wolf.render();
		wolf.gameLoop();
	}
	SDL_Quit();
	IMG_Quit();
	return (0);
}


//NEED MAP.LOAD INSTEAD OF CONSTRUCTOR
//NEED WOLF.CHANGEMAP THAT CALLS MAP.LOAD WITH WOLF.MAPNUM AS PARAMETER
//NEED TO CHECK IF PLAYER IS ON ELEVATOR IN PLAYER.MOVE/STRAFE
//WHY DOES IT BREAK WHEN I ROTATE