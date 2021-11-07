main: Main.o hf.o shell.o m5.o hoare.o lomuto.o
	$(CC) -o main Main.o hf.o shell.o m5.o hoare.o lomuto.o

Main.o: Main.cpp Main.h
	$(CC) -c Main.cpp

hoare.o: hoare.cpp hoare.h
	$(CC) -c hoare.cpp

hf.o: hf.cpp hf.h
	$(CC) -c hf.cpp

shell.o: shell.cpp shell.h
	$(CC) -c shell.cpp

m5.o: m5.cpp m5.h
	$(CC) -c m5.cpp

lomuto.o: lomuto.cpp lomuto.h
	$(CC) -c lomuto.cpp

clean:
	rm -rf ./*.o
