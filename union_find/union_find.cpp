#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#ifdef WUFPC
    #include "uf_weighted_path_compression.h"
#else
    #include "uf_weighted.h"
#endif

void process_file(std::string fname, int &N, std::vector<std::pair<int,int>> &connections) {

    std::ifstream infile(fname);
    int idx=0;
    while(!infile.eof()) {
        getline(infile,fname);
        std::cout << fname << std::endl;
        if (fname.empty()) continue;
        std::stringstream ss(fname);
        if (idx == 0) ss >> N;
        else {
           std::pair<int,int> ct;
           ss >> ct.first;
           ss >> ct.second;
           connections.push_back(ct); 
        }
        idx++;
    } 
    infile.close();
    //std::cout << "Size = " << N << std::endl;
    //for (auto i : connections) {
    //    std::cout << i.first << " , " << i.second << std::endl;
    //}
}



int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Expected input file" << std::endl;
        return 1;
    }
    std::string fname(argv[1]);
    int N;
    std::vector<std::pair<int,int>> connections;
    process_file(fname, N, connections);
    UF *uf = new UF(N);
    for (auto i : connections) {
        if (!uf->Connected(i.first, i.second)) {
            uf->Union(i.first, i.second);
        }
    }
    uf->printID(N);
    return 0;
}
