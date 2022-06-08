#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <exception>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <ranges>
#include <utility>
#include <sstream>
#include <optional>
#include <unordered_map>
#include <unordered_set>
#include<format>
#include <sstream>
#include <map>
#include <typeinfo>
#include <typeindex>

/* Controller Consts */
const auto WindowColor =  sf::Color(249, 231, 159);
const unsigned int WorldSize = 3500;
const unsigned int WindowHeight = 1100;
const unsigned int WindowWidth = 1550;
const auto endScreen = sf::Vector2i(WindowWidth, WindowHeight);
const auto backgroundPos = sf::Vector2f(WindowWidth, WindowHeight);
const auto sizeScreen = sf::Vector2u(WindowWidth, WindowHeight);
const auto centerScreen = sf::Vector2i(WindowWidth/2, WindowHeight/2);
const auto backgroundFactor = sf::Vector2f(1.f, 1.f);
const auto startWindow = sf::Vector2f(0.f, 0.f);
const float musicVolume = 20;
const float mute = 0;


/* Character Selection */
const auto Select_User_Image_Start_Pos = sf::Vector2f(200.f, 490.f);
const auto Select_User_Image_Space = sf::Vector2f(300.f, 400.f);
const auto Select_Fighter_Image_Start_Pos = sf::Vector2f(270.f, 320.f);
const auto Select_Fighter_Image_Space = sf::Vector2f(300.f, 400.f);
const auto Select_playerNum_Image_Start_Pos = sf::Vector2f(250.f, 200.f);
const auto Select_playerNum_Image_Space = sf::Vector2f(300.f, 400.f);
const auto Select_team_Image_Start_Pos = sf::Vector2f(200.f, 410.f);
const auto Select_team_Image_space_Pos = sf::Vector2f(300.f, 400.f);

enum class ActiveSelectType
{
    start, fighter, team, end
};

enum class selectType
{
    Commander, fighter, num, team
};


enum class Team
{
    Team_A, Team_B, Team_C, Team_d, EnemyTeam
};
const unsigned int maxOfTeams = 4;
const std::string teamStrings[maxOfTeams] = {"Team_A", "Team_B", "Team_C", "Team_D"};

/* Background*/

const auto GroundStart = sf::Vector2f(0.f, 500.f);
const auto GroundSize = sf::Vector2f(WorldSize, 400.f);
const auto GroundRect = sf::FloatRect(GroundStart, GroundSize);

/* China Wall Bacground*/
const auto sp_wc_rd2_bg_width = sf::Vector2f(90.f, 155.f);
const auto sp_wc_rd3_bg_width = sf::Vector2f(100.f, 155.f);
const auto wc_bg_roadStart_factor = sf::Vector2f(-230.f, 155.f);
const auto wc_bg_roadEnd_factor = sf::Vector2f(-1.f, 1.f);
const auto wc_bg_road2_factor = sf::Vector2f(90.f, 65.f);
const auto wc_bg_road3_factor = sf::Vector2f(100.f, 35.f);
const auto wc_bg_hill1_factor = sf::Vector2f(100.f, 140.f);
const auto wc_bg_hill2Start_factor = sf::Vector2f(100.f, 135.f);
const auto wc_bg_hill2End_factor = sf::Vector2f(-100.f, 135.f);
const auto wc_bg_sky_factor = sf::Vector2f(100.f, 135.f);

const auto wc_bg_roadStart_pos = sf::Vector2f(0, 150);
const auto wc_bg_roadEnd_pos = sf::Vector2f(WorldSize, 150.f);
const auto wc_bg_road2Start_pos = sf::Vector2f(150.f, 440.f);
const auto wc_bg_road3Start_pos = sf::Vector2f(0.f, 870.f);
const auto wc_bg_hill1_pos = sf::Vector2f(WorldSize/2.f, GroundSize.y);
const auto wc_bg_hill2Start_pos = sf::Vector2f(0.f, 200.f);
const auto wc_bg_hill2End_pos = sf::Vector2f(WorldSize, 500.f);
const auto wc_bg_sky_pos = sf::Vector2f(WorldSize / 2.f, GroundSize.y);
const auto cw_bg_color = sf::Color(154, 110, 90);
const auto cw_bg_numOfCopy = 40;



