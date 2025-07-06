#include "stdafx.h"
#include "SceneTitle.h"

SceneTitle::SceneTitle()
	:Scene(SceneIds::Title)
{
	titleText = nullptr;
	startText = nullptr;
	
}

SceneTitle::~SceneTitle()
{
	delete startText;
}
void SceneTitle::Init()
{
	titleText = new UI("fonts/DS-DIGIT.TTF", "Ping!");
	titleText->SetPosition({ 480.f,260.f });
	titleText->SetCharSize(150);
	startText = new UI("fonts/DS-DIGIT.TTF", "Click to Start");
	startText->SetPosition({ 480.f,630.f });
	startText->SetCharSize(50);
	
}
void SceneTitle::Draw(sf::RenderWindow& window)
{
	if (startText)
		startText->Draw(window);

	if (titleText)
		titleText->Draw(window);

}
void SceneTitle::Update(float dt)
{
	// ���콺 ��ǥ ��������
	sf::Vector2i mousePos = sf::Mouse::getPosition();  // ������ ������ �� ����

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// ���콺 ��ġ�� startText ���� �ȿ� �ִ��� �˻��ϴ� ���� �߰� ����
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
}

