#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
namespace ariel{
    class OrgChart : public error_code {
    private:
        struct Node{
            int level;
            string name;
            Node *parentNode;
            vector<Node*>node_childs;

            Node(const string &name) {
                this->name = name;
            }
        };
        class Iterator{

        private:
            int i;
            Node *node;
            vector<string> node_list;
        public:

            Iterator(Node *root, string id_function){
                if(id_function.compare("begin_level")){
                    begin_level_help(root);
                }
                if(id_function.compare("begin_reverse")){
                    begin_reverse_help(root);
                }
                if(id_function.compare("begin_preorder")){
                    preorder_help(root);
                }
            }

            void begin_level_help(Node *root){
                vector<Node*>tree_level;
                tree_level.push_back(root);
                for (unsigned int i = 0; i < tree_level.size(); ++i) {
                    Node *temp = tree_level[i];
                    this->node_list.push_back(temp->name);
                    for (unsigned int j = 0; j < temp->node_childs.size(); ++j) {
                        Node *temp_child = temp->node_childs[i];
                        tree_level.push_back(temp_child);
                    }
                }
            }

            void begin_reverse_help(Node *root){
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
                    string name_node = tree_level[len -i-1]->name;
                    this->node_list.push_back(name_node);
                }

            }

            void preorder_help(Node *root){
                this->node_list.push_back(root->name);
                for (unsigned int i = 0; i < root->node_childs.size(); ++i) {
                    preorder_help(root->node_childs[i]);
                }
            }

            bool operator!=(const Iterator& it) const{
                return false;
            }
            const Iterator operator++(int){
                Iterator t = *this;
                return t;
            }
            Iterator& operator++(){
                return *this;
            }
            string operator*() const{
                return "";
            }
            string* operator->() const{
                return nullptr;
            }

        };
        Node *root;
        int max_level;
    public:
        vector<string>begin_level;
        vector<string>reverse_level;
        vector<string>beginPreorder;
        OrgChart();
        ~OrgChart();

        OrgChart& add_root(string name);
        OrgChart& add_sub(string name1, string name2);
        friend ostream& operator<<(ostream& output, OrgChart &org);
        bool exist_dad(Node root, string &name1, string &name2);
        void begin_level_help(Node *root);
        void begin_reverse_help(Node *root);
        void preorder_help(Node *root);
        Iterator begin();
        Iterator end();
        Iterator begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();
    };

}