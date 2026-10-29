
#include "GraphAlgorithms/TPrim.h"
#include "Utils/TGraphLoader.h"
#include "View/TGraphView.h"

int RunApp(int argc, char* argv[]) {
	TGraphLoader loader;
	loader.DataInit();

	TGraph<int>* graph = loader.GetGraph();

	TLinkedList<TEdge<int>*> mst;
	PrimMST(*graph, mst);

	TGraphView::PrintMST(mst);
	return 0;
}
