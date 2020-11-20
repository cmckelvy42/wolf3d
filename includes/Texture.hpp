#ifndef W_TEXTURE_HPP
#define W_TEXTURE_HPP

#include "shared.hpp"
#include <SDL.h>

class Texture
{
private:
	SDL_Texture	*texture;
	void		*data;
	int			pitch;
	Uint32		*pixels;
	int			width;
	int			height;
	bool		init = false;
public:
	Texture(void) = default;
	~Texture(void);
	void	init(SDL_Renderer *renderer, SDL_Window *window, int w, int h);
	void	lock(void);
	void	unlock(void);
};

#endif
