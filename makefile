CXX = g++

CXXFLAGS = -std=c++0x -g

# SRC

SRC1 = BedRoom.cpp
SRC2 = game.cpp
SRC3 = Garden.cpp
SRC4 = Item.cpp
SRC5 = Kitchen.cpp
SRC6 = Laundry.cpp
SRC7 = LivingRoom.cpp
SRC8 = main.cpp
SRC9 = menu.cpp
SRC10 = Pond.cpp
SRC11 = Queue.cpp
SRC12 = QueueNode.cpp
SRC13 = Space.cpp
SRC14 = utility.cpp


SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9} ${SRC10} ${SRC11} ${SRC12} ${SRC13} ${SRC14} ${SRC15}

# HEADERS
HEADER1 = BedRoom.cpp
HEADER2 = game.cpp
HEADER3 = Garden.cpp
HEADER4 = Item.cpp
HEADER5 = Kitchen.cpp
HEADER6 = Laundry.cpp
HEADER7 = LivingRoom.cpp
HEADER8 = menu.cpp
HEADER9 = Pond.cpp
HEADER10 = Queue.cpp
HEADER11 = QueueNode.cpp
HEADER12 = Space.cpp
HEADER13 = utility.cpp

# executables
PROG1 = Escaperoom
PROGS = ${PROG1}

# make all
all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

# make clean
clean:
	rm -f ${PROGS} *.o *~