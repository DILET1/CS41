#include <bits/stdc++.h>

class Graph {
private:
    int numPoints;
    std::vector<std::vector<bool>> adjacencyMatrix;
    std::map<int, std::string> labelMap;

public:
    Graph(int n) : numPoints(n) {
        adjacencyMatrix.resize(n, std::vector<bool>(n, false));
    }

    void setLabel(int index, std::string label) {
        labelMap[index] = label;
    }

    void addEdge(std::string from, std::string to) {
        int fi = -1;
        int ti = -1;
        for(int i = 0; i < numPoints; i++){
        	if(labelMap[i] == from){
        		fi = i;
			}
			if(labelMap[i] == to){
				ti = i;
			}
		}

        adjacencyMatrix[fi][ti] = true;
    }

    void listEdges() {
        for (int i = 0; i < numPoints; ++i) {
            for (int j = 0; j < numPoints; ++j) {
                if (adjacencyMatrix[i][j]) {
                    std::cout << labelMap[i] << " - " << labelMap[j] << std::endl;
                }
            }
        }
    }
};

int main() {
    int numPoints;
    std::cout << "Enter the number of points: ";
    std::cin >> numPoints;

    Graph graph(numPoints);

    for (int i = 0; i < numPoints; ++i) {
        std::string label;
        std::cout << "Enter label for point " << i+1 << ": ";
        std::cin >> label;
        graph.setLabel(i, label);
    }
    std::cout<<"Define edges: ";
    std::string line;
    while(true){        
		std::getline(std::cin, line);
    	if(line == "-1"){
    		break;
		}
		if(line == ""){
			continue;
		}
		else{
			std::istringstream s(line);
        	std::string token1, token2;
        	s >> token1 >> token2;
        	graph.addEdge(token1,token2);
        	std::cout<<"Added"<<token1<<" -> "<<token2<<'\n';
		}
	}
    std::cout << "List of edges:" << std::endl;
    graph.listEdges();

    return 0;
}
