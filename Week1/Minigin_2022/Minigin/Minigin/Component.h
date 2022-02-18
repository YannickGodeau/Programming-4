#pragma once
#include <memory>
#include "GameObject.h"


class Component
{
public:
	Component(const std::weak_ptr<dae::GameObject>& owner):
		m_Owner {owner}
	{};
	virtual ~Component() = default;
	Component(const Component & other) = delete;
	Component(Component&& other) = delete;
	Component& operator=(const Component & other) = delete;
	Component& operator=(Component && other) = delete;

	virtual void FixedUpdate() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render() = 0;

protected:
	bool m_NeedsUpdate = false;
	std::weak_ptr<dae::GameObject> m_Owner;
};

