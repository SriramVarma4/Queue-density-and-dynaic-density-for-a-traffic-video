compile:
	g++ task2.cpp -o task2 -pthread -std=c++11 `pkg-config --cflags --libs opencv`
all:
	g++ task2.cpp -o task2 -pthread -std=c++11 `pkg-config --cflags --libs opencv` && ./task2 trafficvideo.mp4
