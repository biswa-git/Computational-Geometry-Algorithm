#pragma once
#include "essential.h"
#include "face.h"

namespace cg
{
	class face;
	class face_node
	{
	public:
		static face_node* New(face*);
		~face_node() = default;
		static size_t GetCount();
		static void SetCount(size_t);
		void PushChild(face_node*);
		void CreateChild(vertex*);
		void ActiveFlag(bool);
		std::list<face_node*>& GetChildList();
		void PrintNode(std::ofstream&);
		void ResetIsVisitedStat();
	private:
		face_node(face*);
		static size_t count;
		bool isActive;
		bool isVisited;
		face* data;
		std::list<face_node*> childList;
		std::list<vertex*> faceVertList;
	};
}