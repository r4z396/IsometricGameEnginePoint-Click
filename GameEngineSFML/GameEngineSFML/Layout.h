#pragma once
#include "Widget.h"
namespace SoloStudios {
	class Layout : protected Widget
	{
	public:
		Layout(Widget* parent = nullptr);
		virtual ~Layout();

		void setSpace(float pixels);

	protected:
		friend class Container;
		float _space;
	};
}
