#pragma once
#include "Game.h"

class Font;
class Text;
class MyGame : public Game
{
public:
	enum class State
	{
		TITLE,
		STARTGAME,
		STARTLEVEL,
		GAME,
		PLAYERDEAD,
		GAMEOVER
	};

	MyGame(Engine* engine) : Game{ engine } {}

	bool Initialize() override;
	void Shutdown() override;

	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	void OnPlayerDeath();

private:
	State m_state{ State::TITLE };
	float m_spawnTimer = 0;
	float m_spawnTime = 0;
	float m_stateTimer = 0;

	Font *m_font{nullptr};
	Text* m_textScore{nullptr};
	Text* m_textLives{nullptr};
	Text* m_textTitle{nullptr};
};