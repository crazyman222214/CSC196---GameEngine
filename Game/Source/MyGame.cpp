#include "MyGame.h"
#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "Font.h"
#include "Text.h"
#include "GameData.h"

#include "SquareMan.h"
#include "TriangleMan.h"
#include "CircleMan.h"
#include "Crossbow.h"
#include "Cannon.h"
#include "WizardTower.h"

#include "Path.h"
#include "UI.h"
#include "UnitRadius.h"
#include <memory>
#include <iostream>
#include <string>


//TODO: Add win/loss condition
//TODO: Add sounds
//TODO: Add particle system


bool MyGame::Initialize()
{
    m_scene = new Scene(this);
    m_font = new Font();
    m_font->Load("Blockletter.otf", 20);

    m_textScore = new Text(m_font);
    m_textLives = new Text(m_font);
    m_textTitle = new Text(m_font);

    m_roundContents[0] = std::vector<std::string>{"Triangle", "Triangle", "Circle", "Square", "Square", "Triangle", "Square"};
    m_roundContents[1] = std::vector<std::string>{"Triangle", "Square", "Triangle", "Square", "Circle", "Circle", "Square", "Triangle", "Circle", "Triangle", "Square"};
    m_roundContents[2] = std::vector<std::string>{"Triangle", "Square", "Triangle", "Triangle", "Square", "Triangle", "Triangle", "Square", "Triangle", "Triangle", "Square", "Triangle"};
    m_roundContents[3] = std::vector<std::string>{"Circle", "Triangle", "Circle", "Circle", "Triangle", "Triangle", "Square", "Triangle", "Square", "Triangle", "Circle", "Circle", "Triangle", "Triangle", "Triangle", "Triangle", "Triangle" };
    m_roundContents[4] = std::vector<std::string>{"Triangle", "Circle", "Square", "Square", "Square", "Square", "Triangle", "Triangle", "Circle", "Triangle", "Square", "Square", "Square", "Square", "Square", "Square", "Triangle", "Square", "Triangle", "Circle", "Triangle", "Circle", "Square", "Square"};

    return true;
}

void MyGame::Shutdown()
{
    m_engine->Shutdown();
}

