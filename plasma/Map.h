#pragma once

#include <map>
#include <set>

namespace plasma
{
	class Node;

	template <typename...> class Map;
	template <typename T1, typename T2>

	class Map<T1, T2>
	{
	public:
		class Node {
		public:
			Node* left;
			Node* parent;
			Node* right;
			char color;
			char isnil;
			T1 key;
			T2 val;
		};

		class Result
		{
		public:
			Map::Node* node;
			bool is_new;
		};

		Map::Node* head;
		__int64 size;

		Map<T1, T2>::Result* FindOrCreateNode(plasma::Map<T1, T2>::Result* result, int key);
	};

	static_assert(sizeof(Map<long long, plasma::Node*>::Node) == 0x30, "Expected plasma::Map<long long, plasma::Node*>::Node to be of size 0x30");
	static_assert(sizeof(Map<long long, plasma::Node*>) == 0x10, "Expected plasma::Map<long long, plasma::Node*> to be of size 0x10");
}