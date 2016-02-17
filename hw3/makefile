CXX = g++
FLAGS = -Wall -g
GTEST_LL = -I /usr/local/opt/gtest/include/ -l gtest -l gtest_main -pthread
all: llistint

clean:
	rm test

listtest: llistint.cpp llistint.h test.cpp
	$(CXX) $(FLAGS) $(GTEST_LL) llistint.cpp test.cpp -o ./bin/test

p5: llistint.cpp llistint.h stack.h stack.cpp main5.cpp
	$(CXX) $(FLAGS) llistint.cpp stack.cpp main5.cpp -o p5