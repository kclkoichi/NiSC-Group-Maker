This is a random group generator for NiSC events.
It tries to allocate the same number of Japanese people and non-Japanese people to each group.

How to use?
1. Create name.txt and copy paste all names in it (each person should be separated by a new line).
2. Create telegram.txt and copy paste all telegram handles in it (each one should be separated by a new line).
3. Run namePrinter.cpp, copy its output.
(You have to separate yourself Japanese and non-Japanese people!!)
4. Inside niscGroupMaker.cpp:
  4.1 Paste Japanese people inside the vector returned in japanesePpl()
  4.2 Paste non-Japanese people inside the vector returned in nonJapanesePpl()
5. Run niscGroupMaker.cpp, indicate number of groups wanted.