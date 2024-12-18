/*
 * Author: Yousif Jabbo
 */

#include <iostream>
#include <limits>
#include "tree.h"

void FruitTest();
void ManualTest();
void NamesTest();
int ReadIntegerInput();

using namespace std;

int main() {

    int testType;
    //this is manually changed to enter test mode
    bool test_mode = true;
    if (test_mode) {
        //let user chose what test to run
        do {
            cout << "Enter 1 for manual test, 2 for fruits test, 3 for names test\n";
            testType = ReadIntegerInput();
            if (testType < 0 || testType > 3) {
                cout << "\nInvalid input try again.\n";
            }
            //run the test
            if (testType == 1) {
                ManualTest();
            } else if (testType==2) {
                FruitTest();
            }else if (testType==3){
                NamesTest();
            }
        } while (testType != -1);

    }

    return 0;
}
/*
 * let user input words build the tree
 * and look for substring in them
 * @param None
 * @Return void
*/
void ManualTest(){
    // create an object of tree class
    auto tree = new Tree();
    vector<string> words;
    bool exitStatus= true;
    int mode;
    string input;
    printf("You are now in manual mode enter -1 anytime to exit");
    while(exitStatus){
        printf("\nEnter 1 for adding words, 2 for find words, 3 to find strings that have matching substring, -1 to return to the main\n");
        mode = ReadIntegerInput();
        switch (mode) {
            case 1:
                input="";
                while (input!="-1"){
                    cout<<"Type Words to insert or -1 to exist\n";
                    cin>>input;
                    if(input=="-1") break;
                    tree->InsertWord(input);
                }
                printf("\n Done adding words\n");
                break;
            case 2:
                input="";
                while (input!="-1"){
                    cout<<"Type a word to find or -1 to exist\n";
                    cin>>input;
                    if(input=="-1") break;
                    if(tree->FindWord(input)){
                        cout<<input<<" Exists in the tree\n";
                    }else{
                        cout<<input<<" Does not exists in the tree\n";
                    }
                }
                printf("\n Done searching for words\n");
                break;
            case 3:
                input="";
                while (input!="-1"){
                    cout<<"Type substring to find or -1 to exist\n";
                    cin>>input;
                    if(input=="-1") break;
                    vector<string> list = tree->FindSubStingMatches(input);
                    cout<<"Number of words containing the substrings: "<<list.size()<<endl;
                    for (const auto & i : list) {
                        cout<<i<<endl;
                    }
                    cout<<endl;
                }
                printf("\n Done searching for sub string for words\n");
                break;
            case -1:
                exitStatus= false;
                break;
            default:
                printf("Invalid input exiting");
                exit(BADINPUTRORRCODE);
        }

    }
}
/*
 * pre-made list of fruits used for testing
 * lets user input the substring to lookup
 * @param None
 * @Return void
*/
void FruitTest() {
    // create an object of tree class
    auto tree = new Tree();
    //root->next[0]= new TreeNode;
    vector<string> fruits = {
            "Apple", "Ackee", "Cherry", "Orange", "Grape",
            "Pineapple", "Mango", "Strawberry", "Peach", "Watermelon",
            "Kiwi", "Lemon", "Blueberry", "Raspberry", "Blackberry",
            "Pear", "Plum", "Cranberry", "Coconut", "Pomegranate",
            "Apricot", "Fig", "Grapefruit", "Lime", "Guava",
            "Tangerine", "Papaya", "Cantaloupe", "Dragonfruit", "Passionfruit",
            "Avocado", "Litchi", "Nectarine", "Mulberry", "Currant",
            "Quince", "Kumquat", "Lychee", "Starfruit", "Persimmon",
            "Elderberry", "Gooseberry", "Date", "Tamarind", "Plantain",
            "Boysenberry", "Rhubarb", "Loganberry", "Soursop", "Feijoa",
            "Jujube", "Sapodilla", "Salak", "Honeydew", "Carambola",
            "Ackee", "Pawpaw", "Pitanga", "Durian", "Mangosteen",
            "Saskatoonberry", "Aronia", "Loquat", "Rambutan", "Guignaberry",
            "Breadfruit", "Chayote", "Jackfruit", "Tangelo", "Uglifruit",
            "Wampee", "Yuzu", "Zucchini", "Tomato", "Cucumber"
    };
    //test the InsertWord function
    for (const auto & word : fruits) {
        tree->InsertWord(word);
    }

    string substring;
    cout<<"Input substring to search in fruits strings: "<<endl;
    cin>>substring;
    vector<string> list = tree->FindSubStingMatches(substring);
    cout<<"Number of fruits containing the substrings : "<<list.size()<<endl;
    for (const auto & i : list) {
        cout<<i<<endl;
    }
    cout<<endl;
}
/*
 * pre-made list of names used for testing
 * lets user input the substring to lookup
 * @param None
 * @Return void
*/
void NamesTest() {
    // create an object of tree class
    auto tree = new Tree();
    //root->next[0]= new TreeNode;
    std::vector<std::string> names = {
            "John", "Alice", "Bob", "Emma", "Michael",
            "Sophia", "William", "Olivia", "James", "Emily",
            "Liam", "Ava", "Benjamin", "Isabella", "Henry",
            "Charlotte", "Alexander", "Mia", "Daniel", "Ella",
            "Elijah", "Madison", "Matthew", "Grace", "David",
            "Scarlett", "Joseph", "Chloe", "Samuel", "Lily",
            "Christopher", "Abigail", "Andrew", "Sophie", "Ethan",
            "Zoe", "Joshua", "Aria", "William", "Nora",
            "Gabriel", "Hannah", "Nicholas", "Amelia", "Jackson",
            "Avery", "Caleb", "Evelyn", "Daniel", "Layla",
            "Anthony", "Victoria", "Ryan", "Lillian", "Thomas",
            "Aubrey", "Nathan", "Zoe", "Christian", "Haley"
    };
    //test the InsertWord function
    for (const auto & name : names) {
        tree->InsertWord(name);
    }

    string substring;
    cout<<"Input substring to search in names strings: "<<endl;
    cin>>substring;
    //FindSubstringMatches and print all substrings
    vector<string> list = tree->FindSubStingMatches(substring);
    cout<<"Number of words containing the substrings: "<<list.size()<<endl;
    for (const auto & i : list) {
        cout<<i<<endl;
    }
    cout<<endl;
}
/* Function that takes user input and
 * checks for errors
 *
 * @param None
 * @Return void
*/
int ReadIntegerInput() {
    int UserInput;
    while (true) {
        if (cin >> UserInput) {
            // Input was a valid integer
            break;
        } else {
            // Input was not an integer
            cin.clear();
            // Ignore the rest of the line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << std::endl;
        }
    }
    return UserInput;
}