/* Stanley Prison Bacground*/
const auto sp_bg_width = sf::Vector2f(600, 400);
const auto sp_bg_wall_1_factor = sf::Vector2f(600.f, 400.f);
const auto sp_bg_wall_2_factor = sf::Vector2f(285.f, 100.f);
const auto sp_bg_wall_3_factor = sf::Vector2f(285.f, 100.f);
const auto sp_bg_wall_4_factor = sf::Vector2f(223.f, 215.f);
const auto sp_bg_fire_factor = sf::Vector2f(2.f, 2.f);
const auto sp_bg_wall_1_start = sf::Vector2f(0, 150);
const auto sp_bg_wall_2_start = sf::Vector2f(-125.f, 460.f);//start and check size height
const auto sp_bg_wall_3_start = sf::Vector2f(-125.f, 460.f);//same as 2
const auto sp_bg_wall_4_start = sf::Vector2f(-89.f, 150);//check size end and check size height
const auto sp_bg_fire_start = sf::Vector2f(77.f, 183);//check size end and check size height
const auto bg_numOfCopy = 6;
const auto sp_bg_color = sf::Color(90, 78, 75, 255);

enum class Bg_sp_t
{
    wall_1, wall_2, wall_3, wall_4, fire, road1, road2, road3, hill1, hill2, sky
};
const int num_Bg_Sp_Textures = 11;
const std::string Bg_Sp_Files[num_Bg_Sp_Textures] = { "wall.jpg", "wall2.jpg", "wall3.jpg", "wall4.jpg", "fire.png", "road1.jpg", "road2.jpg", "road3.jpg", "hill1.jpg" , "hill2.jpg", "sky.jpg" };


/* Textures  */
enum class Type_t
{
	bg_manu
};
const unsigned int numOfTextures = 1;
const std::string TextureFiles[numOfTextures] = { "bg_main_menu.jpg" };

enum class Dynamic_t
{
    dennisBall_t, FirzenBall_t
};
const unsigned int numOfDynamicAttack = 2;
const std::string DynamicAttackFiles[numOfDynamicAttack] = { "dennis_chase.png", "firzen_ball.png"};

enum class Fighter_f
{
	dennis_f, firzen_f, louis_f, bandit_f
};
const unsigned int numOfFighters = 3;
const std::string FightersFiles[numOfFighters] = { "dennis_f.jpg", "firzen_f.jpg", "louis_f.jpg" };

enum class CommandType
{
    ArrowUser, WASDUser, Computer
};
const std::string userString[3] = { "ArrowUser" ,"WASDUser", "Computer" };

struct playerData
{
	CommandType m_commander;
	Fighter_f m_fighter;
	unsigned int playerNum;
  Team team;
};

//Enemy consts

static const playerData enemyData ()
{
    playerData enemy;
    enemy.m_fighter = Fighter_f::bandit_f;
    enemy.m_commander = CommandType::Computer;
    enemy.playerNum = 9;
    enemy.team = Team::EnemyTeam;

    return enemy;
}


/* Fonts */
enum Type_f
{
	algertxt,
};
const int numOfFonts = 1;
const std::string FontFiles[numOfFonts] = { "ALGER.TTF" };


/* Sounds  */
const int mediumVol = 56;
const int volStep = 14;
const int volMax = 100;
const int volMin = 0;
enum Type_s
{

};
const int numOfSounds = 1;
const std::string SoundFiles[numOfSounds] = { "sadds" };

/* MovingObject Consts */
const float CharacterSpeed = 200.f;
const float sprintSpeed = 450.f;
const float jumpSpeed = 300.f;
const float fallSpeed = 100.f;
const float dwarfSpeed = 90.f;
const float dennisBallSpeed = 300.f;

/* Menu consts */
const int numOfButton = 3;
const int firstButton = 12;
const auto spaceButtons = 150.f;
const auto startButtons = 435.f;
const auto menuFactor = sf::Vector2f(1.f, 1.f);
const auto menuImagePosition = (sf::Vector2f)centerScreen;
const auto menuSize = sf::Vector2u(700, 950);
const auto buttonSize = sf::Vector2u(400, 150);

