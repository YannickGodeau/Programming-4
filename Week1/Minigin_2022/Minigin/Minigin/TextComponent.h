#pragma once
#include "Component.h"
#include "Font.h"
#include "SDL.h"
#include "GameObject.h"


class Texture2D;
class TextComponent : public Component
{
public:
	TextComponent(std::weak_ptr<dae::GameObject>& owner, std::string text, const std::shared_ptr<dae::Font> font, const SDL_Color color);
	
	virtual void FixedUpdate() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	void SetText(const std::string& text);
	virtual void SetTexture(const std::shared_ptr<Texture2D>& texture);

private:
	std::string m_Text;
	std::shared_ptr<dae::Font> m_Font;
	SDL_Color m_Color;
	std::shared_ptr<dae::Texture2D> m_TextTexture;


};

