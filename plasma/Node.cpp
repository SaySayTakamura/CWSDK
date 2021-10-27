#include "Node.h"
#include "../cwsdk.h"

void plasma::Node::Translate(plasma::Vector<2, float>* base, plasma::Vector<2, float>* offset) {
	((void(*)(plasma::Node*, plasma::Vector<2, float>*, plasma::Vector<2, float>*))CWOffset(0x334510))(this, base, offset);
}
void plasma::Node::Translate(float baseX, float baseY, float offsetX, float offsetY) {
	plasma::Vector<2, float> base;
	plasma::Vector<2, float> offset;
	base.Set(0, baseX);
	base.Set(1, baseY);
	offset.Set(0, offsetX);
	offset.Set(1, offsetY);
	this->Translate(&base, &offset);
}
i32 plasma::Node::Draw(u32 flags) {
	return ((i32(*)(plasma::Node*, u32))CWOffset(0x330B20))(this, flags);
}

void plasma::Node::MaybeLoadTransformationMatrix(Matrix4* matrix)
{
	((void (*)(plasma::Node*, Matrix4*))CWOffset(0x100EE0))(this, matrix);
}

plasma::Node* plasma::Node::FindChildNodeByName(std::wstring* name)
{
	return ((plasma::Node* (*)(plasma::Node*, std::wstring*))CWOffset(0x332190))(this, name);
}

plasma::Node* plasma::Node::CopyMaybe(plasma::Node* node)
{
	return ((plasma::Node* (*)(plasma::Node*, plasma::Node*))CWOffset(0x333890))(this, node);
}

void plasma::Node::SetTransformation(plasma::Transformation* transformation)
{
	((void (*)(plasma::Node*, plasma::Transformation*))CWOffset(0x334D30))(this, transformation);
}

void plasma::Node::SetDisplay(plasma::Display* display)
{	
	((void (*)(plasma::Node*, plasma::Display*))CWOffset(0x334760))(this, display);
}
