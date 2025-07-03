#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"


SceneDev1::SceneDev1()
	: Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	fontIds.push_back("fonts/DS-DIGIT.ttf");

	TextGo* go = new TextGo("fonts/DS-DIGIT.ttf");
	go->SetString("Dev 1");
	go->SetCharacterSize(30);
	go->SetFillColor(sf::Color::White);
	AddGameObject(go);

	testgo = new TextGo("fonts/DS-DIGIT.ttf");
	testgo->SetString("Dev 1");
	testgo->SetCharacterSize(30);
	testgo->SetFillColor(sf::Color::Red);
	AddGameObject(testgo);
	
	Scene::Init();
}

void SceneDev1::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		testgo->sortingOrder = -1;

	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	{
		testgo->sortingOrder = 1;
	}

	sf::Vector2f dir;
	dir.x = InputMgr::GetAxisRaw(Axis::Horizontal);
	dir.y = InputMgr::GetAxisRaw(Axis::vertical);

	sf::Vector2f pos = testgo->GetPosition();
	pos += dir * 100.f * dt;
	testgo->SetPosition(pos);


	


}
