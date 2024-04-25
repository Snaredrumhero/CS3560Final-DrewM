#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using std::string;

void countLine(string text);
void countChar(string text);
string file_read(string file_path);

int main(int argc, char** argv){

    string file_path;
    if (argc > 0)
    {
        file_path = argv[1];
    }
    else{
        std::cout << "Not enough arguments in command line" << std::endl;
        exit(0);
    }
    
    // string text = file_read(file_path);

    string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do\neiusmod tempor incididunt ut labore et dolore magna aliqua.\nUt enim ad minim veniam, quis nostrud exercitation ullamco laboris\nnisi ut aliquip ex ea commodo consequat.";

    std::cout << text;


    // std::cout << text;
    countLine(text);
    countChar(text);

    return 0;
}

void countLine(string text){
    // std::stringstream s(text);

    // string dummy;
    int counter = 0;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (text.at(i) =='\n')
        {
            counter ++;
        }
    }
    
    std::cout << counter << " Lines" << std::endl;
}

void countChar(string text){
    // int count = 0;
    // while (text[count])
    // {
    //     count ++;
    // }
    
    std::cout << text.length() << " Characters" << std::endl;
}

string file_read(string file_path){
    std::ifstream inStream;

    inStream.open(file_path);
    if (inStream.fail()){
        std::cout << "Couldn't open " << file_path << std::endl;
        exit(0);
    }

    string line;
    string total = "";
    while(std::getline(inStream, line)){
        total += line;
        total += '\n';
    }
    inStream.close();

    return total;
}