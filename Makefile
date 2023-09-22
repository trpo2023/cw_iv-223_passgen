CXX=g++
CFLAGS= -I src/
PWGEN_SRC = src/pwgen_main/
LIBPWGEN_SRC = src/pwgen_lib/
PWGEN_OBJ = obj/src/pwgen_main/
LIBPWGEN_OBJ = obj/src/pwgen_main/
PWGEN_BIN = bin/
SRC = src/
TEST = test/
PWGEN_TEST_OBJ = obj/pwgen_test/
THIRDPARTY = thirdparty/

.PHONY: pwgen

$(PWGEN_BIN)main: $(PWGEN_OBJ)main.o $(LIBPWGEN_OBJ)deletepasswords.o $(LIBPWGEN_OBJ)generatepassword.o $(LIBPWGEN_OBJ)generator.o $(LIBPWGEN_OBJ)passchanger.o $(LIBPWGEN_OBJ)passwordused.o $(LIBPWGEN_OBJ)viewcontent.o $(LIBPWGEN_OBJ)newpassword.o
	$(CXX) $(CFLAGS) $^ -o $@
$(PWGEN_OBJ)main.o: $(PWGEN_SRC)main.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(LIBPWGEN_OBJ)deletepasswords.o: $(LIBPWGEN_SRC)deletepasswords.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(LIBPWGEN_OBJ)generatepassword.o: $(LIBPWGEN_SRC)generatepassword.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(LIBPWGEN_OBJ)generator.o: $(LIBPWGEN_SRC)generator.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(LIBPWGEN_OBJ)passchanger.o: $(LIBPWGEN_SRC)passchanger.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(LIBPWGEN_OBJ)passwordused.o: $(LIBPWGEN_SRC)passwordused.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(LIBPWGEN_OBJ)viewcontent.o: $(LIBPWGEN_SRC)viewcontent.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(LIBPWGEN_OBJ)newpassword.o: $(LIBPWGEN_SRC)newpassword.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@

.PHONY: test

test: $(PWGEN_BIN)test
	./$<

$(PWGEN_BIN)test: $(PWGEN_TEST_OBJ)ctest.o $(PWGEN_TEST_OBJ)main.o $(PWGEN_TEST_OBJ)testlib.a 
	$(CXX) -I thirdparty/ $(CFLAGS) -o $@ $^
$(PWGEN_TEST_OBJ)ctest.o: $(TEST)ctest.cpp
	$(CXX) -c -I thirdparty/ $(CFLAGS) -o $@ $^
$(PWGEN_TEST_OBJ)main.o: $(TEST)main.cpp
	$(CXX) -c -I thirdparty/ $(CFLAGS) -o $@ $^
$(PWGEN_TEST_OBJ)testlib.a: $(PWGEN_TEST_OBJ)deletepasswords.o $(PWGEN_TEST_OBJ)generatepassword.o $(PWGEN_TEST_OBJ)generator.o $(PWGEN_TEST_OBJ)passchanger.o $(PWGEN_TEST_OBJ)passwordused.o $(PWGEN_TEST_OBJ)viewcontent.o $(PWGEN_TEST_OBJ)newpassword.o
	ar rcs $@ $^
$(PWGEN_TEST_OBJ)deletepasswords.o: $(LIBPWGEN_SRC)deletepasswords.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(PWGEN_TEST_OBJ)generatepassword.o: $(LIBPWGEN_SRC)generatepassword.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(PWGEN_TEST_OBJ)generator.o: $(LIBPWGEN_SRC)generator.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(PWGEN_TEST_OBJ)passchanger.o: $(LIBPWGEN_SRC)passchanger.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(PWGEN_TEST_OBJ)passwordused.o: $(LIBPWGEN_SRC)passwordused.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(PWGEN_TEST_OBJ)viewcontent.o: $(LIBPWGEN_SRC)viewcontent.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(PWGEN_TEST_OBJ)newpassword.o: $(LIBPWGEN_SRC)newpassword.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -rf $(PWGEN_BIN)*
	rm -rf $(PWGEN_OBJ)*.o
	rm -rf $(LIBPWGEN_OBJ)*.o
	rm -rf $(LIBPWGEN_OBJ)*.a
	rm -rf $(PWGEN_TEST_OBJ)*.o
	rm -rf $(PWGEN_TEST_OBJ)*.a

.PHONY: format

CPPS := $(shell find . -type f -name '*.cpp')
HS := $(shell find . -type f -name '*.h')

format:
	clang-format -i $(CPPS) $(HS)