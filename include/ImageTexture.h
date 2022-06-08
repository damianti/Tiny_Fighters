#pragma once
#include <vector>
#include <utility>
#include "macros.h"
#include "ResourceManager.h"
#include "Image.h"

class ImageTexture : public Image
{
public:
    
    /* Constructor / Distructor */
    ImageTexture(const sf::Vector2f& CenterPos, Type_t objectTex, const sf::Vector2f& factor);
    ImageTexture( const sf::Vector2f& CenterPos, const Fighter_f& objectTex, const sf::Vector2f& factor);
    ImageTexture( const sf::Vector2f& CenterPos, const Bg_sp_t& objectTex, const sf::Vector2f& factor);
    ImageTexture( const sf::Vector2f& CenterPos, const sf::Vector2f& factor);
    virtual ~ImageTexture() = default;

    /* draw */
    void draw( sf::RenderWindow& window ) const override;
    /* Accesors */
    sf::Vector2f getPosition() const override;
    sf::Vector2f getSize() const override;
    float getFactor() const override;
    sf::FloatRect getGlobalBounds() const override;

    /* Mutator */
    void setPosition( const sf::Vector2f& pos ) override;
    void setScale( const float scale ) override;
    void setOrigin( const float x, const float y ) override;
    void setSize( const sf::Vector2u size ) override;
    void setTexture( const Fighter_f& objectTex) ;
protected:
    sf::Sprite m_sprite;

    void initImage(const sf::Vector2f& CenterPos, sf::Texture* texture, const sf::Vector2f& factor);
};
