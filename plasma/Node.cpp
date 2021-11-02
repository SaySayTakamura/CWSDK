#include "Node.h"
#include "../cwsdk.h"

// Only called once in GUI init, but here for documentation purposes
plasma::Node* plasma::Node::ctor(plasma::D3D11Engine* engine, plasma::Transformation* transformation, std::list<plasma::Node*>* nodes, plasma::Display* display, std::wstring* name)
{
	return ((plasma::Node * (*)(plasma::Node*, plasma::D3D11Engine*, plasma::Transformation*, std::list<plasma::Node*>*, plasma::Display*, std::wstring*))CWOffset(0x32EE60))(this, engine, transformation, nodes, display, name);
}

plasma::Node* plasma::Node::CreateAndAddNodeMaybe(plasma::Node* root_node)
{
	return ((plasma::Node* (*)(plasma::Node*, plasma::Node*))CWOffset(0x3308E0))(this, root_node);
}

void plasma::Node::Translate(FloatVector2* base, FloatVector2* offset) {
	((void(*)(plasma::Node*, FloatVector2*, FloatVector2*))CWOffset(0x334510))(this, base, offset);
}
void plasma::Node::Translate(float baseX, float baseY, float offsetX, float offsetY) {
	FloatVector2 base(baseX, baseY);
	FloatVector2 offset(offsetX, offsetY);
	this->Translate(&base, &offset);
}
plasma::Node* plasma::Node::Draw(u32 flags) {
	return ((plasma::Node* (*)(plasma::Node*, u32))CWOffset(0x330B20))(this, flags);
}

bool plasma::Node::IsVisible()
{
	return this->display->IsVisible();
}

void plasma::Node::SetVisibility(bool visible)
{
	this->display->SetVisibility(visible);
}

plasma::Node* plasma::Node::GetHoveredNode(FloatVector2* mouse_pos, u32 flags)
{
	return ((plasma::Node* (*)(plasma::Node*, FloatVector2*, u32))CWOffset(0x333F60))(this, mouse_pos, flags);
}

bool plasma::Node::IsMouseOverNode()
{
	return this->GetHoveredNode(&this->d3d11_engine->mouse_position, 0) != nullptr;
}

void plasma::Node::LoadSomeMatrix(Matrix4* matrix)
{
	((void (*)(plasma::Node*, Matrix4*))CWOffset(0x100EE0))(this, matrix);
}

plasma::Node* plasma::Node::FindChildByName(std::wstring* name)
{
	return ((plasma::Node* (*)(plasma::Node*, std::wstring*))CWOffset(0x332190))(this, name);
}

void plasma::Node::FindByNameAndSetString(std::wstring* name, std::string* str, int flags)
{
	((void (*)(plasma::Node*, std::wstring*, std::string*, int flags))CWOffset(0xA3940))(this, name, str, flags);
}

void plasma::Node::FindByNameAndSetString(std::wstring* name, std::wstring* str, int flags)
{
	((void (*)(plasma::Node*, std::wstring*, std::wstring*, int flags))CWOffset(0x3348E0))(this, name, str, flags);
}

plasma::Node* plasma::Node::CreateCopy(plasma::Node* parent)
{
	return ((plasma::Node* (*)(plasma::Node*, plasma::Node*))CWOffset(0x333890))(this, parent);
}

void plasma::Node::ClearChildrenMaybe()
{
	((void (*)(plasma::Node*))CWOffset(0x330A80))(this);
}

void plasma::Node::SetTransformation(plasma::Transformation* transformation)
{
	((void (*)(plasma::Node*, plasma::Transformation*))CWOffset(0x334D30))(this, transformation);
}

void plasma::Node::SetDisplay(plasma::Display* display)
{	
	((void (*)(plasma::Node*, plasma::Display*))CWOffset(0x334760))(this, display);
}
