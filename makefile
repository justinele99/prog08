# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

plagiarismCatcher: 
	g++ -std=c++11 main.cpp folder.cpp hashTable.cpp matrix.cpp parser.cpp -o plagiarismCatcher
