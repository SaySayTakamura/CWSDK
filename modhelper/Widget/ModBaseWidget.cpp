#include "ModBaseWidget.h"

void modhelper::ModBaseWidget::Init(cube::Game* game, plasma::Node* node, void* draw_func)
{
	void* NULLSUB = CWOffset(0xE8A20);
	void* RETZERO = CWOffset(0x368230);

	void* vtab[43] = {
	CWOffset(0x268B40),
	draw_func,				// void Draw(plasma::Widget*)
	CWOffset(0x26A720),
	CWOffset(0x26A720),
	RETZERO,
	RETZERO,
	NULLSUB,
	CWOffset(0x32B830),
	CWOffset(0x32BFD0),
	CWOffset(0x32BD70),
	NULLSUB,
	CWOffset(0x32B990),
	CWOffset(0x32BB40),
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	CWOffset(0x32BB80),		// void OnMouseOver(plasma::Widget*)
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	CWOffset(0x32B5A0),
	CWOffset(0x32B6B0),
	NULLSUB,
	NULLSUB,
	CWOffset(0x32B6E0),
	CWOffset(0x32A2C0),		// plasma::Widget* CreateCopy(plasma::Widget*);
	CWOffset(0x32A8D0),
	NULLSUB
	};

	std::wstring wstr_empty(L"");
	((cube::BaseWidget*)this)->ctor(game->plasma_engine, node, &wstr_empty);
	for (int i = 0; i < 43; ++i)
	{
		this->artificial_vtable[i] = vtab[i];
	}
	size_t* vptr = (size_t*)this;
	*vptr = (size_t)this->artificial_vtable;

	// Create deep copy of the cursor node
	plasma::Node* cursor_node = game->gui.cursor_node->CreateDeepCopy(game->plasma_engine->root_node);

	// Hide the old cursor node
	game->gui.cursor_node->SetVisibility(false);

	// Set the new cursor node
	game->gui.cursor_node = cursor_node;
}