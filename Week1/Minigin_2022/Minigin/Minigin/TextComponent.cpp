#include "MiniginPCH.h"
#include "TextComponent.h"
#include <SDL_ttf.h>
#include "Renderer.h"

TextComponent::TextComponent(std::weak_ptr<dae::GameObject>& owner, std::string text, const std::shared_ptr<dae::Font> font, const SDL_Color color) :
	Component(owner),
	m_Text(text),
	m_Font(font),
	m_Color(color)
{

}

void TextComponent::FixedUpdate()
{
}

void TextComponent::Update()
{
	if (m_NeedsUpdate)
	{
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), m_Color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(dae::Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);

		m_NeedsUpdate = false;
	}
}

void TextComponent::LateUpdate()
{
}

void TextComponent::Render()
{
	if (m_TextTexture != nullptr)
	{
		glm::vec3 pos = m_Owner.lock()->GetTransform().GetPosition();
		dae::Renderer::GetInstance().RenderTexture(*m_TextTexture, pos.x, pos.y);
	}
}

void TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}

void TextComponent::SetTexture(const std::shared_ptr<Texture2D>& texture)
{
	m_TextTexture = texture;
}

