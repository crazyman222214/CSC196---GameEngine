#include "MyGame.h"
#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "GameData.h"
#include "TriangleMan.h"
#include "Font.h"
#include "Text.h"

bool MyGame::Initialize()
{
    m_scene = new Scene(this);
    m_font = new Font();
    m_font->Load("Blockletter.otf", 20);

    m_textScore = new Text(m_font);
    m_textLives = new Text(m_font);
    m_textTitle = new Text(m_font);
    return true;
}

void MyGame::Shutdown()
{

}

void MyGame::Update(float dt)
{
    switch (m_state)
    {
    case State::TITLE:
        if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE)) m_state = State::STARTGAME;
        m_textTitle->Create(m_engine->GetRenderer(), "Tower Defense", Color{1,0,0,1});
        m_textTitle->Draw(m_engine->GetRenderer(), 300, 400);
        break;
    case State::STARTGAME:
        //Restart all values
        m_score = 0;
        m_lives = 3;

        m_state = State::STARTLEVEL;
        break;
    case State::STARTLEVEL:
        m_scene->RemoveAll();
        {
            Transform transform{ {400, 400}, 0, 5 };

            Model* model = new Model{ GameData::TriangleManPoints, Color{0,0,1} };
            Player* player = new Player(400, transform, model);
            player->SetDamping(0.4f);
            player->SetTag("Player");
            m_scene->AddActor(player);

            m_spawnTime = 2;
            m_spawnTimer = m_spawnTime;
            m_state = State::GAME;
        }
        break;

    case State::GAME:
        m_spawnTimer -= dt;
        if (m_spawnTimer <= 0)
        {
            m_spawnTimer = m_spawnTime;

            Transform transform3{ {600, 300}, 0, 5 };
            auto* squareMan = new TriangleMan(transform3);
            squareMan->SetTag("Enemy");
            m_scene->AddActor(squareMan);
        }
        break;
    case State::PLAYERDEAD:
        m_stateTimer -= dt;
        if (m_stateTimer <= 0)
        {
            m_stateTimer = 3;
            m_state = State::STARTLEVEL;
        }
        break;
    case State::GAMEOVER:
        m_state = State::TITLE;
        break;
    default:
        break;
    }

    m_scene->Update(dt);
}

void MyGame::Draw(Renderer& renderer)
{
    switch (m_state)
    {
    case State::TITLE:
        break;
    case State::GAMEOVER:
        break;
    default:
        break;
    }

    std::string text = "Score " + std::to_string(m_score);
    m_textScore->Create(renderer, text, {0,1,0,1});
    m_textScore->Draw(renderer, 20, 20);

    text = "Lives " + std::to_string(m_lives);
    m_textScore->Create(renderer, text, {0,1,0,1});
    m_textScore->Draw(renderer, renderer.GetWidth() - 100, 20);

    m_scene->Draw(renderer);
}

void MyGame::OnPlayerDeath()
{
    m_lives--;
    m_state = (m_lives == 0) ? State::GAMEOVER : State::PLAYERDEAD;
    m_stateTimer = 3;
}