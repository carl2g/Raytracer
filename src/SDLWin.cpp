/*
* @Author: carl de gentile
* @Date:   2018-06-01 20:30:53
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-06-03 16:18:18
*/

#include "SDLWin.hpp"

SDLWin::SDLWin(const std::string &winName, const std::pair<int, int> &winSize)
	: _event({0}), _quitWin(false), _update(true), _winSize(winSize)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Quit();
		throw "Quiting screen";
	}
	 _window = SDL_CreateWindow(
	 	winName.c_str(),
	 	SDL_WINDOWPOS_CENTERED,
	 	SDL_WINDOWPOS_CENTERED,
	 	winSize.first, winSize.second,
	 	SDL_WINDOW_SHOWN
	 );
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Window *SDLWin::getSDLWin() const
{
	return (_window);
}

void SDLWin::setBufferPixel(int pos, const Color &c)
{
	_mtx.lock();
	SDL_SetRenderDrawColor(_renderer, c.getR(),  c.getG(), c.getB(),  c.getA());
	SDL_RenderDrawPoint(_renderer, pos % _winSize.first , pos / _winSize.first);
	_mtx.unlock();
}

void SDLWin::updateWin()
{
	_mtx.lock();
	SDL_RenderPresent(_renderer);
	_mtx.unlock();
}


void SDLWin::windowBlock(Camera &cam)
{
	SDL_PollEvent(&_event);

	if (_event.type == SDL_KEYDOWN) { 
		switch (_event.key.keysym.sym) {
			case SDLK_UP:
				cam.rotate_vertical(0.01);
				break;
			case SDLK_DOWN:
				cam.rotate_vertical(-0.01);
				break;
			case SDLK_LEFT:
				cam.rotate_horizontal(0.01);
				break;
			case SDLK_RIGHT:
				cam.rotate_horizontal(-0.01);
				break;
		}
		this->_update = true;
	}
	if(_event.window.event == SDL_WINDOWEVENT_CLOSE)
		_quitWin = true;
}

SDLWin::~SDLWin()
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}