/*
 * Author: Yousif Jabbo
 * Class: CS635
 * Professor: Abbas Mazloumi
 */

#include <string>
#include <vector>

using namespace std;
#define ALPHABETSIZE 27
#define TERMINATOR 26
#define BADSTRINGERORRCODE -2
#define BADINPUTRORRCODE -3

//forward declaration for tree class
class Tree;

class TreeNode{
    friend Tree;
public:
    TreeNode * next[ALPHABETSIZE];
    TreeNode();
    ~TreeNode();
private:
    //comments for all the methods are in tree.cpp
    void InsertWord(std::string word);
    bool FindWord(string word);
    vector<string> FindSubstringMatches(string subString, string currentSubString, vector<string> *list, string currentWord= "");
    //helper functions
    static int ConvertCharToIndex(char character);
    static char ConvertIndexToChar(int index);
};

class Tree{

public:
    TreeNode * root;
    Tree();
    ~Tree();
    void InsertWord(string word);
    vector<string> FindSubStingMatches(string subString);
    bool FindWord(string word);

};



