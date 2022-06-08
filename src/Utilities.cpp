#include "Utilities.h"



//if received direction left and looking right or received direction right and looking left
void correctDir(sf::Sprite& pic, Direction dir)
{
	if ((dir == Direction::Left && pic.getScale().x > 0) ||
        (dir == Direction::LeftUp && pic.getScale().x > 0) ||
        (dir == Direction::LeftDown && pic.getScale().x > 0) ||
        (dir == Direction::Right && pic.getScale().x < 0) ||
        (dir == Direction::RightUp && pic.getScale().x < 0) ||
		(dir == Direction::RightDown && pic.getScale().x < 0))
		pic.scale(-1, 1);
}



inline sf::Vector2f toVector(Direction dir)
{
    static const
        std::unordered_map<Direction, sf::Vector2f>
        dirToVector =
    {
        { Direction::Right     , { 1, 0 }  },
        { Direction::Left      , { -1, 0 } },
        { Direction::Up        , { 0, -1 } },
        { Direction::Down      , { 0, 1 }  },
        { Direction::Stay      , { 0, 0 }  },
        { Direction::LeftUp    , {-1, -1}  },
        { Direction::LeftDown  , {-1, 1}   },
        { Direction::RightUp   , {1, -1}   },
        { Direction::RightDown , {1, 1}    },
        { Direction::Stay      , {0, 0}    },
    };
    return dirToVector.at(dir);
}


inline Direction toDir (const sf::Vector2f victor)
{
    if (victor.x == -1)
    {
        if (victor.y == -1)
            return Direction::LeftUp;
        else if (victor.y == 0)
            return Direction::Left;
        else if (victor.y == 1)
            return Direction::LeftDown;
        else 
            throw std::runtime_error("Unknown victor");
    }
    else if (victor.x == 0)
    {
           if (victor.y == -1)
            return Direction::Up;
        else if (victor.y == 0)
            return Direction::Stay;
        else if (victor.y == 1)
            return Direction::Down;
        else 
            throw std::runtime_error("Unknown victor");
    }
    else if (victor.x == 1)
    {
           if (victor.y == -1)
            return Direction::RightUp;
        else if (victor.y == 0)
            return Direction::Right;
        else if (victor.y == 1)
            return Direction::RightDown;
        else 
            throw std::runtime_error("Unknown victor");
    }
    else 
        throw std::runtime_error("Unknown victor");
}


 Direction oppositeDir(Direction dir)
{
    auto dirToVector = toVector(dir);
    return toDir(sf::Vector2f(dirToVector.y, dirToVector.x));
}

 sf::Vector2f OpposideVector(Direction dir)
{
    auto dirToVector = toVector(dir);
    return -dirToVector;
}

 bool collide(GameObject& a, GameObject& b)
 {
     return a.collidWith(b);
 }

 float calcDistance(const sf::Vector2f& v1, const sf::Vector2f& v2)
 {
     return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
 }

 Direction TextureFacing(sf::Sprite& pic) 
 {
     if (pic.getScale().x < 0 )
         return Direction::Left;
     return Direction::Right;
 }