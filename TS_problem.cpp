#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

constexpr int INT_MAX = 9999;
constexpr int placesToGo = 4;

int TSP(int graph[][placesToGo], int p){
    std::vector<int> ver;
    int m_p = 0;

    for(int i=0; i<placesToGo; i++){
        if(i != p){
            ver.push_back(i);
            m_p = INT_MAX; 
            // store minimum weight of a graph
        }
    }
        do{
            int cur_pth = 0;
            int k = p;
            for(int i=0; i<ver.size(); i++){
                cur_pth += graph[k][ver[i]];
                k = ver[i];
            }
            cur_pth += graph[k][p];
            m_p = std::min(m_p, cur_pth);
            // update value of minimum weight
        } while(std::next_permutation(ver.begin(), ver.end()));
    return m_p;
}

int main(){
    std::string line("\n\t**********************************\n");

    int graph[][placesToGo] = {
        { 0, 5, 10, 15 },
        { 5, 0, 20, 30 },
        { 10, 20, 0, 35 },
        { 15, 30, 35, 0 }
    };

    int p = 0;
    std::cout << line << "\t     The result is: " << TSP(graph, p) << line << std::endl;

 return EXIT_SUCCESS;
}