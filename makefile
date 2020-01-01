library: BinarySearchTree.cpp
	cl /c BinarySearchTree.cpp
	lib BinarySearchTree.obj

compile_test:
	cl /c test.cpp
	link test.obj BinarySearchTree.lib

compile_count:
	cl /c wordcounter.cpp
	link wordcounter.obj BinarySearchTree.lib

test:
	test
	
single_words:
	wordcounter single_words_test.txt
	
sentences:
	wordcounter sentences_test.txt

clean:
	del *.obj *.exe *.lib