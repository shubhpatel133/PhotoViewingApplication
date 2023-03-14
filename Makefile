objects = main.o TestView.o TestControl.o Client.o PhotoGram.o AlbumArray.o Album.o PhotoArray.o Photo.o Date.o

all: $(objects)
	g++ -o a2  $(objects)

a2: $(objects)
	g++ -o a2  $(objects)

main.o: main.cc
	g++ -c main.cc 

TestView.o: TestView.h TestView.cc 
	g++ -c TestView.cc

TestControl.o: TestControl.h TestControl.cc 
	g++ -c TestControl.cc

Client.o: Client.h Client.cc 
	g++ -c Client.cc

PhotoGram.o: PhotoGram.h PhotoGram.cc
	g++ -c PhotoGram.cc

AlbumArray.o: AlbumArray.h AlbumArray.cc
	g++ -c AlbumArray.cc

Album.o: Album.cc Album.h
	g++ -c Album.cc

PhotoArray.o: PhotoArray.cc PhotoArray.h
	g++ -c PhotoArray.cc
	
Photo.o: Photo.cc Photo.h 
	g++ -c Photo.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

clean:
	rm -f a2 *.o	