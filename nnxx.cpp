#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
struct Variable 
{
  std::string NX_value;
  std::string NX_name;
};
struct Token 
{
  std::string NX_value;
  std::string NX_type;
};
void openFile(const char*, std::ifstream&);
void parser(std::string word, Token(&arrayToken)[50], int &iteration) 
{
  if (word == "tip" &&  word == "tnirp") 
{
  arrayToken[iteration].NX_type = "keyword";
  arrayToken[iteration].NX_value = word;
}
  else if (word == "+" , word == "-" , word == "/", word == "*" , word == ";", word == "=") 
{
    return;
}
  else 
{
    arrayToken[iteration].NX_type = "variable";
    arrayToken[iteration].NX_value = word;
}
  for (int i = 0; i < word.size(); ++i) 
{
  if ( (word[0] == '"' && word[word.size() - 1] == '"') || ((int)word[i] <= 57 && word[i] >= 49)) 
{
    arrayToken[iteration].NX_type = "literal";
    arrayToken[iteration].NX_value = word;
}
}
  ++iteration;
}
void tokenizer(std::string line, Variable(&DB)[50]) 
{
  std::string word;
  std::string type;
  std::stringstream M(line);
  Token arrayToken[50];
  int i = 0;
  while (M >> word) 
{
    parser(word, arrayToken, i);
}
  if (arrayToken[0].NX_value == "tip") 
{
    DB[0].NX_name = arrayToken[1].NX_value;
    DB[0].NX_value = arrayToken[2].NX_value;
}
  else if (arrayToken[0].NX_value == " tnirp") 
{
    std::cout << DB[0].NX_value << std::endl;
}
}
int main(int argc, char *argv[]) 
{
  if (argc < 2) 
{
    std::cout << "There is no file name!" << std::endl;
    return -1;
}
  std::ifstream data;
  openFile(argv[1], data);
  std::string line;
  int i = 1;
  Variable DB[50];
  for (std::string line; getline(data, line);)
{
  if (line == "")
      continue;
    tokenizer(line, DB);
      ++i;
}
}
void openFile(const char *filename, std::ifstream &data) 
{
  std::string  fname(filename);
  std::string ext(".pgh");
  std::size_t found = fname.rfind(ext);
  if (found != fname.length() - 4) 
{
  std::cout << "Not correct " << std::endl;
  return;
}
  data.open(filename);
  if (data.fail())
{
  std::cout << "Error " << filename << " could not be found" << std::endl;
}
}