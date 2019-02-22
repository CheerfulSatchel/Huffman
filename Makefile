CXX = g++

CXXFLAGS = -Wall -g

build:
	mkdir -p builds
	$(CXX) $(CXXFLAGS) -o builds/huffy huffman_enc.cpp binary_heap.cpp huffman_node.cpp

clean:
	rm *.o
