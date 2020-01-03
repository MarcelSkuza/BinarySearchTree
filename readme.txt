1. Program "wordcounter.exe", "test.exe" and library "BinarySearchTree.lib" are built using Microsoft Compiler.

2. In order to build/run these files enter following into Command Prompt (while in the working directory):
	
	nmake library -- to build "BinarySearchTree.lib"

	nmake compile_test -- to build "test.exe"

	nmake wordcouter_compile -- to build "wordcounter.exe"

3. In order to run test enter:
	nmake test

4. In order to run wordcounter program enter:

	nmake single_words -- to count words in "single_words_test.txt" file

	nmake sentences -- to count words in "sentences_test.txt" file

5. Finally, to delete all newly created files enter:

	nmake clean