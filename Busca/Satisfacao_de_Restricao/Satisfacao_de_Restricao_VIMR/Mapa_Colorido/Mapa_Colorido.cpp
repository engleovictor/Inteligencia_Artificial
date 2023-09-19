#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>


int RS(std::map<int,std::set<int>> grp, int index, std::vector<std::pair<int,int>> vimr, int *colors, std::map<int,std::set<int>> possible_colors) {
    if(index == vimr.size()) return 1;
    while(possible_colors[vimr[index].second].size() > 0) {
        std::set<int>::iterator it = possible_colors[vimr[index].second].begin();
        colors[vimr[index].second] = *it;

        for(int u: grp[vimr[index].second]) possible_colors[u].erase(*it);

        int ret_val = RS(grp,index+1,vimr,colors,possible_colors);
        if(ret_val == 1) return 1;
        else {
            for(int u: grp[vimr[index].second]) possible_colors[u].insert(*it);
            possible_colors[vimr[index].second].erase(it);
            continue;
        }
    } return 0;
}

bool cmp(std::pair<int,int> p1, std::pair<int,int> p2) {
    return p1.first > p2.first;
}

// bool cmp(std::pair<int,int> p1, std::pair<int,int> p2) {
//     return p1.first < p2.first;
// }

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

    std::vector<std::pair<int,int>> vimr;
    for(int i=0;i<graph.size();i++) {
        vimr.push_back(std::make_pair(graph[i].size(),i));
    }

    std::sort(vimr.begin(), vimr.end(), cmp);

    std::map<int,std::set<int>> possible_colors;

    possible_colors[0] = std::set<int>({1,2,3});
    possible_colors[1] = std::set<int>({1,2,3});
    possible_colors[2] = std::set<int>({1,2,3});
    possible_colors[3] = std::set<int>({1,2,3});
    possible_colors[4] = std::set<int>({1,2,3});
    possible_colors[5] = std::set<int>({1,2,3});

    int colors[] = {0,0,0,0,0,0};

    RS(graph,0,vimr,colors,possible_colors);

    for(int i=0;i<6;i++) {
        std::cout << (char) (i + 65) << ":" << Colors[colors[i]] << std::endl;
    }

    std::cout << std::endl;

    return 0;
}