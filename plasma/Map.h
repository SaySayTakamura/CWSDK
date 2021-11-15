#pragma once
#include <map>
#include <set>
#include "Node.h"

namespace plasma
{
	template <typename T>
	class Map
	{
	public:
		class Node {
		public:
			Node* left;
			Node* parent;
			Node* right;
			char color;
			char isnil;
			long long key;
			T* val;
		};

		class Result
		{
		public:
			Map::Node* node;
			bool is_new;
		};

		Map::Node* head;
		__int64 size;

		Map<T>::Result* FindOrCreateNode(plasma::Map<T>::Result* result, int key);
	};

	static_assert(sizeof(Map<plasma::Node>::Node) == 0x30, "Expected plasma::TreeNode to be of size 0x30");
	static_assert(sizeof(Map<plasma::Node>) == 0x10, "Expected plasma::NodeMap to be of size 0x10");
}