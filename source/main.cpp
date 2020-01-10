#include "sweep_line.h"
#include "bst.h"

int main()
{
	//std::vector<cg::vertex*> vertexVec; //TO KEEP TRACK OF VERTEX MEMORY, SO THAT WE CAN DELETE IT. 
	std::vector<cg::edge*> edgeVec;

	//  SPECIFY THE LOCATION OF DATA FILE HERE
	std::string vertexFile = "../input/test.crd";

	//READING DATA FROM INPUT FILE (FORMAT OF LINE  --->      START_X    START_Y    END_X    END_Y)
	{
		std::ifstream FileIn;
		FileIn.open(vertexFile, std::ios::in);
		assert (!FileIn.fail());

		double x[4];
		while (!FileIn.eof())
		{
			FileIn >> x[0] >> x[1] >> x[2] >> x[3];

			cg::vertex* start = cg::vertex::New(x[0], x[1]);
			cg::vertex* end   = cg::vertex::New(x[2], x[3]);
			edgeVec.emplace_back(cg::edge::New(start,end));
		}
		FileIn.close();
	}
	//AT THIS POINT WE'VE STORED THE POINTER OF ALL EDGES IN A STL VECTOR

// SWEEP LINE ALGORITHM CALL
//-----------------------------------------------------------------------

	cg::sweep_line(edgeVec);

//-----------------------------------------------------------------------

	//MEMORY CLEAN UP
	for (auto it = edgeVec.begin(); it != edgeVec.end(); it++)
	{
		auto vertStart = (*it)->GetStart();
		auto vertEnd = (*it)->GetEnd();
		FREE_OBJ_MACRO(vertStart);
		FREE_OBJ_MACRO(vertEnd);
		FREE_OBJ_MACRO(*it);
	}

	return 0;
}