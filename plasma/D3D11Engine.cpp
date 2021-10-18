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