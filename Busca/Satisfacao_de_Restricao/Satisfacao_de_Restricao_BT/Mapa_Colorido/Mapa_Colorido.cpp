#include <iostream>
#include <set>
#include <map>


int RS(std::map<int,std::set<int>> grp, int index, int size, int *colors, int *possible_colors, int qnt) {
    if(index == size) return 1;
    int j = 0;
    while(j<qnt) {
        bool already = false;
        colors[index] = possible_colors[j++];
        for(int u: grp[index]) if(colors[u] == colors[index]) {
            already = true;
            break;
        } if(already) continue;

        int ret_val = RS(grp,index+1,size,colors,possible_colors,qnt);
        if(ret_val == 1) return 1;
        else if(ret_val == 0) continue;
    } 
    colors[index] = 0;
    return 0;
}

int main() {

    std::map<int,std::string> Colors;
    Colors[1] = "Vermelho";
    Colors[2] = "Azul";
    Colors[3] = "Roxo";

    std::map<int,std::set<int>> graph;
    graph[0] = std::set<int>({1,2,4});
    graph[1] = std::set<int>({0,4,5});
    graph[2] = std::set<int>({0,4,5});
    graph[3] = std::set<int>({5});
    graph[4] = std::set<int>({0,1,2,5});
    graph[5] = std::set<int>({1,2,3,4});

    int colors[] = {0,0,0,0,0,0};
    int possible_colors[] = {1,2,3};

    RS(graph,0,6,colors,possible_colors,3);


    for(int i=0;i<6;i++) {
        std::cout << (char) (i + 65) << ":" << Colors[colors[i]] << std::endl;
    }

    std::cout << std::endl;

    return 0;
}