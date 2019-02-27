#ifndef ACTIONTAGET_HPP
#define ACTIONTAGET_HPP

#include "ActionMap.h"
#include <ppl.h>

#include <functional> //function
#include <utility> //pair
#include <list> //list

namespace SoloStudios
{
    template<typename T = int>
    class ActionTarget
    {
        public:
            ActionTarget(const ActionTarget<T>&) = delete;
            ActionTarget<T>& operator=(const ActionTarget<T>&) = delete;

            using FuncType = std::function<void(const sf::Event&)>;

            ActionTarget(const ActionMap<T>& map);

            bool processEvent(const sf::Event& event)const;
            void processEvents()const;

            void bind(const T& key,const FuncType& callback);
            void unbind(const T& key);

        private:
            std::list<std::pair<T,FuncType>> _eventsRealTime;
            std::list<std::pair<T,FuncType>> _eventsPoll;

            const ActionMap<T>& _actionMap;
    };
}
#include </ERASMUS/GAME PROGRAMMING/C++/Engine/GameEngineSFML/GameEngineSFML/ActionTarget.tpl>

#endif
