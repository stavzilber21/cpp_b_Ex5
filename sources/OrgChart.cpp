#include "OrgChart.hpp"
#include <string>
using namespace std;
using namespace ariel;

OrgChart::OrgChart(){
    this->root= nullptr;
}
OrgChart::~OrgChart(){
    (*this).delete_node(this->root);
}

OrgChart& OrgChart::add_root(const string &name){
    if (name.empty()) {
        throw invalid_argument("the name is empty");
    }
    if(this->root==nullptr){
        this->root = new Node(name);
    }
    else{
        this->root->name=name;
    }
    return *this;
}

OrgChart& OrgChart::add_sub( const string &name1,const  string &name2){
    if (name1.empty() || name2.empty()) {
        throw invalid_argument("the name is empty");
    }
    if (this->root == nullptr) {
        throw invalid_argument("no exist root in the tree");
    }
    if(exist_dad(this->root,name1,name2)){
        return *this;
    }

    throw invalid_argument("name1 not exit in the organization");

}

bool OrgChart:: exist_dad(Node *root, const string &name1,const  string &name2){
    if(root->name==name1){
        Node* child= new Node(name2);
        (*root).node_childs.push_back(child);
        return true;
    }
    for (unsigned int i = 0; i < root->node_childs.size(); ++i) {
        if(exist_dad(root->node_childs[i],name1,name2)){
            return true;
        }
    }

    return false;
}

ostream& ariel::operator<<(ostream& output,OrgChart &org){
    return output;
}


OrgChart::Iterator OrgChart::begin()const{
    return begin_level_order();
}

OrgChart::Iterator OrgChart::end()const{
    return end_level_order();
}


void OrgChart::Iterator::begin_level_help(Node *root){
    vector<Node*>tree_level;
    tree_level.push_back(root);
    while(!tree_level.empty()) {
        Node* temp = tree_level[0];
        this->node_list.push_back(temp);
        for (unsigned int i = 0; i < temp->node_childs.size(); i++) {
            tree_level.push_back(temp->node_childs.at(i));
        }
        tree_level.erase(tree_level.begin());
    }
}


void OrgChart::Iterator::begin_reverse_help(Node *root){
    vector<Node*>tree_level;
    tree_level.push_back(root);
    for (unsigned int i = 0; i < tree_level.size(); ++i) {
        Node *temp = tree_level[i];
        unsigned int len = temp->node_childs.size();
        for (unsigned int j = 0; j < len; ++j) {
            tree_level.push_back(temp->node_childs[len-1-j]);
        }
    }

    for (unsigned int i = 0; i < tree_level.size(); ++i) {
        unsigned int len = tree_level.size();
        this->node_list.push_back(tree_level[len -i-1]);
    }

}

void OrgChart::Iterator::preorder_help(Node *root){
    this->node_list.push_back(root);
    for (unsigned int i = 0; i < root->node_childs.size(); ++i) {
        preorder_help(root->node_childs[i]);
    }
}

void OrgChart::delete_node(Node *root) {
    if (this->root==nullptr) {
        return;
    }
    if (!root->node_childs.empty()) {
        for (unsigned int i = 0; i < root->node_childs.size(); i++) {
            delete_node(root->node_childs[i]);
        }
    }
    delete root;
}

OrgChart::Iterator OrgChart::begin_level_order() const{
    if(this->root== nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(this->root,"begin_level");
}


OrgChart::Iterator OrgChart::end_level_order()const{
    if(this->root == nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(nullptr, "");
}

OrgChart::Iterator OrgChart::begin_reverse_order()const{
    if(this->root== nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(this->root,"begin_reverse");
}


OrgChart::Iterator OrgChart::begin_preorder()const{
    if(this->root== nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(this->root,"begin_preorder");
}

OrgChart::Iterator OrgChart::end_preorder()const{
    if(this->root == nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(nullptr, "");
}

OrgChart::Iterator OrgChart::reverse_order()const{
    if(this->root == nullptr){
        throw invalid_argument("the tree is empty");
    }
    return Iterator(nullptr, "");
}

