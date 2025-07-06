#pragma once
#include "GameObject.h"
class UI : public GameObject
{
protected:
	sf::Sprite sprite;
	sf::Font font;
	sf::Text text;

public:
	UI(const std::string& fontPath, const std::string& str); // ������ ����
	~UI()=default;
	
	
	void SetText(const std::string& str);
	void SetTexture(const std::string& textureId);
	void SetPosition(const sf::Vector2f& pos);
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	void HandleInput(const sf::Vector2f& mousePos, bool isClicked);//���콺 �Է� ó�� �Լ�
	void SetCharSize(int size);

	// GameObject��(��) ���� ��ӵ�
	void Init() override;

	void Release() override;

	void Reset() override;

};

