#include <iostream>
#include <set>
#include <map>


int RS(std::map<int,std::set<int>> grp, int index, int size, int *colors, std::map<int,std::set<int>> possible_colors) {
    if(index == size) return 1;
    while(possible_colors[index].size() > 0) {
        std::set<int>::iterator it = possible_colors[index].begin();
        colors[index] = *it;

        for(int u: grp[index]) possible_colors[u].erase(*it);

        int ret_val = RS(grp,index+1,size,colors,possible_colors);
        if(ret_val == 1) return 1;
        else {
            for(int u: grp[index]) possible_colors[u].insert(*it);
            possible_colors[index].erase(it);
            continue;
        }
    } return 0;
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

    std::map<int,std::set<int>> possible_colors;

    possible_colors[0] = std::set<int>({1,2,3});
    possible_colors[1] = std::set<int>({1,2,3});
    possible_colors[2] = std::set<int>({1,2,3});
    possible_colors[3] = std::set<int>({1,2,3});
    possible_colors[4] = std::set<int>({1,2,3});
    possible_colors[5] = std::set<int>({1,2,3});

    int colors[] = {0,0,0,0,0,0};

    RS(graph,0,6,colors,possible_colors);


    for(int i=0;i<6;i++) {
        std::cout << (char) (i + 65) << ":" << Colors[colors[i]] << std::endl;
    }

    std::cout << std::endl;

    return 0;
}