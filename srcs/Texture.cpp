#include "Texture.hpp"

Texture::~Texture(void)
{
	if (this->init)
	{
		SDL_DestroyTexture(texture);
	}
}

void	Texture::init(SDL_Renderer *renderer, SDL_Window *window, int w, int h)
{
	texture = SDL_CreateTexture()
}

void	Texture::lock(void)
{
	if (
}