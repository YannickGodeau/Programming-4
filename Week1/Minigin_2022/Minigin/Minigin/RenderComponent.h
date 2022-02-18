#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Texture2D.h"


class RenderComponent : public Component
{
public:
	RenderComponent(std::weak_ptr<dae::GameObject>& owner);

	virtual void FixedUpdate() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	virtual void SetTexture(const std::shared_ptr<dae::Texture2D>& texture);
	//IVector2 GetTextureDimensions() const;

private:

	std::shared_ptr<dae::Texture2D> m_Texture;
};