void MyGame::Update(float dt)
{
    switch (m_state)
    {
    case State::TITLE:
        if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE)) m_state = State::STARTGAME;
        
        break;
    case State::STARTGAME:
        //Restart all values
        m_currentRound = 0;
        m_lives = 3;
        m_spawnIndex = 0;
        m_spawnTime = 2;

         m_engine->GetAudio().AddSound("Bomb.wav");
         m_engine->GetAudio().AddSound("Lightning.wav");
         m_engine->GetAudio().AddSound("Arrow.wav");
         m_engine->GetAudio().AddSound("Tribes.mp3");

        m_state = State::STARTLEVEL;
        break;
    case State::STARTLEVEL:
        m_scene->RemoveAll();
        {
            m_engine->GetAudio().PlaySound("Tribes.mp3");

            Transform pathTransform{ {0,50}, 0, 1 };
            //Path reference for variables
            m_path = std::make_unique<Path>(pathTransform);

            //Path passed into scene
            auto path = std::make_unique<Path>(pathTransform);
            path.get()->SetTag("Visual");
            m_scene->AddActor(std::move(path));

            Transform uiTransform{ {m_engine->GetRenderer().GetWidth() - 125, 50}, 0, 1};
            auto ui = std::make_unique<UI>(uiTransform);
            ui.get()->PopulateUI(*m_scene);
            ui.get()->SetTag("Visual");
            m_scene->AddActor(std::move(ui));

            Transform towerTransform{ {300, 500}, 0, 4 };
            auto wizardTower = std::make_unique<Cannon>(towerTransform);
            wizardTower->SetDamping(0.4f);
            wizardTower->SetTag("Player");
            m_scene->AddActor(std::move(wizardTower));


            Transform transform{ {400, 500}, 0, 1 };
            auto unitCircle = std::make_unique<UnitRadius>(100.0f, transform);
            m_scene->AddActor(std::move(unitCircle));

            m_spawnTime = 2;
            m_spawnTimer = m_spawnTime;
            m_state = State::GAME;
        }
        break;

    case State::GAME:
    {
        m_spawnTimer -= dt;

        auto& round = m_roundContents[m_currentRound];
        

        if (m_spawnTimer <= 0 && m_spawnIndex != round.size())
        {
            m_spawnTimer = m_spawnTime;

            Transform transform{ ((GameData::pathPoints[0]) + (m_path.get()->GetTransform().position)), 0, 5 };
            std::string enemyName = round[m_spawnIndex];
            if (enemyName == "Triangle")
            {
                auto triangleMan = std::make_unique<TriangleMan>(transform, *m_path);
                triangleMan->SetTag("Enemy");
                m_scene->AddActor(std::move(triangleMan));
            }
            else if (enemyName == "Square")
            {
                auto squareMan = std::make_unique<SquareMan>(transform, *m_path);
                squareMan->SetTag("Enemy");
                m_scene->AddActor(std::move(squareMan));
            }
            else if (enemyName == "Circle")
            {
                auto circleMan = std::make_unique<CircleMan>(transform, *m_path);
                circleMan->SetTag("Enemy");
                m_scene->AddActor(std::move(circleMan));
            }

            m_spawnIndex++;
            
        }

        if (m_spawnIndex == round.size() && !m_scene->AreThereEnemies())
        {
            NextRound();
            m_spawnIndex = 0;
            m_spawnTime = 1.5f;
        }

        //If the mouse position is in the same as a ui actor, store that actor
        if (m_engine->GetInput().GetMouseButtonDown(0) && !m_engine->GetInput().GetPrevMouseButtonDown(0))
        {
            Vector2 position = m_engine->GetInput().GetMousePosition();
            Actor* actor = m_scene->GetActorFromPosition(position);

            if (actor && actor->GetTag() == "UI" && !m_hasSelectedActor)
            {
                m_hasSelectedActor = true;
                m_selectedActor = actor;
                m_selectedActorPrevPosition = m_selectedActor->GetTransform().position;

            }

            if (actor && actor->GetTag() == "Player")
            {
                Player* player = dynamic_cast<Player*>(actor);
                player->GetUnitRadius().get()->SetActive(!player->GetUnitRadius().get()->GetActive());

                std::cout << "Yay player";
            }


        }

        if (m_lives == 0)
        {
            m_state = State::GAMEOVER;
        }

        if (m_hasSelectedActor)
        {
            m_selectedActor->UpdateTransformToMouse(m_engine->GetInput(), m_selectedActorPrevPosition);

            if (m_engine->GetInput().GetMouseButtonDown(1))
            {
                m_hasSelectedActor = false;
                m_selectedActor->SetTag("Player");

                dynamic_cast<Player*>(m_selectedActor)->GetUnitRadius().get()->UpdateTransformToMouse(m_engine->GetInput(), { m_selectedActor->GetTransform().position.x + m_selectedActor->GetRadius() / 4, m_selectedActor->GetTransform().position.y - m_selectedActor->GetRadius() / 4 });
            }


            if (m_engine->GetInput().GetMouseButtonDown(2))
            {
                m_hasSelectedActor = false;
                m_selectedActor = nullptr;

            }
        }
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
        m_scene->RemoveAll();
        
        
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
        m_textTitle->Create(renderer, "Tower Defense", Color{ 1,0,0,1 });
        m_textTitle->Draw(renderer, 300, 400);
        break;
    case State::GAME:
        m_textScore->Create(renderer, "Round " + std::to_string(m_currentRound + 1), { 0,1,0,1 });
        m_textScore->Draw(renderer, 20, 20);

        m_textScore->Create(renderer, "Lives " + std::to_string(m_lives), { 0,1,0,1 });
        m_textScore->Draw(renderer, renderer.GetWidth() - 100, 20);
        break;
    case State::GAMEOVER:
        break;
    default:
        break;
    }

    
    m_engine->GetPS().Draw(renderer);
    m_scene->Draw(renderer);
}

void MyGame::OnPlayerDeath()
{
    m_lives--;
    m_state = (m_lives == 0) ? State::GAMEOVER : State::PLAYERDEAD;
    m_stateTimer = 3;
}