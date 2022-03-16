all: data_structures
data_structures: linked_list hash_table generic_binary_tree
		gcc -o ./bin/data_structures ./bin/linked_list ./bin/hash_table ./bin/generic_binary_tree
linked_list: linked_list.c
	gcc -o ./bin/linked_list linked_list.c -c -W -Wall -ansi -pedantic
hash_table: hash_table.c
	gcc -o ./bin/hash_table hash_table.c -c -W -Wall -ansi -pedantic
generic_binary_tree: generic_binary_tree.c
	gcc -o ./bin/generic_binary_tree generic_binary_tree.c -c -W -Wall -ansi -pedantic
clean:
	rm bin/*
