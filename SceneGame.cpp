#include "stdafx.h"
#include "SceneGame.h"
#include "Bat.h"
#include "Ball.h"
#include "UI.h"

SceneGame::SceneGame() : Scene(SceneIds::Game)
{
	startButton = nullptr;
	
}


void SceneGame::Init()
{
	bat = (Bat*)AddGameObject(new Bat("Bat"));
	ball = (Ball*)AddGameObject(new Ball("Ball"));
	ball->SetBat(bat);
	startButton = new UI("fonts/DS-DIGIT.TTF", "SCORE: ");
	startButton->SetPosition({ 50,50 });
	startButton->SetCharSize(50);
	
	uiElements.push_back(startButton);
	Scene::Init();
}
void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);

	if (startButton)
	{
		startButton->Draw(window);

	}
	
}
void SceneGame::Enter()
{
	ballActive = false;

	Scene::Enter();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);
	if (!ballActive)
	{
		ball->SetPosition(bat->GetPosition());

		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			ballActive = true;

			sf::Vector2f dir(1.f, -1.f);
			Utils::Nomalize(dir);
			ball->Fire(dir, 500.f);
		}
	}
}

void SceneGame::SetGameOver()
{
	SCENE_MGR.ChangeScene(SceneIds::Game);
}
