CXX = g++

CXXFLAGS = -Wall -g

build:
	mkdir -p builds
	$(CXX) $(CXXFLAGS) -o builds/huffy huffmanenc.cpp binary_heap.cpp

clean:
	rm *.o
