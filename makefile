default: main.cpp
	clear && clear && g++ main.cpp -o exe -std=c++11

val:
	clear && clear && g++ main.cpp -o exe -std=c++11 && valgrind ./exe
	
clean:
	clear
