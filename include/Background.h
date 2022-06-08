#pragma once
#include "macros.h"
#include "ImageTexture.h"

class Background : public ImageTexture
{
public:
    /* Constructor / Distructor */
    Background( const Type_t objectTex );
    virtual ~Background() = default;
private:
    sf::Sprite m_backgroundImg;
};