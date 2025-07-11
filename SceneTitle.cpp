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
	// 마우스 좌표 가져오기
	sf::Vector2i mousePos = sf::Mouse::getPosition();  // 윈도우 기준일 수 있음

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// 마우스 위치가 startText 영역 안에 있는지 검사하는 로직 추가 가능
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
}

