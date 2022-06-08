#pragma once

#include "macros.h"
#include "ResourceManager.h"
#include "Image.h"


class ImageText : public Image
{
public:
    /* Constructor / Distructors*/

    ImageText(const std::string& str, const sf::Vector2f& loc);
    ~ImageText()= default;
    /* Draw */
     void draw(sf::RenderWindow& window) const override;

    /* Accesors */
    std::string getString() const;
    sf::Vector2f getPosition() const override;
    sf::FloatRect getGlobalBounds() const override;
    sf::Vector2f getSize() const override;
    float getFactor() const override;

    /* Mutator */
    void setOutlineColor(const sf::Color& color);
    void setOutlineThickness(const float thinkers);
    void setPosition(const sf::Vector2f& pos) override;
    void setString(const std::string& str);
    void setScale(const float scale) override;
    void setOrigin(const float x, const float y) override;
    void setSize(const sf::Vector2u size)  override;

private:
    /* Private Members*/
    sf::Text m_text;
};


