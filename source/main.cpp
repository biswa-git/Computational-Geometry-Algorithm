#include "sweep_line.h"
#include "bst.h"

int main()
{
	std::vector<cg::vertex*> vertexVec;
	std::vector<cg::edge*> edgeVec;

	//  SPECIFY THE LOCATION OF DATA FILE HERE
	std::string vertexFile = "../input/test.crd";
	{
		std::ifstream FileIn;
		FileIn.open(vertexFile, std::ios::in);
		assert (!FileIn.fail());
		while (!FileIn.eof())
		{
			double x[4];
			FileIn >> x[0] >> x[1] >> x[2] >> x[3];

			cg::vertex* start = cg::vertex::New(x[0], x[1]);
			cg::vertex* end = cg::vertex::New(x[2], x[3]);
			vertexVec.emplace_back(start);
			vertexVec.emplace_back(end);
			edgeVec.emplace_back(cg::edge::New(start,end));
		}
		FileIn.close();
	}

// SWEEP LINE ALGORITHM CALL
//---------------------------------------
	cg::sweep_line(edgeVec);           //
//---------------------------------------

	ClearVector<cg::edge*>(edgeVec);
	ClearVector<cg::vertex*>(vertexVec);
	return 0;
}