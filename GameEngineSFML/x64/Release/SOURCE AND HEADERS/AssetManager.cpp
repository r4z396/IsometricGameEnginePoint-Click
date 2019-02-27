

#include "AssetManager.h"
#include <iostream>
namespace SoloStudios {

	template<typename T>
	T getAsset(string name, string fileName) {


/*
		if constexpr (std::is_same<T, bool>) return _boolValueOf();
		else if constexpr (std::is_same<T, int>) return _intValueOf();
		else if constexpr (std::is_same<T, std::string>) return _std_stringValueOf();*/


	}

	void AssetManager::LoadTexture(string name, string fileName) {
		
		Texture tex;

		if (tex.loadFromFile(fileName)) {

			this->_textures[name] = tex;
		}
	}

	Texture &AssetManager::GetTexture(string name) {
		return this->_textures.at(name);
	}


	void AssetManager::LoadFont(string name, string fileName) {

		Font font;

		if (font.loadFromFile(fileName)) {

			this->_fonts[name] = font;
		}
	}

	Font &AssetManager::GetFont(string name) {
		return this->_fonts.at(name);
	}

	void AssetManager::test() {
		std::cout << "testMAAAAAAAAP";
	}
}