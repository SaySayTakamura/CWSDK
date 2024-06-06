#pragma once
#include "cwsdk.h"

// Nichiren (thetrueoneshot) is the one behind the original ModWidget code, all the research behind it is from him.
namespace modhelper {
	class ModBaseWidget : public cube::BaseWidget {
	private:
		void* artificial_vtable[43];
	public:
		void Init(cube::Game* game, plasma::Node* node, void* draw_func);
	};
}