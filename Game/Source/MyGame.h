#pragma once
#include "Game.h"
#include "Path.h"
#include <memory>
#include <vector>

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
	std::unique_ptr<Path> m_path;

	Font* m_font{nullptr};
	Font* m_fontLarge{nullptr};
	Text* m_textScore{nullptr};
	Text* m_textLives{nullptr};
	Text* m_textTitle{nullptr};

	bool m_hasSelectedActor = false;
	Actor* m_selectedActor;
	Vector2 m_selectedActorPrevPosition{0,0};

	int m_spawnIndex = 0;
	std::vector<std::string> m_roundContents[5];
};