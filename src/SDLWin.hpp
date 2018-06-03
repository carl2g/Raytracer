#ifndef _SLD_WIN_HPP
	# define _SLD_WIN_HPP

# include <SDL2/SDL.h>
# include <utility>
# include <memory>
# include <iostream>
# include <mutex>
# include "Obj.hpp"

class SDLWin {
public:
	SDLWin(const std::string &winName, const std::pair<int, int> &winSize);
	~SDLWin();
	void launchWin();
	SDL_Window *getSDLWin() const;
	void setBufferPixel(int pos, const Color &c);
	void updateWin();
private:
	SDL_Event 		_event;
	SDL_Window 		*_window;
	bool 			_quitWin;
	SDL_Renderer 		*_renderer;
	std::pair<int, int> 	_winSize;
	std::mutex 		_mtx;
};

#endif /* _SDL_WIN_HPP */