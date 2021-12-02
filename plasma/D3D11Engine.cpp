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

long long EncodeKey(std::string* key)
{
	long long base = 0x3FFFFFFFFFFE5;
	size_t size = key->size();
	if (size > 0)
	{
		size_t r10 = key->capacity();
		int i = 0;
		while (i < size)
		{
			base *= 31;
			base += key->at(i);
			i++;
		}
	}
	return base;
}



void InitKeyObject(BytesIO* obj, int flag, long long* key)
{
	((void (*)(BytesIO*, int, long long*))CWOffset(0xF9110))(obj, flag, key);
}



plasma::TextShape* plasma::D3D11Engine::CreateTextShape(std::wstring* str, std::wstring* name)
{
	return ((plasma::TextShape* (*)(plasma::D3D11Engine*, std::wstring*, std::wstring*))CWOffset(0x33DA70))(this, str, name);
}

plasma::TextShape* plasma::D3D11Engine::CreateTextShape()
{
	std::wstring wstr_empty = L"";
	return this->CreateTextShape(&wstr_empty, &wstr_empty);
}

bool plasma::D3D11Engine::LoadNodeFromFile(std::wstring* filename, plasma::Node* node, int a4, int a5)
{
	static std::string key("PlasmaXGraphics");
	BytesIO keyObj;

	long long encodedKey = EncodeKey(&key);
	InitKeyObject(&keyObj, 1, &encodedKey);
	return this->LoadNodeFromFile(filename, node, a4, a5, &keyObj);
}

bool plasma::D3D11Engine::LoadNodeFromFile(std::wstring* filename, plasma::Node* node, int a4, int a5, void* keyObj)
{
	return ((bool (*)(plasma::D3D11Engine*, std::wstring*, plasma::Node*, int, int, void*))CWOffset(0x3429A0))(this, filename, node, a4, a5, keyObj);
}

void* plasma::D3D11Engine::cw_33BCF0(void* a2, plasma::Object* object)
{
	return ((void* (*)(plasma::D3D11Engine*, void*, plasma::Object*))CWOffset(0x33BCF0))(this, a2, object);
}

void* plasma::D3D11Engine::cw_33BFE0(void* a2, plasma::Widget* widget)
{
	return ((void* (*)(plasma::D3D11Engine*, void*, plasma::Widget*))CWOffset(0x33BCF0))(this, a2, widget);
}
