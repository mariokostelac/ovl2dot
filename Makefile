default:
	mkdir -p bin
	g++ -O2 -std=c++11 src/ovl2dot.cpp src/reader.cpp -o bin/ovl2dot
