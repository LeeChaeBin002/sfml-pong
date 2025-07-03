#pragma once
enum class Axis
{
	Horizontal,
	vertical,
};

struct AxisInfo
{
	Axis axis;
	std::list<sf::Keyboard::Key> positivies;//1.f;양수
	std::list<sf::Keyboard::Key> nagatives;//1.f;음수
	float sensi = 10.f;
	float value = 0.f;

};

class InputMgr
{
private:
	static std::list<sf::Keyboard::Key> downKeys;
	static std::list<sf::Keyboard::Key> heldKeys;//눌려있는
	static std::list<sf::Keyboard::Key> upKeys;

	

	static std::unordered_map<Axis, AxisInfo>axisInfoMap;
public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);
	static void Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);

	static float GetAxisRaw(Axis axis);
	static float GetAxis(Axis axis);

	static bool GetMouseButtonDown(sf::Mouse::Button key);
	static bool GetMouseButtonUp(sf::Mouse::Button key);
	static bool GetMouseButton(sf::Mouse::Button key);
	static sf::Vector2i GetMousePosition(sf::RenderWindow& window);

	

};

