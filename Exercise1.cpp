//
//  Exercise1.cpp
//  GameProgrammingC++
//
//  Created by FastTrackCoder on 6/21/22.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    vector<string> games;
    vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;
    
    string selection = "";
    string input = "";
    
    
    // main loop
    // This will stay looping until the user decides to quit
    // the program
    while (selection != "4" && selection != "QUIT")
    {
        cout << "\nPlease select an option from below, you can type in the"
        << " keyword next to it as well as the number itself to select:\n-------------\n";
        cout << "1. View Your Game List (VIEW)" << endl;
        cout << "2. Add A Game To The List (ADD)" << endl;
        cout << "3. Remove A Game From The List (REMOVE)" << endl;
        cout << "4. Quit Program (QUIT)" << endl << "Enter here: ";
        getline(cin, selection);
        
        
        // Uppercase the selection
        for (int i = 0; i < selection.size(); i++)
        {
            selection[i] = toupper(selection[i]);
        }
        
        if (selection[0] == '1' || selection == "VIEW")
        {
            cout << "\nHere is the list of your favorite games: \n";
            
            for (iter = games.begin(); iter != games.end(); iter++)
            {
                cout << *iter << endl;
            }
        }
        else if (selection[0] == '2' || selection == "ADD")
        {
            cout << "\nType in the game you would like to add to your list of games:\nEnter here: ";
            getline(cin, input);
            games.push_back(input);
            
        }
        else if (selection[0] == '3' || selection == "REMOVE")
        {
            cout << "\nHere's the list of your favorite games: \n";
            
            for (iter = games.begin(); iter != games.end(); iter++)
            {
                cout << *iter << endl;
            }
            
            cout << "\nPlease enter the name of the game you want to remove: \nEnter here: ";
            getline(cin, input);
            
            // Trying to find the iterator of a selected and making sure its in the vector list
            while (find(games.begin(), games.end(), input) == games.end() && input != "0")
            {
                cout << "\nWe couldn't find " << input << " in your games list. "
                << "Make sure to be case-sensitive in your input.\n";
                cout << "Please enter 0 if you wish to go back to the menu or "
                << "enter a game to remove:\nEnter here: ";
                getline(cin, input);
            }
            // If input is 0, cancel removal and go back to menu
            if (input == "0")
                continue;
            
            // Find iteration and remove it
            myIterator = find(games.begin(), games.end(), input);
            games.erase(myIterator);
            myIterator = games.begin();
            
            cout << input << " was removed from games. You can view the new list from the menu.\n";
        }
        else if (selection[0] != '4' && selection != "QUIT" )
        {
            cout << "\nYou mistyped or didn't select an option from above.\n";
        }
        
        
    }
    
    // List off the games one last time
    cout << "\nHere was the final list of favorite games you created: \n";
    for (iter = games.begin(); iter != games.end(); iter++)
    {
        cout << *iter << endl;
    }
    cout << endl;
    
    return 0;
}
