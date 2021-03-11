#ifndef _SLD_WIN_HPP
	# define _SLD_WIN_HPP

# include <SDL2/SDL.h>
# include <utility>
# include <memory>
# include <iostream>
# include <mutex>
# include "Obj.hpp"
#include <unistd.h>
#include "Camera.hpp"

class SDLWin {
public:
	SDLWin(const std::string &winName, const std::pair<int, int> &winSize);
	~SDLWin();
	void windowBlock(Camera &cam);
	SDL_Window *getSDLWin() const;
	void setBufferPixel(int pos, const Color &c);
	void updateWin();
	bool _update;
	bool _quitWin;
private:
	SDL_Event 				_event;
	SDL_Window 				*_window;
	SDL_Renderer 			*_renderer;
	std::pair<int, int> 	_winSize;
	std::mutex 				_mtx;
};

#endif /* _SDL_WIN_HPP */