#include <iostream>  // std::cout
#include <algorithm> // std::lower_bound, std::upper_bound, std::sort
#include <vector>    // std::vector
#include <queue>    // std::priority_queue
#include <float.h>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    Node(Node* l, Node* r) : left(l), right(r){} 
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    Node* left;
    Node* right;
};

class VNode : public Node {
    public:
    VNode(int value) : Node(nullptr, nullptr), val(value){}
    int evaluate() const{
        return val;
    }
    protected:
    int val;
};

class Plus : public Node {
    public:
    Plus(Node* l, Node* r) : Node(l, r){}
    protected:
    int evaluate() const{
        return left->evaluate() + right->evaluate();
    }
};

class Minus : public Node {
    public:
    Minus(Node* l, Node* r) : Node(l, r){}
    protected:
    int evaluate() const{
        return right->evaluate() - left->evaluate();
    }
};
class Multiply : public Node {
    public:
    Multiply(Node* l, Node* r) : Node(l, r){}
    protected:
    int evaluate() const{
        return left->evaluate() * right->evaluate();
    }
};
class Divide : public Node {
    public:
    Divide(Node* l, Node* r) : Node(l, r){}
    protected:
    int evaluate() const{
        return right->evaluate() / left->evaluate();
    }
};
class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        if(postfix.size() == 0)
            return nullptr;
        string s  = postfix.back();
        postfix.pop_back();
        if(!isdigit(s[0])){
            auto left = buildTree(postfix);
            auto right = buildTree(postfix);
            if(s == "+"){
                return new Plus(left, right);
            }else if(s == "-"){
                return new Minus(left, right);
            }else if (s == "*")
            {
                return new Multiply(left, right);
            }else
            {
                return new Divide(left, right);
            }
        }else{
            return new VNode(stoi(s));
        }
    }
};

int main(){
    vector<string> v = {"3","4","+","2","*","7","/"};
    TreeBuilder tb;
    Node* node =  tb.buildTree(v);
    cout << node->evaluate() << endl;
    return 0;
}