tree:  bst.o userInfo.o bstApp.o
	g++ -o tree bst.o userInfo.o bstApp.o

bst.o:	bst.h bst.cpp
	g++ -c bst.cpp

userInfo.o:	userInfo.h userInfo.cpp
	g++ -c userInfo.cpp

bstApp.o:	bst.h userInfo.h bstApp.cpp
	g++ -c bstApp.cpp