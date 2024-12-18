# CXX Make variable for compiler
CXX=g++
# -std=c++11  C/C++ variant to use, e.g. C++ 2011
# -Wall       show the necessary warning files
# -g3         include information for symbolic debugger e.g. gdb
CXXFLAGS=-std=c++11 -Wall -g3 -c

# object files
OBJS = tree.o countSubStrings.o

# Program name
PROGRAM = countsubstrings

# Rules format:
# target : dependency1 dependency2 ... dependencyN
#     Command to make target, uses default rules if not specified

# First target is the one executed if you just type make
# make target specifies a specific target
# $^ is an example of a special variable.  It substitutes all dependencies
$(PROGRAM) : $(OBJS)
	$(CXX) -o $(PROGRAM) $^

trie.o : tree.h tree.cpp
	$(CXX) $(CXXFLAGS) tree.cpp

countSubStrings.o : tree.h countSubStrings.cpp
	$(CXX) $(CXXFLAGS) countSubStrings.cpp

clean :
	rm -f *.o $(PROGRAM)

