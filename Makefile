CXX = g++

CXXFLAGS = -Wall -g

build:
	mkdir -p builds
	$(CXX) $(CXXFLAGS) -o builds/HuffEnc huffman_enc.cpp binary_heap.cpp huffman_node.cpp huffman_tree.cpp

test:
	mkdir -p builds
	$(CXX) $(CXXFLAGS) -o builds/TestHeap test_binary_heap.cpp binary_heap.cpp huffman_node.cpp

clean:
	rm *.o
