#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ofstream inFile("data.txt");
    inFile << "Cat" << endl;
    inFile << "Elephant" << endl;
    inFile << "Banana" << endl;
    inFile << "Dog" << endl;
inFile.close();

ifstream readFile("data.txt");

vector<int> positions;
vector<string> words;

string word;

while(getline(readFile, word))
{
    words.push_back(word);
}

for(int i =0; i< words.size(); i++)
{
    for(int j=i+1; j < words.size(); j++)
    {
        if(words[i] > words[j])
        {
            string temp = words[i];
            words[i] = words[j];
            words[j] = temp;
        }
    }
}

for (int i =0; i <words.size(); i++)
{
    cout << words[i] << endl;
}

readFile.close();

return 0;

}