/* Selection Buttons const */
const auto Select_start_pos = sf::Vector2f(400.f, 400.f);
const auto Select_Factor = sf::Vector2f(1.f, 1.f);
const auto Select_Space = 100;

/* Menu Buttons const*/
const unsigned int characterSize =  40;
const auto AllVsAll_B = sf::Vector2f(600.f, 400);
const auto PracticeMode_B = sf::Vector2f(620.f, 480);
const auto StageMode_B = sf::Vector2f(650.f, 560.f);
const auto Help_B = sf::Vector2f(720.f, 640.f);
const auto Exit_B = sf::Vector2f(720.f, 720.f);
const auto boldSize = 10.f;
const auto buttonColor = sf::Color::White;
const auto buttonThinkerColor = sf::Color::Black;

/* Player const*/
const auto playerFactor = sf::Vector2f(2.f, 2.f);
const auto EnemyFactor = sf::Vector2f(1.f, 1.f);
const auto ballFactor = sf::Vector2f(0.73f, 0.73f);
const auto playerSpeed = 1.f;
const auto enemySpeed = 0.5f;

static const std::unordered_map < Fighter_f , float >
fighterSpeedData = 
{
  {   Fighter_f::dennis_f ,     playerSpeed},
  {   Fighter_f::firzen_f ,     playerSpeed},
  {   Fighter_f::louis_f  ,     playerSpeed},
  {   Fighter_f::bandit_f ,     enemySpeed}

};
static const std::unordered_map < Fighter_f , sf::Vector2f >
fighterFactorData = 
{
  {   Fighter_f::dennis_f ,     playerFactor},
  {   Fighter_f::firzen_f ,     playerFactor},
  {   Fighter_f::louis_f  ,     playerFactor},
  {   Fighter_f::bandit_f ,     EnemyFactor}

};








enum class State_t
{
	AllVsAll,
	PracticeMode,
	StageMode,
	Help,
};

enum class ActionType
{
    Beated, Bend, Burning, ComboA, Defend, DieBack, DieFront, Fading,
    Freezing, FallBack, FallFront, hit, Jump, MovingJump, Lift, OnFire, Punching,
    Roll, Smacked, SpecialDynamic, SpecialStatic, Sprinting, Standing,
    Walking, CreateBall, ShotBall, ExplodeBall
};

enum class Direction
{
	Start, Right, Down, Left, Up, Stay, End, LeftUp, LeftDown, RightUp, RightDown,
};
using Action = std::pair <ActionType, Direction>;

//Animation
const auto AnimationTime = sf::seconds(0.1f);
const auto firstPos = sf::Vector2f(600.f, 600.f);


/* Actions */
const auto ComboTime = sf::seconds(2.f);

//---------------------------------------------------------------------------------------------------
static const
      std::vector < std::vector < std::pair < std::vector <sf::Keyboard::Key>, Action  >>> comboData = 
      {
        //Dennis Combos
        {


          {{sf::Keyboard::Key::P, sf::Keyboard::Right, sf::Keyboard::Enter}, Action {ActionType::Lift, Direction::Right}},
          //{{sf::Keyboard::RControl, sf::Keyboard::Left, sf::Keyboard::Enter}, Action {ActionType::ComboA, Direction::Left}},
          {{sf::Keyboard::Key::O }, Action {ActionType::ComboA, Direction::Left}},
          


        },
        
        

        //Firzen Combos
        {





        },
        //Louis Combos
        {





        }




      };

//---------------------------------------------------------------------------------------------------
static const
  std::vector<std::vector<std::pair < sf::Keyboard::Key, Direction >>>
        mapKeyboardToDir = 
    {
      {
          {sf::Keyboard::Right    ,  Direction::Right  },
          {sf::Keyboard::Left     ,  Direction::Left   },
          {sf::Keyboard::Up       ,  Direction::Up     },
          {sf::Keyboard::Down     ,  Direction::Down   }
      },
      
      {
          { sf::Keyboard::D       ,  Direction::Right  },
          { sf::Keyboard::A       ,  Direction::Left   },
          { sf::Keyboard::W       ,  Direction::Up     },
          { sf::Keyboard::S       ,  Direction::Down   }

      }      
    };

