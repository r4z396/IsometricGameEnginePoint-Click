#pragma once
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include <map>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
namespace SoloStudios {
	class AssetManager {

	public:
		AssetManager(){}
		~AssetManager() {}
		void test();
		template<typename T>		
		typename T LoadAsset(string name, string fileName);

		void LoadTexture(string name, string fileName);
		Texture &GetTexture(string name);

		void LoadFont(string name, string fileName);
		Font &GetFont(string name);

		

	private:
		map<string, Texture> _textures;
		map<string, Font> _fonts;
	};
}
#endif