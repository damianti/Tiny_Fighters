#include "ImageText.h"


/* Constructors / Distructors */
ImageText::ImageText(const std::string& str, const sf::Vector2f& loc)

{
    sf::Text text;
    sf::Font* font = ResourceManager::instance().getFont(Type_f::algertxt);
	
	text.setFont(*font);
	text.setString(str);
	text.setPosition(loc);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(characterSize);

    m_text = text;
}

/* Mutator */
void ImageText::setString(const std::string& str)
{
	sf::Text text;
	sf::Font* font = ResourceManager::instance().getFont(Type_f::algertxt);

	text.setFont(*font);
	text.setString(str);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(characterSize);
	text.setPosition(m_text.getPosition());
	m_text = text;
}

void ImageText::setPosition(const sf::Vector2f& pos)
{
	m_text.setPosition(pos);
}

void ImageText::setSize(const sf::Vector2u size)
{
	m_text.scale((size.x / m_text.getGlobalBounds().width), (size.y / m_text.getGlobalBounds().height));
}

void ImageText::setOrigin(const float x, const float y)
{
	m_text.setOrigin(x, y);
}

void ImageText::setScale(const float scale)
{
	m_text.setScale(sf::Vector2f(scale, scale));
}


void ImageText::setOutlineColor(const sf::Color& color)
{
	m_text.setOutlineColor(color);
}


void ImageText::setOutlineThickness(const float thinkers)
{
	m_text.setOutlineThickness(thinkers);
}

/* Accesors */

sf::Vector2f ImageText::getPosition() const
{
	return m_text.getPosition();
}

std::string ImageText::getString() const
{
	return m_text.getString();
}

sf::FloatRect ImageText::getGlobalBounds() const
{
	return m_text.getGlobalBounds();
}

sf::Vector2f ImageText::getSize() const
{
	return sf::Vector2f(float(m_text.getGlobalBounds().width), float(m_text.getGlobalBounds().height));
}

float ImageText::getFactor() const
{
	return m_text.getScale().x;
}

/* draw */
void ImageText::draw(sf::RenderWindow& window) const
{
	window.draw(m_text);
}