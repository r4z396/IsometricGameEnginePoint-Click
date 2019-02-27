#include "DialogManager.h"

using namespace std;

using namespace rapidxml;

namespace SoloStudios {
	DialogManager::DialogManager(sf::Font& font):font(font)
	{
		/*this->font = font;*/
	}


	DialogManager::~DialogManager()
	{
	}

	void DialogManager::init(sf::Font& font) {
		
	}

	void DialogManager::Update(sf::RenderWindow* pWindow) {
		/*pWindow->draw(_text);*/
		
		if (indexQuote < numbQuotes) {
			quoteList[indexQuote]->Update(pWindow);
			time = timer_clock.getElapsedTime().asSeconds();
			if (time > quoteList[indexQuote]->_duration) {
				indexQuote++;
				timer_clock.restart();
			}
		}
		
		
	}
	void DialogManager::loadDialogsLevel() {
		cout << endl << "-----------------"<< endl;
		cout << endl << "Loading Dialogs" << endl;

		
		cout << endl;

		//_data->assetManager.test();
		//this->_data->assetManager;
		cout << "Loading map2";
		cout << endl;
		ifstream MyFile("dialog.xml", ios::binary);
		cout << "Loading map3";
		cout << endl;
		vector<char> buffer((istreambuf_iterator<char>(MyFile)), istreambuf_iterator<char>());
		cout << "Loading map4";
		cout << endl;
		buffer.push_back('\0');
		cout << "Loading map5";
		cout << endl;
		MyFile.close();

		xml_document<>		Doc;
		Doc.parse<0>(&buffer[0]);

		xml_node<>*	pRootNode = Doc.first_node();

		xml_node<>*				pNode;
		xml_node<>*				pChild;
		xml_attribute<>*	pAttr;

		
		cout << endl;

		
		pNode =FindChildNodeWithAttribute(pRootNode, "level","1") ;
		if (pNode != NULL) {
			//pAttr = FindAttribute(pNode, "");
			xml_node<>* pChildQuotes = pNode->first_node();
			cout << " QUotes this level " << pChildQuotes->name();

			xml_attribute<>*	pAttr = FindAttribute(pChildQuotes, "size");
			cout << " number of quotes " << atoi(pAttr->value());
			numbQuotes = atoi(pAttr->value());
			
			/*pChild = pChild->first_node();*/
			 for (xml_node<>* pChild = pChildQuotes->first_node(); pChild != NULL; pChild = pChild->next_sibling()) {
				 Quote* quote = new Quote(font);
				 cout << endl << "Adding one quote" << endl;
				pAttr = FindAttribute(pChild, "id");
				cout << " id " << atoi(pAttr->value());


				pAttr = FindAttribute(pChild, "duration");
				quote->_duration = atoi(pAttr->value());				
				cout << " duration " << atoi(pAttr->value());
				
				quote->text = pChild->value();
				quote->_text.setString(quote->text);
				cout << " Text " << pChild->value();

				pAttr = FindAttribute(pChild, "posX");
				cout << " posX " << atoi(pAttr->value());
				quote->pos.x= atoi(pAttr->value());
				pAttr = FindAttribute(pChild, "posY");
				cout << " posY " << atoi(pAttr->value());
				quote->pos.y=atoi(pAttr->value());
				quoteList.push_back(quote);
				cout << endl << "Finish adding" << endl;


			}

		
		}
		
	}
}