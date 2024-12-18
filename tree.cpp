/*
 * Author: Yousif Jabbo
 */

#include "tree.h"
//default constructors
TreeNode::TreeNode() {
    for (int i = 0; i < ALPHABETSIZE; i++){
        next[i] = nullptr;
    }
}
Tree::Tree() {
    root = new TreeNode;
}
//destructors
TreeNode::~TreeNode() {
    // Delete child nodes recursively
    for (int i = 0; i < ALPHABETSIZE; i++) {
        if (next[i] != nullptr) {
            delete next[i];
        }
    }
}
Tree::~Tree() {
    // Delete the root TreeNode
    delete root;
}

/*
 * Function used to InsertWord words to the trie tree
 * @param word - a string to input
 * @Return void
*/
void TreeNode::InsertWord(std::string word) {
    //check if we reached the end of a word
    if(!word.empty()){
        char character = word.at(0);
        int charIndex = ConvertCharToIndex(character);
        //check if the character does not exist in the tree
        if (this->next[charIndex] == nullptr){
            // InsertWord the character to the tree and go to the next level in the tree
            this->next[charIndex] = new TreeNode;
        }
        //remove the inputted character from the word
        //and recursively call on the child
        this->next[charIndex]->InsertWord(word.substr(1));
    }else{
        //assign the index at the end to the word to TERMINATOR to indicate that this is the end of the word
        this->next[TERMINATOR] = new TreeNode;
    }
}

/*
 * Function used to search for a single word in the trie tree
 * @param word - a string to input
 * @Return bool true if the word exists false if it does not
*/
bool TreeNode::FindWord(string word) {
    //check if we reached the end of a word
    if(!word.empty()){
        char character = word.at(0);
        int charIndex = ConvertCharToIndex(character);
        //check if the character does not exist in the tree
        if (this->next[charIndex] == nullptr){
            return false;
        }
        return this->next[charIndex]->FindWord(word.substr(1));
    }else{
        //return true when we reach the end of the word
        if(this->next[TERMINATOR] != nullptr){
            return true;
        }
    }

    return false;
}


/*
 * Searches for substrings inside the trie tree
 *
 * @param subString - string to look for in the tree
 *        currentSubString - string to keep tract of while in the recursive call
 *        *list - a list to push words that match the substring
 *        currentWord - string create through the recursive call
 * @Return list - all words that match the substring
*/
vector<string> TreeNode::FindSubstringMatches(string subString, string currentSubString, vector<string> *list, string currentWord) {
    //string to keep track of the substring for children of the same leaf
    string tempSubString = currentSubString;
    //check all the children of the current tree node
    for (int i = 0; i < ALPHABETSIZE; ++i) {
        if(this->next[i]!= nullptr){
            //check what char is this and save the path that leads to it as a string
            currentWord.append(1, ConvertIndexToChar(i));
            //make sure that the substring is consecutive
            //mo should match lemon but not mango
            if(!currentSubString.empty() && ConvertIndexToChar(i) != currentSubString.at(0)){
                currentSubString = subString;
            }
            //if the current char in the substring matches removed it
            if(!currentSubString.empty() && ConvertIndexToChar(i) == currentSubString.at(0)){
                currentSubString = currentSubString.substr(1);
            }
            //when we reach the end of the word and substring was found InsertWord it to the list
            if(this->next[i]->next[TERMINATOR]!= nullptr && currentSubString.empty()){
                list->push_back(currentWord);
            }
            //recursively call FindSubstringMatches while it's not null
            this->next[i]->FindSubstringMatches(subString, currentSubString, list, currentWord);
            //throw away current last char when the substring is not found
            currentWord.pop_back();
            currentSubString=tempSubString;

        }
    }
    return *list;
}

/*
 * Remaps and convert character to index by using the ASCII Table value of a
 * capital and small letters will be assigned the same index
 * starting index for 'a' is 0 then 'b' is 1 ...
 * index 26 reserved for terminator character '\0'
 * @param character - a character to convert
 * @Return int - remapped value of the character
*/
int TreeNode::ConvertCharToIndex(char character) {
    //check if a character is an upper case then change it to lowercase
    // by using the value different between upper and lower case characters
    character = tolower(character);
    if(character < 'a' || character > 'z'){
        exit(BADSTRINGERORRCODE);
    }
    return character - 'a';
}
/*
 * convert index back to character  by using the ASCII Table value of a letters
 * starting index 0 is for 'a' then 1 for 'b' ...
 * index 26 reserved for terminator character '\0'
 * @param character - an index to convert
 * @Return char - remapped char of the Index
*/
char TreeNode::ConvertIndexToChar(int index) {
    if(index==TERMINATOR){
        return '\0';
    }
    return 'a' + index;
}

/*
 * Error checking before calling InsertWord word
 * to the tree.
 * @param string - word
 * @Return void
*/
void Tree::InsertWord(string word) {
    if (word.empty()){
        return;
    }
    root->InsertWord(word);
}

/*
 * Searches for substrings inside the trie tree
 *
 * @param string - word
 * @Return list - list of all words that contain the substring
*/
vector<string> Tree::FindSubStingMatches(string subString) {
    vector<string> list;
    root->FindSubstringMatches(subString, subString, &list);
    return list;
}
/*
 * FindWord if the word exists in the tree
 *
 * @param string - word
 * @Return bool - true if it exists
*/
bool Tree::FindWord(string word) {
    //ignore empty strings
    if (word.empty()){
        return false;
    }
    return root->FindWord(word);
}