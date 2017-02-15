EXEC = stats

CXX = g++
CFLAGS = -Wall -Wextra -O3 -march=native -fopenmp
BOOST_LIBS = -lboost_program_options -lboost_filesystem -lboost_system
LDFLAGS = $(BOOST_LIBS) -fopenmp
SRC = $(wildcard *.cc)
OBJECTS = $(patsubst %.cc, %.o, $(SRC))

.PHONY : clean

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) *.o
