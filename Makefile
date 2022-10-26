# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Author>
list: main.c list.c
	gcc main.c list.c -o list -I.
