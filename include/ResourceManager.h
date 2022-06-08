//this class is singleton class
#pragma once

#include <unordered_map>
#include <string>
#include "macros.h"
#include "AnimationData.h"

class ResourceManager
{
public:
	//make the static event so we wont load the textures multiple times
	static ResourceManager& instance();
	sf::Texture* getTexture(const Bg_sp_t);
	sf::Texture* getTexture(const Dynamic_t);
	sf::Texture* getTexture(const Type_t);
	sf::Texture* getTexture(const Fighter_f);
	sf::Texture* getTexture2(const Fighter_f name);
	sf::Font* getFont (const Type_f name);
	void setSong(const int);
	void volUp();
	void volDown();
	void playSFX(Type_s sound);
	sf::SoundBuffer& getSound(const Type_s name);
	void setVolumeSong(const Type_s name, const int volume);
	const AnimationData& animationData(Fighter_f fighter) { return m_animationData[(int)fighter]; }
	const AnimationData& animationData(Bg_sp_t bg) { return m_animationData[2]; }
	const AnimationData& animationData(Dynamic_t bg) { return m_animationData[3]; }
private:

	ResourceManager(); //private ctor for singleton
	void loadTexture(const std::string, const Dynamic_t);
	void loadTexture(const std::string, const Bg_sp_t);
	void loadTexture(const std::string, const Type_t);
	void loadTexture(const std::string, const Fighter_f);
	void loadImage(const std::string& fileName, int character);
	void loadFont(const std::string path, const Type_f name);
	void loadSound(const std::string path, const Type_s name);
	void setSounds();
	void stopAllSongs();
	void playSong();
	void setVolumeAll();

	AnimationData dennisData() const;
	AnimationData firzenData() const;
	AnimationData BgData() const;
	AnimationData dennisBallData() const;
	AnimationData firzenBallData() const;



	std::unordered_map<Bg_sp_t, sf::Texture> m_bg_sp_texture;
	std::unordered_map<Dynamic_t, sf::Texture> m_dynamicAttack_texture;
	std::vector<std::vector<sf::Texture>> m_textures2;
	std::unordered_map<Type_t, sf::Texture> m_textures;
	std::unordered_map<Fighter_f, sf::Texture> m_fighters;
	std::unordered_map<Type_f, sf::Font> m_fonts;
	std::unordered_map<Type_s, sf::SoundBuffer> m_soundBuff;
	
	std::vector <sf::Sound> m_sounds;
	std::vector <AnimationData> m_animationData;
	Type_s m_playing;
	int m_volume = mediumVol;
};