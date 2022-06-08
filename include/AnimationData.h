#pragma once
#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>
#include "macros.h"

struct AnimationData
{
	//a map with keys = ActionType , and value = vector of IntRect
	//holds a vector of a cut sprite sheet
	using ListType = std::vector<sf::IntRect>;
	using DataType = std::unordered_map<ActionType, ListType>;
	DataType m_data;

	// AnimationData& operator+=(const AnimationData& other);	
};


// AnimationData& AnimationData::operator+=(const AnimationData& other){


// 	for (auto& otherItem : other.m_data)
// 	{
// 		auto thisItem = this->m_data.find(otherItem.first);

// 		if (thisItem != this->m_data.end())
// 			thisItem->second.insert( thisItem->second.end(), 
// 							std::make_move_iterator(otherItem.second.begin()),
//       						std::make_move_iterator(otherItem.second.end()));

// 		else
// 			this->m_data[otherItem.first] = otherItem.second;

// 	}
	
//       return *this;
// }




// AnimationData& operator+= (const AnimationData& other)
// {
// 	for (auto& otherItem : other.m_data)
// 	{
// 		auto thisItem = this->m_data.find(otherItem.first);

// 		if (thisItem != this->m_data.end())
// 			thisItem->second.insert( thisItem->second.end(), 
// 							std::make_move_iterator(otherItem.second.begin()),
//       						std::make_move_iterator(otherItem.second.end()));

// 		else
// 			this->m_data[otherItem.first] = otherItem.second;

// 	}
	
//       return *this;
// }