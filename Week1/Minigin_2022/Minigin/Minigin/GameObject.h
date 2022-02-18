#pragma once
#include "Transform.h"
#include "Component.h"

namespace dae
{
	class GameObject final 
	{
	public:
		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void FixedUpdate();
		void Update();
		void LateUpdate();

		void Render()const;

		void MarkForDestroy();
		bool MarkedFordestroy() const;

		void SetPosition(float x, float y);
		// TODO make ovrloaded SetPosition with a Vector2 struct

		const Transform& GetTransform() const;

		template<typename T>
		typename std::enable_if<std::is_base_of<Component, T>::value, bool>::type
			AddComponent(std::weak_ptr<T> component)
		{
			if (component.expired()
				|| component.use_count() != 1
				|| !GetComponent<T>().expired())
				return false;

			m_Components.push_back(component.lock());
			std::static_pointer_cast<Component>(component.lock())->OnAddedToObject();
			return true;
		}
		template<typename T>
		typename std::enable_if<std::is_base_of<Component, T>::value, bool>::type
			RemoveComponent()
		{
			std::weak_ptr<T> search = GetComponent<T>();
			if (search.expired())
				return false;

			m_Components.erase(std::remove_if(m_Components.begin(), m_Components.end(), [search](shared_ptr<Component> rhs)
				{
					return search.lock() == rhs;
				}), m_Components.end());
			return true;
		}
		template<typename T>
		std::weak_ptr<T> GetComponent() const {
			std::weak_ptr<T> weak;
			for (shared_ptr<Component> comp : m_Components) {

				weak = std::dynamic_pointer_cast<T>(comp);
				if (weak.lock() != nullptr) {
					return weak;
				}
			}

			return weak;
		}

	private:
		bool m_MarkedDestroy;
		Transform m_Transform;
		// TODO Make vector of components 
		std::vector<shared_ptr<Component>> m_Components{};

	};
}
