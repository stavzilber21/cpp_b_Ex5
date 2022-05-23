#include "OrgChart.hpp"
#include <string>
using namespace std;
using namespace ariel;

OrgChart::OrgChart(){
    this->root= nullptr;
}
OrgChart::~OrgChart(){
    delete this->root;
}

OrgChart& OrgChart::add_root(string name){
    if(this->root==nullptr){
        this->root = new Node(name);
    }
    this->root->name=move(name);
    return *this;
}

OrgChart& OrgChart::add_sub(string name1, string name2){
    if(exist_dad(*this->root,name1,name2)){
        return *this;
    }
    else{
        throw invalid_argument("name1 not exit in the organization");
    }
}

bool OrgChart:: exist_dad(Node root, string &name1, string &name2){
    if(root.name.compare(name1)){
        Node *child;
        child->name=name2;
        root.node_childs.push_back(child);
        return true;
    } else{
        for (unsigned int i = 0; i < root.node_childs.size(); ++i) {
            if(exist_dad(*root.node_childs[i],name1,name2)){
                return true;
            }
        } 
    }
    return false;
}

ostream& ariel::operator<<(ostream& output, OrgChart &org){
    for (auto i = org.begin_level_order(); i != org.end_level_order(); i++)
    {
        output << (*i);
    }
    return output;
}

OrgChart::Iterator OrgChart::begin(){
    if(this->root == nullptr){
        throw std::invalid_argument("Empty tree");
    }
    return Iterator(this->root, 0);
}
OrgChart::Iterator OrgChart::end(){
    if(this->root == nullptr){
        throw std::invalid_argument("Empty tree");
    }
    return Iterator(nullptr, 0);
}


//void OrgChart::begin_level_help(Node *root){
//    vector<Node*>tree_level;
//    tree_level.push_back(root);
//    for (unsigned int i = 0; i < tree_level.size(); ++i) {
//        Node *temp = tree_level[i];
//        this->begin_level.push_back(temp->name);
//        for (unsigned int j = 0; j < temp->node_childs.size(); ++j) {
//            Node *temp_child = temp->node_childs[i];
//            tree_level.push_back(temp_child);
//        }
//    }
//}
//
//void OrgChart::begin_reverse_help(Node *root){
//    vector<Node*>tree_level;
//    tree_level.push_back(root);
//    for (unsigned int i = 0; i < tree_level.size(); ++i) {
//        Node *temp = tree_level[i];
//        unsigned int len = temp->node_childs.size();
//        for (unsigned int j = 0; j < len; ++j) {
//            tree_level.push_back(temp->node_childs[len-1-j]);
//        }
//    }
//
//    for (unsigned int i = 0; i < tree_level.size(); ++i) {
//        unsigned int len = tree_level.size();
//        string name_node = tree_level[len -i-1]->name;
//        this->reverse_level.push_back(name_node);
//    }
//
//}
//
//void OrgChart::preorder_help(Node *root){
//    this->beginPreorder.push_back(root->name);
//    for (unsigned int i = 0; i < root->node_childs.size(); ++i) {
//        preorder_help(root->node_childs[i]);
//    }
//}

OrgChart::Iterator OrgChart::begin_level_order(){
    if(this->root== nullptr){
        throw invalid_argument("the organization is empty");
    }
    return Iterator(this->root,"begin_level");
}


OrgChart::Iterator OrgChart::end_level_order(){
    if(this->root == nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(nullptr, "0");
}

OrgChart::Iterator OrgChart::begin_reverse_order(){
    if(this->root== nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(this->root,"begin_reverse");
}


OrgChart::Iterator OrgChart::begin_preorder(){
    if(this->root== nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(this->root,"begin_preorder");
}

OrgChart::Iterator OrgChart::end_preorder(){
    if(this->root == nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(nullptr, "0");
}
OrgChart::Iterator OrgChart::reverse_order(){
    if(this->root == nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(nullptr, "0");
}