#pragma once
#include "essential.h"
#include "face.h"

namespace cg
{
	class face_node
	{
	public:
		static face_node* New(face*);
		~face_node() = default;
		void PushChild(face_node*);
		void CreateChild(vertex*);
	private:
		face_node(face*);
		bool isActive;
		face* data;
		std::list<face_node*> childList;
		std::list<vertex*> faceVertList;
	};
}