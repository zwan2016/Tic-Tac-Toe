CC  = g++
C	= cpp
H	= h

INCLUDES = -I view -I model -I controller -I rapidjson
CFLAGS = -std=c++11 ${INCLUDES}

HFILES = view/GameBoard.${H} model/Player.${H} controller/TTTController.${H} rapidjson/document.${H} rapidjson/writer.${H} rapidjson/stringbuffer.${H}
OFILES = view/GameBoard.o model/Player.o controller/TTTController.o main.o
PROJECTName=main
PROJECT = main

ttt.cgi:${OFILES}
	${CC} ${CFLAGS} -o ttt.cgi ${OFILES} ${LDFLAGS}

main.o: main.${C} ${HFILES}
	${CC} ${CFLAGS} -o main.o -c main.${C}

view/GameBoard.o: view/GameBoard.${C}
	${CC} ${CFLAGS} -o view/GameBoard.o -c view/GameBoard.${C}
model/Player.o: model/Player.${C}
	${CC} ${CFLAGS} -o model/Player.o -c model/Player.${C}
controller/TTTController.o: controller/TTTController.${C}
	${CC} ${CFLAGS} -o controller/TTTController.o -c controller/TTTController.${C}


clean:
	rm -rf core.* *.cgi *.o *~ ${PROJECTName} view/*.o model/*.o controller/*.o 

