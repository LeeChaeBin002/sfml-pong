#pragma once
#include "Scene.h"
#include "UI.h"
class SceneTitle :
    public Scene
{
protected:
    UI* startText = nullptr;
    UI* titleText;
   
public:
    SceneTitle();
    ~SceneTitle()override;

    void Init()override;
    void Draw(sf::RenderWindow& window)override;
    void Update(float dt)override;

};

