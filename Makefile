CXXFLAGS=-fno-omit-frame-pointer # do not omit the frame pointer \
         -ggdb3 # detailed debugging information
CXX=g++ -std=c++11

all: vector random

vector:	vector.cc
	$(CXX) $(CXXFLAGS) $< -o $@

random:	random.cc
	$(CXX) $(CXXFLAGS) $< -o $@

distclean:	clean
		rm -f vector random

clean:
		rm -f *.o