//---------------------------------------------------------------------------------------------------
static const
    std::vector < std::pair < std::vector < Direction > , Direction > >
    finalDirection =
    {
      { { Direction::Right                  },              Direction::Right      },
      { { Direction::Right, Direction::Down },              Direction::RightDown  },
      { { Direction::Right, Direction::Up   },              Direction::RightUp    },
      { { Direction::Left                   },              Direction::Left       },
      { { Direction::Left, Direction::Up    },              Direction::LeftUp     },
      { { Direction::Left, Direction::Down  },              Direction::LeftDown   },
      { { Direction::Up                     },              Direction::Up         },
      { { Direction::Down                   },              Direction::Down       }
    };

//---------------------------------------------------------------------------------------------------
static const
    std::vector<std::vector < std::pair < sf::Keyboard::Key, ActionType>>>
    mapKeyboardToActionType =
    {   
      {
        { sf::Keyboard::Enter     ,  ActionType::Punching   },
        { sf::Keyboard::RControl  ,  ActionType::Defend     },
        { sf::Keyboard::RShift    ,  ActionType::Jump       },
        { sf::Keyboard::Space     ,  ActionType::Sprinting  },
        { sf::Keyboard::Delete    ,  ActionType::Standing   }
      },
      {
        { sf::Keyboard::T         ,  ActionType::Punching   },
        { sf::Keyboard::Y         ,  ActionType::Defend     },
        { sf::Keyboard::U         ,  ActionType::Jump       },
        { sf::Keyboard::Tab       ,  ActionType::Sprinting  },
        { sf::Keyboard::Delete    ,  ActionType::Standing   },
        { sf::Keyboard::Q         ,  ActionType::Freezing   }
      }
    };

//---------------------------------------------------------------------------------------------------
static const
  std::unordered_map < ActionType, float > 
  delayOfAction =
  {
    {   ActionType::Beated,             0.3f  },
    {   ActionType::Bend,               0.6f  },
    {   ActionType::Burning,            0.6f  },
    {   ActionType::ComboA,             0.3f  },
    {   ActionType::Defend,             0.6f  },
    {   ActionType::DieBack,            2.f   },
    {   ActionType::DieFront,           0.6f  },
    {   ActionType::Fading,             0.6f  },
    {   ActionType::Freezing,           0.6f  },
    {   ActionType::FallBack,           0.3f  },
    {   ActionType::FallFront,          0.6f  },
    {   ActionType::hit,                0.02f },
    {   ActionType::Jump,               0.6f  },
    {   ActionType::Lift,               0.6f  },
    {   ActionType::OnFire,             0.6f  },
    {   ActionType::Punching,           0.6f  },
    {   ActionType::Roll,               0.6f  },
    {   ActionType::Smacked,            0.4f  },
    {   ActionType::SpecialDynamic,     0.6f  },
    {   ActionType::SpecialStatic,      0.6f  },
    {   ActionType::CreateBall,         0.4f  },
    {   ActionType::ExplodeBall,        0.4f  },
  };

//---------------------------------------------------------------------------------------------------
static const
  std::unordered_map < ActionType, float > 
  speedOfAction =
  {
    {   ActionType::Standing,           CharacterSpeed  },
    {   ActionType::Walking,            CharacterSpeed  },
    {   ActionType::Beated,             CharacterSpeed  },
    {   ActionType::Bend,               CharacterSpeed  },
    {   ActionType::Burning,            CharacterSpeed  },
    {   ActionType::ComboA,             CharacterSpeed  },
    {   ActionType::Defend,             CharacterSpeed  },
    {   ActionType::DieBack,            CharacterSpeed  },
    {   ActionType::DieFront,           CharacterSpeed  },
    {   ActionType::Fading,             CharacterSpeed  },
    {   ActionType::Freezing,           CharacterSpeed  },
    {   ActionType::FallBack,           fallSpeed       },
    {   ActionType::FallFront,          fallSpeed       },
    {   ActionType::hit,                CharacterSpeed  },
    {   ActionType::Jump,               jumpSpeed       },
    {   ActionType::Lift,               CharacterSpeed  },
    {   ActionType::OnFire,             CharacterSpeed  },
    {   ActionType::Punching,           CharacterSpeed  },
    {   ActionType::Roll,               CharacterSpeed  },
    {   ActionType::Smacked,            CharacterSpeed  },
    {   ActionType::SpecialDynamic,     CharacterSpeed  },
    {   ActionType::Sprinting,          sprintSpeed     },
    {   ActionType::SpecialStatic,      CharacterSpeed  },
    {   ActionType::CreateBall,         CharacterSpeed  },
    {   ActionType::ExplodeBall,        CharacterSpeed  },
  };

