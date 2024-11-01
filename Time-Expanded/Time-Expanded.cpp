#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class Point {
public:
    double x, y;

    bool equals(Point* p) {
        return (this->x == p->x && this->y == p->y);
    }
};

class Shape {
public:
    Point* start;
    Point* end;
    double d;
    std::string name;

    bool equals(Shape* s) {
        return (this->start->equals(s->start) && this->end->equals(s->end));
    }
};

class TimeExpandedNode {
public:
    std::vector<std::pair<TimeExpandedNode*, Shape*>> srcs;
    Point* origin;
    double time;
    int layer;
    std::vector<std::pair<TimeExpandedNode*, Shape*>> tgts;

    void insertSource(Shape* s) {
        bool found = false;
        for (auto& pair : srcs) {
            if (pair.first && pair.first->origin->equals(s->start)) {
                found = true;
                break;
            }
        }
        if (!found) {
            srcs.push_back(std::make_pair(nullptr, s));
        }
    }

    void insertTarget(Shape* s) {
        bool found = false;
        for (auto& pair : tgts) {
            if (pair.first && pair.first->origin->equals(s->end)) {
                found = true;
                break;
            }
        }
        if (!found) {
            tgts.push_back(std::make_pair(nullptr, s));
        }
    }

    bool equals(TimeExpandedNode* n) {
        return this->origin->equals(n->origin);
    }

    void insertSourcesAndTargets(TimeExpandedNode* n, std::vector<std::pair<int, int>>& fromN,
                                 std::vector<std::pair<int, int>>& toN) {
        for (int i = 0; i < fromN.size(); i++) {
            int atN = fromN.at(i).first;
            int toThis = fromN.at(i).second;
            if (!this->srcs.at(toThis).first) {
                this->srcs.at(toThis).first = n;
            }
            if (!n->tgts.at(atN).first) {
                n->tgts.at(atN).first = this;
            }
        }

        for (int i = 0; i < toN.size(); i++) {
            int atThis = toN.at(i).first;
            int fromThis = toN.at(i).second;
            if (!this->tgts.at(atThis).first) {
                this->tgts.at(atThis).first = n;
            }
            if (!n->srcs.at(fromThis).first) {
                n->srcs.at(fromThis).first = this;
            }
        }
    }
};

std::string getName(const std::string& line) {
    std::stringstream ss(line);
    std::string name;
    ss >> name;
    return name;
}

int getIndex(const std::string& line) {
    std::stringstream ss(line);
    std::string name;
    int index;
    ss >> name >> index;
    return index;
}

Point* getPoint(const std::string& pointStr) {
    std::stringstream ss(pointStr);
    std::string xStr, yStr;
    std::getline(ss,xStr, ',');
std::getline(ss, yStr, ')');
double x = std::stod(xStr);
double y = std::stod(yStr);
Point* point = new Point();
point->x = x;
point->y = y;

return point;
}

Shape* getShape(const std::string& shapeStr) {
std::stringstream ss(shapeStr);
std::string startStr, endStr, dStr;
std::getline(ss, startStr, '-');
std::getline(ss, endStr, '-');
std::getline(ss, dStr);
Point* start = getPoint(startStr);
Point* end = getPoint(endStr);
double d = std::stod(dStr);

Shape* shape = new Shape();
shape->start = start;
shape->end = end;
shape->d = d;

return shape;
}

void parseInput(const std::string& inputFile, std::vector<Shape*>& shapes) {
std::ifstream file(inputFile);
std::string line;
while (std::getline(file, line)) {
    if (line.find("edge") != std::string::npos) {
        Shape* shape = getShape(line);
        shapes.push_back(shape);
    }
}

file.close();

}

void buildGraph(std::vector<Shape*>& shapes, std::vector<TimeExpandedNode*>& graph) {
for (Shape* shape : shapes) {
TimeExpandedNode* startNode = nullptr;
TimeExpandedNode* endNode = nullptr;
    for (TimeExpandedNode* node : graph) {
        if (node->origin->equals(shape->start)) {
            startNode = node;
        }
        if (node->origin->equals(shape->end)) {
            endNode = node;
        }
        if (startNode && endNode) {
            break;
        }
    }

    if (!startNode) {
        startNode = new TimeExpandedNode();
        startNode->origin = shape->start;
        graph.push_back(startNode);
    }
    if (!endNode) {
        endNode = new TimeExpandedNode();
        endNode->origin = shape->end;
        graph.push_back(endNode);
    }

    startNode->insertTarget(shape);
    endNode->insertSource(shape);
}
}

void findPaths(TimeExpandedNode* node, std::vector<TimeExpandedNode*>& graph, std::vector<Shape*>& path,
std::vector<std::vector<Shape*>>& paths) {
path.push_back(node->srcs.at(0).second);
if (node->layer == graph.size() - 1) {
    paths.push_back(path);
} else {
    for (auto& pair : node->tgts) {
        TimeExpandedNode* nextNode = pair.first;

        if (nextNode) {
            findPaths(nextNode, graph, path, paths);
        }
    }
}

path.pop_back();
}

void printPaths(std::vector<std::vector<Shape*>>& paths) {
for (const auto& path : paths) {
for (const auto& shape : path) {
std::cout << shape->name << " ";
}
std::cout << std::endl;
}
}

int main() {
std::vector<Shape*> shapes;
parseInput("AllParts.txt", shapes);
std::vector<TimeExpandedNode*> graph;
buildGraph(shapes, graph);

std::vector<std::vector<Shape*>> paths;
std::vector<Shape*> path;

findPaths(graph.at(0), graph, path, paths);

printPaths(paths);

// Clean up memory
for (Shape* shape : shapes) {
    delete shape;
}
for (TimeExpandedNode* node : graph) {
    delete node;
}

return 0;
}








