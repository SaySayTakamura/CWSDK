#include "Map.h"
#include "cwsdk.h"

template<>
plasma::Map<plasma::Node>::Result* plasma::Map<plasma::Node>::FindOrCreateNode(plasma::Map<plasma::Node>::Result* result, int key)
{
	return ((plasma::Map<plasma::Node>::Result*(*)(void*, void*, int*))CWOffset(0xF7E50))(this, result, &key);
}