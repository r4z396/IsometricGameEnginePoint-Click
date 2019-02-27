
#pragma once

#include "StateMachine.h"

namespace SoloStudios {

	void StateMachine::AddState(StateRef newState, bool isReplacing) {
		this->_isAdding = true;
		this->_isReplacing = true;
		this->_newState = move(newState);




	}

	void StateMachine::RemoveState() {

		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges() {
		if (this->_isRemoving && !this->_states.empty()) {
			this->_states.pop();

			if (!this->_states.empty()) {
				this->_states.top()->Resume();
			}

			this->_isRemoving = false;
		}

		if (this->_isAdding) {

			if (!this->_states.empty()) {
				if (this->_isReplacing) {

					this->_states.pop();
				}
				else {
					this->_states.top()->Pause();
				}
			}
				this->_states.push(move(this->_newState));
				this->_states.top()->Init();

				this->_isAdding = false;

				//this->_states.push(this->_newState);
				//this->_newState->Resume();
			
			
		}
	}


	StateRef & StateMachine::GetActiveState() {
		return this->_states.top();
	}
}