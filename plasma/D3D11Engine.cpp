#include "D3D11Engine.h"
#include "cwsdk.h"

void plasma::D3D11Engine::MiddleMouseButtonUp()
{
	((void(*)(plasma::D3D11Engine*))CWOffset(0x3414A0))(this);
}

void plasma::D3D11Engine::LeftMouseButtonUp()
{
	((void(*)(plasma::D3D11Engine*))CWOffset(0x3410E0))(this);
}

void plasma::D3D11Engine::RightMouseButtonUp()
{
	((void(*)(plasma::D3D11Engine*))CWOffset(0x341780))(this);
}

plasma::Node* plasma::D3D11Engine::CreateNode(plasma::Transformation* transformation, plasma::TextShape* text_shape, plasma::Display* display, plasma::Node* root_node, std::wstring* name)
{
	return ((plasma::Node* (*)(plasma::D3D11Engine*, plasma::Transformation*, plasma::TextShape*, plasma::Display*, plasma::Node*, std::wstring*))CWOffset(0x33CD30))(this, transformation, text_shape, display, root_node, name);
}

plasma::Node* plasma::D3D11Engine::CreateNode(plasma::Node* root_node, std::wstring* name)
{
	return this->CreateNode(nullptr, nullptr, nullptr, root_node, name);
}

bool plasma::D3D11Engine::LoadNodeFromFile(std::wstring* filename, plasma::Node* node, int a4, int a5, void* some_struct)
{
	return ((bool (*)(plasma::D3D11Engine*, std::wstring*, plasma::Node*, int, int, void*))CWOffset(0x3429A0))(this, filename, node, a4, a5, some_struct);
}
