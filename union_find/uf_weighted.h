#pragma once

class UF {
    private:
        std::vector<int> id;
        std::vector<int> sz;
        int root(int i) {
            while(id[i] != i) { 
                i = id[i];
            }
            return i;
        }
    public: 
        UF(int N) {
            for (auto i=0; i<N; ++i) {
                id.push_back(i);
                sz.push_back(1);
            }
        }
        bool Connected(int p, int q) {
            return root(p) == root(q);
        }

        void Union(int p, int q) {
            int i = root(p);
            int j = root(q);
            if (i == j) return;
            if (sz[i] < sz[j]) {
                id[i] = j; sz[j] += sz[i];
            } else {
                id[j] = i; sz[i] += sz[j];
            }
        }

        void printID(int N) {
            for (auto i=0; i<N; ++i) {
                std::cout << i << " - " << id[i] << "," << sz[i] << std::endl;
            }
        }
};
