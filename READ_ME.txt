Instructions:
1. type in "module load gcc" to update gcc to get c++11 flag
2. make sure that you have the directory of test files is in the same directory
3. type "make" into command window
4. type "./plagiarismCatcher <pathToFiles> <sizeOfChunk> <numCollisions>"
5. press enter to run file

Notes: 
*works for small and medium document sets
	example propmt: ./plagiarismCatcher sm_doc_set 10 200

*works for large document sets in cLion - hasn't been tested in Kamek

*all three arguements MUST be defined - code does not account for lacking input

*arguements must be entered in the correct order according to the instructions