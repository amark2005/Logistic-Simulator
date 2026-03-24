#include <cmath>
#include <cstdio>
#include<vector>
#include<string>
using std::vector;
using std::string;

struct Edge{
  int to;
  float dist_km;
};
struct Node{
  string name;
  float lat,lon;
  vector<Edge> edges;
  Node(string n,float latE,float lonE){
    name=n;
    lat=latE;
    lon=lonE;

  }
};
int main(){
  vector<Node> graph = {
    {"Bengaluru",12.97f, 77.56f},
    {"Chennai",13.08f, 80.27f},
    {"Coimbatore",11.02f, 77.04f},
    {"Kochi",9.93f, 76.26f},
    {"Madurai",9.9252f, 78.1198f}
  };
  auto add=[&](int a,int b,float km){
    graph[a].edges.push_back({b,km});
    graph[b].edges.push_back({a,km});
  };
  add(0, 1, 345.f); //blr to chen
    add(0, 2, 340.f); //blr to cbe
    add(0, 3, 540.f); //blr to kochi
    add(1, 2, 500.f);  //chen to cbe
    add(2, 3, 200.f); //cbe to kochi
    add(1,4,465); //chen to mdu
    add(2,4,210); //cbe to mdu
    add(3,4,245); //koc to mdu

    for (auto& node : graph)
    for (auto& e : node.edges)
    printf("The distance between %s and %s is %.0f Km\n",node.name.c_str(),graph[e.to].name.c_str(),e.dist_km);
  return 0;

}