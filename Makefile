CXX?=g++ 
CXXFLAGS+= --std=c++17 -O3 -I. -static-libgcc -static-libstdc++ -static 
SOURCES= $(wildcard src/*.cpp)

src/%.o: src/%.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

sim: $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm src/*.o
