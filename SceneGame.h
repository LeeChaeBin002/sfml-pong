#pragma once
#include "Scene.h"

class Bat;
class Ball;
class UI;

class SceneGame : public Scene
{
protected:
	Bat* bat = nullptr;
	Ball* ball = nullptr;
	std::vector<UI*> uiElements;
	bool ballActive = false;

	UI* startButton;

public:
	SceneGame();
	~SceneGame() override = default;

	void Init() override;
	void Enter() override;

	void Update(float dt) override;
	
	void Draw(sf::RenderWindow& window) override;
	void SetGameOver();

};

