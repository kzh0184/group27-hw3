CC = g++
SRCS = address.cpp credit_card.cpp product.cpp store.cpp transaction.cpp main.cpp person.cpp

OBJS=$(SRCS:.c=.o)

all: main.cpp $(OBJS)
	mkdir -p build
	$(CC) $(OBJS) -o build/MAIN.out

%.o: %.cpp
	@echo making $^
	$(CC) -c $(SRCS)


