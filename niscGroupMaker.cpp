#include <iostream>
#include <string>
#include <random>
#include <vector>
using namespace std;

// This code creates groups randomly.
// It does its best to put an equal number of Japanese and non-Japanese people in each group.
// Author: Koichi Ueno
// Date: 2022/11/30

// Enter here all Japanese people's names.
vector<string> japanesePpl() {
  return vector<string> {
    
  };
}

// Enter here all non-Japanese people's names.
vector<string> nonJapanesePpl() {
return vector<string> {
    
  };
}

// Create a pool of people.
// Can pick people randomly from it, without any repetition.
struct RandomisedPool {
  vector<string> members;
  int count;
  int size;

  RandomisedPool(vector<string> ppl) {
    members = ppl;
    // Set seed depending on actual time so that every run gives different output
    default_random_engine engine;
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    shuffle(members.begin(), members.end(), engine);

    count = 0;
    size = ppl.size();
  }

  int pplCount() { return size; }
  bool canPick() { return count < size; }
  // Don't use if canPick returns false
  string pick() { return members[count++]; }
};

// A group of people (string).
struct Group {
  int maxSize; // 1-based
  int actual;
  vector<string> members;

  Group() {
    maxSize = -1;
    members = vector<string>(1);
    actual = -10000000;
  }

  Group(int count) {
    maxSize = count;
    members = vector<string>(count);
    actual = 0;
  }

  int count() { return actual; }
  bool canAdd() { return actual < maxSize; }
  // Don't use if canAdd() returns false
  void addSomeone(string person) { members[actual++] = person; }

  vector<string>::iterator begin() {return members.begin(); }
  vector<string>::iterator end() { return members.end(); }
};

int main() {
  RandomisedPool jp = RandomisedPool(japanesePpl());
  RandomisedPool nonjp = RandomisedPool(nonJapanesePpl());

  cout << "Japanese people count: " << jp.pplCount() << "\n";
  cout << "Non-Japanese people count: " << nonjp.pplCount() << "\n";
  int total = jp.pplCount() + nonjp.pplCount();
  cout << "Total count: " << total << "\n\n";

  int n;
  cout << "How many groups?" << "\n"; cin >> n;

  // create n groups
  int maxPplPerGroup = floor(total/n) + 1;
  vector<Group> groups = vector<Group>(n);
  for(int i = 0; i < n; i++) { groups[i] = Group(maxPplPerGroup); }

  // Add JP ppl
  int i = 0;
  while(jp.canPick()) {
    groups[i++].addSomeone(jp.pick());
    i = i%n;
  }
  // Add non-JP ppl
  while(nonjp.canPick()) {
    groups[i++].addSomeone(nonjp.pick());
    i = i%n;
  }

  // Print out the groups
  i = 0;
  for(auto group : groups) {
    cout << "Group " << ++i << " members:\n";
    for(string p : group) {
      cout << "  " << p << "\n";
    }
    cout << "\n";
  }

  return 0;
}