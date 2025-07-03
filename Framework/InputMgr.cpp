#include "stdafx.h"
#include "InputMgr.h"

std::list<sf::Keyboard::Key> InputMgr::downKeys;
std::list<sf::Keyboard::Key> InputMgr::heldKeys;
std::list<sf::Keyboard::Key> InputMgr::upKeys;

std::unordered_map<Axis, AxisInfo> InputMgr::axisInfoMap;
sf::Vector2f InputMgr::getMousePoisition(sf::RenderWindow& window)

void InputMgr::Init()
{
	AxisInfo infoH;
	infoH.axis = Axis::Horizontal;
	infoH.positivies.push_back(sf::Keyboard::D);
	infoH.positivies.push_back(sf::Keyboard::Right);
	infoH.nagatives.push_back(sf::Keyboard::A);
	infoH.nagatives.push_back(sf::Keyboard::Left);
	axisInfoMap.insert({ Axis::Horizontal,infoH });

	AxisInfo infoV;
	infoV.axis = Axis::vertical;
	infoV.positivies.push_back(sf::Keyboard::S);
	infoV.positivies.push_back(sf::Keyboard::Down);
	infoV.nagatives.push_back(sf::Keyboard::W);
	infoV.nagatives.push_back(sf::Keyboard::Up);
	axisInfoMap.insert({ Axis::vertical,infoV });



}

void InputMgr::Clear() 
{
	downKeys.clear();
	upKeys.clear();
}

void InputMgr::UpdateEvent(const sf::Event& ev) 
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (!Contains(heldKeys, ev.key.code))
		{
			downKeys.push_back(ev.key.code);
			heldKeys.push_back(ev.key.code);
		}
		break;
	case sf::Event::KeyReleased:
		Remove(heldKeys, ev.key.code);
		upKeys.push_back(ev.key.code);
		break;
	case sf::Event::MouseMoved:
		std::cout << "Mouse moved to: " << ev.mouseMove.x << ", " << ev.mouseMove.y << std::endl;
		break;
	}
}

void InputMgr::Update(float dt) 
{

}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downKeys, key);
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(upKeys, key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return Contains(heldKeys, key);
}

bool InputMgr::Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	return std::find(list.begin(), list.end(), key) != list.end();
}

void InputMgr::Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}

float InputMgr::GetAxisRaw(Axis axis)
{
	auto findIt = axisInfoMap.find(axis);
	if (findIt == axisInfoMap.end())
		return 0.0f;

	const auto& axisInfo = findIt->second;
	auto it = heldKeys.rbegin();//역방향 리터레이터
	while (it!= heldKeys.rend())
	{
		sf::Keyboard::Key code = *it;
		if (Contains(axisInfo.positivies, code))
		{
			return 1.f;
		}
		if (Contains(axisInfo.nagatives, code))
		{
			return -1.f;
		}
		++it;

	}

	return 0.0f;
}

float InputMgr::GetAxis(Axis axis)
{
	return 0.0f;
}
static bool state[sf::Mouse::ButtonCount] = { false };

bool InputMgr::GetMouseButtonDown(sf::Mouse::Button key)
{
	return sf::Mouse::isButtonPressed(key) && !state[key];//true
}

bool InputMgr::GetMouseButtonUp(sf::Mouse::Button key)
{
	return !sf::Mouse::isButtonPressed(key) && state[key];
}

bool InputMgr::GetMouseButton(sf::Mouse::Button key)
{
	return sf::Mouse::isButtonPressed(key);
}

sf::Vector2i InputMgr::GetMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}

sf::Vector2f InputMgr::GetMousePositionNormalized(sf::RenderWindow& window)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2u windowSize = window.getSize();

	sf::Vector2f normPos;
	normPos.x = static_cast<float>(pixelPos.x) / static_cast<float>(windowSize.x);
	normPos.y = static_cast<float>(pixelPos.y) / static_cast<float>(windowSize.y);

	return normPos;


