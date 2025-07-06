#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"
#include "UI.h"


//UI* titleUl;
//UI* scoreUI;

SceneDev1::SceneDev1()
	: Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{/*
	fontIds.push_back("fonts/DS-DIGIT.TTF");
	titleUl = new UI("fonts/DS-DIGIT.TTF", "Ping");
	titleUl->SetPosition({ 450.f, 360.f });*/



	//TextGo* go = new TextGo("fonts/DS-DIGIT.TTF");
	//go->SetString("Dev 1");
	//go->SetCharacterSize(30);
	//go->SetFillColor(sf::Color::White);
	//AddGameObject(go);

	testGo = new TextGo("fonts/DS-DIGIT.TTF");
	testGo->SetString("Dev 1");
	testGo->SetCharacterSize(30);
	testGo->SetFillColor(sf::Color::White);
	AddGameObject(testGo);

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
		testGo->sortingOrder = -1;
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	{
		testGo->sortingOrder = 1;
	}

	sf::Vector2f dir;
	dir.x = InputMgr::GetAxis(Axis::Horizontal);
	sf::Vector2f pos = testGo->GetPosition();
	pos += dir * 100.f * dt;
	testGo->SetPosition(pos);
}
