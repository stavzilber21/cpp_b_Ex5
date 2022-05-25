#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
namespace ariel{
    class OrgChart{
    private:
        class Node{
        public:
            string name;
            vector<Node*>node_childs;

            Node(const string &name) {
                this->name = name;
            }
        };
        class Iterator{

        private:
            Node *node;
            vector<Node*>node_list;

        public:

            Iterator(Node *root = nullptr, const string &id_function =""){
                if(root!= nullptr){
                    if(id_function=="begin_level"){
                        begin_level_help(root);
                    }
                    else if(id_function=="begin_reverse"){
                        begin_reverse_help(root);
                    }
                    else if(id_function=="begin_preorder"){
                        preorder_help(root);
                    }
                    this->node = node_list.at(0);
                    node_list.erase(node_list.begin());
                }

                else{
                    this->node= nullptr;
                }

            }
            void begin_level_help(Node* root);
            void begin_reverse_help(Node* root);
            void preorder_help(Node* root);


            bool operator!=(const Iterator& iter) const{
                return this->node != iter.node;
            }
            bool operator==(const Iterator& iter) const{
                return this->node == iter.node;
            }
            Iterator operator++(int){
                Iterator t = *this;
                return t;
            }
            Iterator& operator++(){
                if (!node_list.empty()) {
                    this->node = node_list.at(0);
                    node_list.erase(node_list.begin());
                }
                else {
                    this->node = nullptr;
                }
                return *this;
            }
            string operator*() const{
                return (*this->node).name;
            }
            string* operator->() const{
                return &node->name;;
            }

        };


    public:
        Node *root;

        OrgChart();
        ~OrgChart();
        OrgChart &operator=(OrgChart const &other) = default;
        OrgChart &operator=(OrgChart &&other) = default;
        OrgChart(OrgChart&) = default;
        OrgChart(OrgChart&&) = default;

        OrgChart& add_root(const string &name);
        OrgChart& add_sub( const string &name1,const  string &name2);
        friend ostream& operator<<(ostream& output,OrgChart &org);
        bool exist_dad(Node *root, const string &name1,const  string &name2);
        void delete_node(Node *root);
        Iterator begin()const;
        Iterator end()const;
        Iterator begin_level_order()const;
        Iterator end_level_order()const;
        Iterator begin_reverse_order()const;
        Iterator reverse_order()const;
        Iterator begin_preorder()const;
        Iterator end_preorder()const;
    };

}