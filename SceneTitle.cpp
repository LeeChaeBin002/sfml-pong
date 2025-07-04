#include "stdafx.h"
#include "SceneTitle.h"

SceneTitle::SceneTitle()
	:Scene(SceneIds::Title)
{
	startText = nullptr;
}

SceneTitle::~SceneTitle()
{
	delete startText;
}
void SceneTitle::Init()
{
	startText = new UI("fonts/DS-DiGIT.TTF", "Start");
	startText->SetPosition({ 640.f,360.f });
}
void SceneTitle::Draw(sf::RenderWindow& window)
{
	if (startText)
		startText->Draw(window);


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

