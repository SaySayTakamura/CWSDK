#include "Map.h"
#include "cwsdk.h"

template<>
plasma::Map<long long, plasma::Node*>::Result* plasma::Map<long long, plasma::Node*>::FindOrCreateNode(plasma::Map<long long, plasma::Node*>::Result* result, int key)
{
	return ((plasma::Map<long long, plasma::Node*>::Result*(*)(void*, void*, int*))CWOffset(0xF7E50))(this, result, &key);
}