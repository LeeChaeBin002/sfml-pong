#include "stdafx.h"
#include "UI.h"

UI::UI(const std::string& fontPath, const std::string& str)
{
	if (!font.loadFromFile(fontPath))
	{
		std::cout << "폰트 로딩 실패: " << fontPath << std::endl;
	}
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(50);              // 글자 크게
	text.setFillColor(sf::Color::Red);      // 배경 대비 확실히
	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
	text.setPosition(640.f, 360.f);         // 화면 중앙

}

void UI::SetText(const std::string& str)
{
	text.setString(str);
}

void UI::SetTexture(const std::string& textureId)
{
	sprite.setTexture(TEXTURE_MGR.Get(textureId));
}
void UI::SetPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}
void UI::Update(float dt)
{

}
void UI::Draw(sf::RenderWindow& window)
{
	//std::cout << "UI Draw Called" << std::endl;
	if (sprite.getTexture())
	{
	window.draw(sprite);
	}
	window.draw(text);

}
void UI::HandleInput(const sf::Vector2f& mousePos, bool isClicked)
{

}

void UI::Init()
{
}

void UI::Release()
{
}

void UI::Reset()
{
}
