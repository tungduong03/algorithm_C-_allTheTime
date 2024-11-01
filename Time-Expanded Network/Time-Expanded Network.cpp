#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

struct Edge {
    string id;
    string from;
    string to;
    string shape;
};

struct Junction {
    string id;
    string type;
    string shape;
};

vector<Edge> readEdges(const string& filename) {
    vector<Edge> edges;
    XMLDocument doc;
    doc.LoadFile(filename.c_str());
    XMLElement* root = doc.RootElement();

    for (XMLElement* element = root->FirstChildElement("edge"); element; element = element->NextSiblingElement("edge")) {
        Edge edge;
        edge.id = element->Attribute("id");
        edge.from = element->Attribute("from");
        edge.to = element->Attribute("to");

        XMLElement* laneElement = element->FirstChildElement("lane");
        while (laneElement) {
            const char* disallow = laneElement->Attribute("disallow");
            if (disallow && strcmp(disallow, "pedestrian") == 0) {
                edge.shape = laneElement->Attribute("shape");
                break;
            }
            laneElement = laneElement->NextSiblingElement("lane");
        }

        edges.push_back(edge);
    }

    return edges;
}

unordered_map<string, Junction> readJunctions(const string& filename) {
    unordered_map<string, Junction> junctions;
    XMLDocument doc;
    doc.LoadFile(filename.c_str());
    XMLElement* root = doc.RootElement();

    for (XMLElement* element = root->FirstChildElement("junction"); element; element = element->NextSiblingElement("junction")) {
        Junction junction;
        junction.id = element->Attribute("id");
        junction.type = element->Attribute("type");
        junction.shape = element->Attribute("shape");

        junctions[junction.id] = junction;
    }

    return junctions;
}

void printEdge(const Edge& edge) {
    cout << edge.id << "\t" << edge.from << "\t" << edge.to << "\t" << edge.shape << endl;
}

void printEdge2Juncs(const Edge& edge, const Junction& junction1, const Junction& junction2, const Junction& junction3) {
    cout << edge.id << "\t" << edge.shape << "\t" << junction1.id << "\t" << junction1.shape << "\t" << junction2.id << "\t" << junction2.shape << "\t" << junction3.id << "\t" << junction3.shape << endl;
}

void printStart(const Edge& edge) {
    cout << edge.id << "\t" << edge.from << "\t" << edge.to << "\t" << edge.shape << endl;
}

void splitStart(double x, const string& name) {
    size_t id = 0;
    size_t pos = 0;
    string shape = name.substr(name.find("\t") + 1);

    cout << name;
    while ((pos = shape.find(" ")) != string::npos) {
        string segment = shape.substr(0, pos);
        cout << "\t" << id << "_" << segment;
        shape.erase(0,pos+1);
        id++;
    }
    cout << "\t" << id << "_" << shape << endl;
}

int main() {
    string edgesFile = "vd013.net.xml";
    string junctionsFile = "vd013.net.xml";
    vector<Edge> edges = readEdges(edgesFile);
    unordered_map<string, Junction> junctions = readJunctions(junctionsFile);

    cout << "Edge ID\tFrom\tTo\tShape" << endl;
    for (const auto& edge : edges) {
    printEdge(edge);
}

    cout << endl << "Edge ID\tShape\tJunction 1 ID\tJunction 1 Shape\tJunction 2 ID\tJunction 2 Shape\tJunction 3 ID\tJunction 3 Shape" << endl;
    for (const auto& edge : edges) {
        Junction junction1, junction2, junction3;

        auto it1 = junctions.find(edge.from);
        if (it1 != junctions.end()) {
            junction1 = it1->second;
        }

        auto it2 = junctions.find(edge.to);
        if (it2 != junctions.end()) {
            junction2 = it2->second;
        }

        auto it3 = junctions.find(edge.to + "_1");
        if (it3 != junctions.end()) {
            junction3 = it3->second;
        }

        printEdge2Juncs(edge, junction1, junction2, junction3);
    }

    cout << endl << "Edge ID\tFrom\tTo\tShape" << endl;
    for (const auto& edge : edges) {
        printStart(edge);
    }

    cout << endl << "Split Start" << endl;
    for (const auto& edge : edges) {
        splitStart(0.0, edge.id + "\t" + edge.shape);
    }

    return 0;
}
