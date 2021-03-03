PROGRAM_TEST = testGUI

# Compilation command and flags
CXX = g++
CXXVERSION= -std=c++11
CXXFLAGS= $(CXXVERSION) -g -fprofile-arcs -ftest-coverage

LINKFLAGS = -lgtest

SRC_DIR = src

# Directories
GTEST_DIR = test
TEST_FILE_EMPTY_WINDOW = asciiWindow_empty.txt
TEST_FILE_WIDGETS_WINDOW = asciiWindow_widgets.txt

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Coverage
GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

# Tool varialbes
STATIC_ANALYSIS = cppcheck
STYLE_CHECK = cpplint.py
DOXY_DIR = docs/code

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := testGUI

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o *.o $(GTEST_DIR)/output/*.dat \
	*.gcov *.gcda *.gcno *.orig ???*/*.orig \
	$(PROJECT) $(GTEST) $(MEMCHECK_RESULTS) $(COVERAGE_DIR)  \
	$(DOXY_DIR)/html obj bin $(PROGRAM_TEST).exe

$(PROGRAM_TEST): $(GTEST_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) \
	$(GTEST_DIR)/*.cpp $(SRC_DIR)/*.cpp $(LINKFLAGS)

# Tests
.PHONY: allTests
allTests: testGUI testGUI-diff \
		memcheck static style

.PHONY: test-clean
tests: $(PROGRAM_TEST)
	$(PROGRAM_TEST)
	diff -s $(TEST_FILE_EMPTY_WINDOW) test/output/ascii_empty_expected.txt
	diff -s $(TEST_FILE_WIDGETS_WINDOW) test/output/ascii_widgets_expected.txt

.PHONY: memcheck
memcheck: $(PROGRAM_TEST_CLEAN)
	valgrind --tool=memcheck --leak-check=full --error-exitcode=1 $(PROGRAM_TEST)

.PHONY: static
static: ${GTEST_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all ${GTEST_DIR} --suppress=missingInclude

.PHONY: style
style: ${TEST_DIR}
	${STYLE_CHECK} ${GTEST_DIR}/*

.PHONY: docs
docs: ${SRC_INCLUDE}
	doxygen $(DOXY_DIR)/doxyfile

.PHONY: coverage
coverage: $(PROGRAM_TEST)
	$(PROGRAM_TEST)
	# Determine code coverage
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS)
	# Only show code coverage for the source code files (not library files)
	$(LCOV) --extract $(COVERAGE_RESULTS) "*/codecoverage/src/*" -o $(COVERAGE_RESULTS)
	#Generate the HTML reports
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	#Remove all of the generated files from gcov
	rm -f *.gc*
