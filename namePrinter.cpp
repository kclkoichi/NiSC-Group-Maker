#include <iostream>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

// Output easily usable combined name+telegrams
// Input (copy paste) in name.txt and telegram.txt
// Adds @ to telegram handles without @ as 1st character
int main() {
  queue<string> names;
  queue<string> telegrams;

  // Read names from name.txt
  ifstream nameStream("name.txt");
  if (nameStream.is_open()) {
    string n;
    while(getline(nameStream, n)) { names.push(n); }
    nameStream.close();
  }

  // Read telegrams from telegram.txt
  ifstream telegramStream("telegram.txt");
  if (telegramStream.is_open()) {
    string t;
    while(getline(telegramStream, t)) { telegrams.push(t); }
    telegramStream.close();
  }

  // Output
  while(names.size() > 0) {
    cout << "\"" << names.front() << "   " << (telegrams.front()[0] == '@' ? telegrams.front() : "@" + telegrams.front()) << "\",\n";
    names.pop();
    telegrams.pop();
  }

  return 0;
}