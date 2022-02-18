#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "Renderer.h"

RenderComponent::RenderComponent(std::weak_ptr<dae::GameObject>& owner):
	Component(owner)
{
}

void RenderComponent::FixedUpdate()
{
}

void RenderComponent::Update()
{
}

void RenderComponent::LateUpdate()
{
}

void RenderComponent::Render()
{
	if (m_Texture != nullptr)
	{
		glm::vec3 pos = m_Owner.lock()->GetTransform().GetPosition();
		
		dae::Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
	}
}

void RenderComponent::SetTexture(const std::shared_ptr<dae::Texture2D>& texture)
{
	m_Texture = texture;
}
