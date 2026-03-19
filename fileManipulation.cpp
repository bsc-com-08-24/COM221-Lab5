#include <iostream>
#include <fstream>
#include <string>
#include <cctype> //header that contains the tolower() funtion and other type based functions

using namespace std;

const char vowels[10] = {'a','e','i','o','u'};

int numberOfSpaces(string n);

void numberOfVowels(string n);

//int numberOfVowels2(string n);//Version 2 of number of vowels that does not use an array to check for vowels


//used int& to reference the original arguments value because it function is supposed to change it
string getWord(string n, int& indexer);


int numberOfWords(string n);
void numberOfWordsOut(string n);

string sentenceReversal(string n);

string Reversal(string n);

string secondLetterCapitalization(string n);


int main()
{
    string fileData;
    
    int index = 0;

    ifstream inFile("file.txt");
    if (inFile.is_open()){
        getline(inFile, fileData);
    }else{
        cout << "Unable to open file";
        return 1;
    }

    numberOfVowels(fileData);
    numberOfWordsOut(fileData);
    cout << "File Data Reversal: " << Reversal(fileData) << endl;

    cout << "Second Letter Capitalization: " << secondLetterCapitalization(fileData) << endl;

    return 0;
}



//Number of spaces
int numberOfSpaces(string n){
    int NOS = 0;
    for(char c : n){
        if(c == ' '){
            NOS++;
        }
    }
    return NOS;
}


//number of vowels
void numberOfVowels(string n){
    int vowelCount = 0;
    for(char c : n){
        for(int i = 0; i < sizeof(vowels); i++){
            if(tolower(c) == vowels[i]){
                vowelCount++;
            }
        }
    }

    cout << "Number of vowels: " << vowelCount << endl;
}

//number of vowels version 2
/*
int numberOfVowels2(string n){
    int vowelCount = 0;
    for(char c : n){
        if(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u'){
            vowelCount++;
        }
    }

    return vowelCount;
}
*/




//get a single word from the a string 
string getWord(string n, int& indexer){
    string word = "";
    for(int i = indexer; i < n.length(); i++){
        char c = n[i];
        if(c != ' '){
            word = word + c;
            indexer++;
        }else{
               break;
        }
    }
    return word;
}

//number of words
int numberOfWords(string n) {
    int numberOfWords = numberOfSpaces(n) + 1;
   return numberOfWords;
}


void numberOfWordsOut(string n) {
    int numberOfWords = numberOfSpaces(n) + 1;
    cout << "Number of words: " << numberOfWords << endl;
}

//sentence reversal
//Unused
string sentenceReversal(string n){
    string words[numberOfWords(n)];
    int index = 0;
    string reverseSentence = "";

    for(int i = 0; i < numberOfWords(n);i++){
        words[i] = getWord(n, index);
        index += 1;
    }

    for(int i =  numberOfWords(n) - 1; i >= 0; i--){
        if(i == 0){
            reverseSentence = reverseSentence + words[i];
        }else{
            reverseSentence = reverseSentence + words[i] + " ";
        }   
    }
    return reverseSentence;

}

string Reversal(string n){
    string reverseSentence = "";

    for(int i = n.length() -1; i >= 0; i--){
        reverseSentence = reverseSentence + n[i];
    }
    return reverseSentence;
}



//second letter capitalization
string secondLetterCapitalization(string n){
    string words[numberOfWords(n)];
    int index = 0;
    string newSentence = "";

    for(int i = 0; i < numberOfWords(n);i++){
        words[i] = getWord(n, index);
        index += 1;
    }

    for(int i = 0; i < numberOfWords(n);i++){
         string word = words[i];
        if(word.length() > 1){
            word[1] = toupper(word[1]);
            if(i == numberOfWords(n) - 1){
                newSentence = newSentence + word;
            }else{
                newSentence = newSentence + word + " ";
            }
    
        }
    }

    return newSentence;

}