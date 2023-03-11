CXX = g++
CFLAGS = -Wall -Wextra -O -g -fopenmp 
SOURCE = raytracer.cpp
EXEC = raytracer
FILE = scene
SUPPORT = cameras/*.cpp geometry/*.cpp materials/*.cpp samplers/*.cpp utilities/*.cpp world/*.cpp


CH14S:
	$(CXX) $(SOURCE) build/buildChapter14.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC) 
	time ./$(EXEC)
	code $(FILE).ppm

MVPS:
	$(CXX) $(SOURCE) build/buildMvp.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC)
	time ./$(EXEC)
	code $(FILE).ppm

HWS:
	$(CXX) $(SOURCE) build/buildHelloWorld.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC) 
	time ./$(EXEC)
	code $(FILE).ppm

CH14A:
	$(CXX) $(SOURCE) build/buildChapter14_AA.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC) 
	time ./$(EXEC)
	code $(FILE).ppm

MVPA:
	$(CXX) $(SOURCE) build/buildMvp_AA.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC) 
	time ./$(EXEC)
	code $(FILE).ppm

HWA:
	$(CXX) $(SOURCE) build/buildHelloWorld_AA.cpp $(SUPPORT) $(CFLAGS) -o $(EXEC) 
	time ./$(EXEC)
	code $(FILE).ppm

clean:
	rm ./$(EXEC) $(FILE).ppm

ppm_to_png:
	ffmpeg -i $(FILE).ppm $(FILE).png