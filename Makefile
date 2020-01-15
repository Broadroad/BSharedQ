all: consumer producer

SRC_DIR := src
CPPFLAGS+=-std=c++11 -Wall -pedantic
CPPFLAGS+=-g -O0

LDFLAGS+=-lboost_system -lrt -lpthread

%:${SRC_DIR}/%.cpp
	$(CXX) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)