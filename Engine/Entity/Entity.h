
#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include "../Vendor/enTT/entt.hpp"
#include "Game/Game.h"

namespace Engine
{
	class Entity
	{
	public:
		Entity() 
			: m_reg(), m_handle()
		{
			//m_handle = Game::RegisterEntity();
		};
		Entity(entt::registry& _reg)
			:m_reg(&_reg), m_handle()
		{
			m_handle = m_reg->create();
		};

		~Entity()
		{
			//m_reg->destroy(m_handle);
			m_reg = nullptr;
		};


		template<typename T, typename... Args>
		T* AddComponent( Args&&... args)
		{
			return &m_reg->emplace<T>(m_handle, std::forward<Args>(args)...);
		}
		
		entt::entity GetHandle() const { return m_handle; }

	private:
		entt::registry* m_reg;
		entt::entity m_handle;

	};
}

#endif // !ENGINE_ENTITY_H



