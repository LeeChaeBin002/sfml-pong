#include "stdafx.h"
#include "UI.h"
#include <filesystem>

UI::UI(const std::string& fontPath, const std::string& str)
{
	if (!font.loadFromFile(fontPath))
	{
		std::cout << "폰트 로딩 실패: " << fontPath << std::endl;
		std::cout << "현재 작업 디렉터리: " << std::filesystem::current_path() << std::endl;
	}
	text.setFont(font);
	text.setString(str); 
	          
	text.setFillColor(sf::Color::White);

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
	text.setPosition(pos);
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

void UI::SetCharSize(int size)
{
	text.setCharacterSize(size);
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

