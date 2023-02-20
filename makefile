CXX = g++
CFLAGS = -Wall -Wextra -O -g
SOURCE = raytracer.cpp
EXEC = raytracer
FILE = scene.ppm
SUPPORT = cameras/*.cpp geometry/*.cpp materials/*.cpp samplers/*.cpp utilities/*.cpp world/*.cpp


CH14S:
	$(CXX) $(SOURCE) build/buildChapter14.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC) 
	time ./$(EXEC)
	code $(FILE)

MVPS:
	$(CXX) $(SOURCE) build/buildMvp.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC)
	time ./$(EXEC)
	code $(FILE)

HWS:
	$(CXX) $(SOURCE) build/buildHelloWorld.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC) 
	time ./$(EXEC)
	code $(FILE)

CH14A:
	$(CXX) $(SOURCE) build/buildChapter14_AA.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC) 
	time ./$(EXEC)
	code $(FILE)

MVPA:
	$(CXX) $(SOURCE) build/buildMvp_AA.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC) 
	time ./$(EXEC)
	code $(FILE)

HWA:
	$(CXX) $(SOURCE) build/buildHelloWorld_AA.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC) 
	time ./$(EXEC)
	code $(FILE)

clean:
	rm ./$(EXEC)
