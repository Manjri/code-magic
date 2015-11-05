arxan : main.o base64_scheme1.o base64_scheme2.o
	g++ -Wall -o arxan main.o base64_scheme1.o base64_scheme2.o

main.o : main.cpp base64_scheme1.h base64_scheme2.h
	g++ -Wall -c main.cpp

base64_scheme1.o : base64_scheme1.cpp base64.h
	g++ -Wall -c base64_scheme1.cpp

base64_scheme2.o : base64_scheme2.cpp base64.h
	g++ -Wall -c base64_scheme2.cpp

clean :
	rm arxan main.o base64_scheme1.o base64_scheme2.o
