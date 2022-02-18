#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::FixedUpdate()
{
	for (std::shared_ptr<Component> comp : m_Components)
	{
		comp->FixedUpdate();
	}
}

void dae::GameObject::Update()
{
	for (std::shared_ptr<Component> comp : m_Components)
	{
		comp->Update();
	}
}

void dae::GameObject::LateUpdate()
{
	for (std::shared_ptr<Component> comp : m_Components)
	{
		comp->LateUpdate();
	}
}

void dae::GameObject::Render() const
{
	for (std::shared_ptr<Component> comp : m_Components)
	{
		comp->Render();
	}
}

void dae::GameObject::MarkForDestroy()
{
	m_MarkedDestroy = true;
}

bool dae::GameObject::MarkedFordestroy() const
{
	return m_MarkedDestroy;
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 1.f);
}

const dae::Transform& dae::GameObject::GetTransform() const
{
	// TODO: insert return statement here
	return m_Transform;
}


