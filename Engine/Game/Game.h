
#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include "Vendor/enTT/entt.hpp"
#include "Vendor/glm/glm.hpp"
#include "Vendor/SDL2/SDL.h"

namespace Engine
{
	class Game
	{
	public:
		Game();
		Game(const Game&) = delete;
		Game(const Game&&) = delete;
		virtual ~Game();

		void Run();

		entt::registry& GetRegistry() { return m_Register; }

	public:
		glm::vec4 m_ClearColor;
		SDL_DisplayMode m_DisplayMode;
		SDL_Window* pWindow;
		entt::registry m_Register;
		
		
	};

}

#endif // !ENGINE_GAME_H



