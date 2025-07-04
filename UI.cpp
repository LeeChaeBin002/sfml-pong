#include "stdafx.h"
#include "UI.h"

UI::UI(const std::string& fontPath, const std::string& str)
{
	if (!font.loadFromFile(fontPath))
	{
		std::cout << "��Ʈ �ε� ����: " << fontPath << std::endl;
	}
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(50);              // ���� ũ��
	text.setFillColor(sf::Color::Red);      // ��� ��� Ȯ����
	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
	text.setPosition(640.f, 360.f);         // ȭ�� �߾�

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