//---------------------------------------------------------------------------------------------------
static const
 std::unordered_map < ActionType, ActionType > nextActionMap =
 {
   {   ActionType::Beated,            ActionType::FallBack    },
   {   ActionType::Bend,              ActionType::FallBack    },
   {   ActionType::Burning,           ActionType::DieBack     },
   {   ActionType::ComboA,            ActionType::FallBack    },
   {   ActionType::Defend,            ActionType::FallBack    },
   {   ActionType::DieBack,           ActionType::DieBack     },
   {   ActionType::DieFront,          ActionType::DieFront    },
   {   ActionType::Fading,            ActionType::FallBack    },
   {   ActionType::Freezing,          ActionType::DieBack     },
   {   ActionType::FallBack,          ActionType::DieBack     },
   {   ActionType::FallFront,         ActionType::DieFront    },
   {   ActionType::hit,               ActionType::FallBack    },
   {   ActionType::Jump,              ActionType::FallBack    },
   {   ActionType::Lift,              ActionType::FallBack    },
   {   ActionType::OnFire,            ActionType::FallBack    },
   {   ActionType::Punching,          ActionType::FallBack    },
   {   ActionType::Roll,              ActionType::FallBack    },
   {   ActionType::Smacked,           ActionType::FallBack    },
   {   ActionType::SpecialDynamic,    ActionType::FallBack    },
   {   ActionType::SpecialStatic,     ActionType::FallBack    },
 };

//---------------------------------------------------------------------------------------------------
static const
std::unordered_map < Direction , Direction >
firstStageJumpMap = 
{
  { Direction::Right,         Direction::RightUp      },
  { Direction::RightUp,       Direction::RightUp      },
  { Direction::RightDown,     Direction::RightUp      },
  { Direction::Left,          Direction::LeftUp       },
  { Direction::LeftUp,        Direction::LeftUp       },
  { Direction::LeftDown,      Direction::LeftUp       },
  { Direction::Up,            Direction::Up           },
  { Direction::Down,          Direction::Up           },
  { Direction::Stay,          Direction::Up           },
};

//---------------------------------------------------------------------------------------------------
static const
std::unordered_map < Direction , Direction >
secondStageJumpMap = 
{
  { Direction::Right,         Direction::RightDown    },
  { Direction::RightUp,       Direction::RightDown    },
  { Direction::RightDown,     Direction::RightDown    },
  { Direction::Left,          Direction::LeftDown     },
  { Direction::LeftUp,        Direction::LeftDown     },
  { Direction::LeftDown,      Direction::LeftDown     },
  { Direction::Up,            Direction::Down         },
  { Direction::Down,          Direction::Down         },
  { Direction::Stay,          Direction::Down         },
};

//---------------------------------------------------------------------------------------------------

static const
std::unordered_map < int , Direction >
randomMapDirection = 
{
  { 0,              Direction::Right      },
  { 1,              Direction::RightDown  },
  { 2,              Direction::RightUp    },
  { 3,              Direction::Left       },
  { 4,              Direction::LeftUp     },
  { 5,              Direction::LeftDown   },
  { 6,              Direction::Up         },
  { 7,              Direction::Down       }
};


/* Damage and mana consts */
const auto  PunchDmg = 2.f;
const auto  dennisBallDmg = 100.f;
const auto firzenBallDmg = 100.f;