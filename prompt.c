/*
 ============================================================================
 Name        : Prompt.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaDinEnc.h"

void print_entry(List* li, char *entry) {
    int param = 0;
    char *cmd;
    int value, response;
    char *pch = strtok (entry, " \n");
    while (pch != NULL){
        if(param == 0)
            cmd = pch;
        else
            value = atoi(pch);
        pch = strtok (NULL, " \n");
        param++;
    }

    if(strcmp(cmd, "put") == 0){
        insert_list_last(li, value);
        show_list(li);
    }
    if(strcmp(cmd, "get") == 0){
        search_list_at(li, value, &response);
        printf("%d\n", response);
    }
    if(strcmp(cmd, "first") == 0){
        search_list_at(li, 1, &response);
        printf("%d\n", response);
    }
    if(strcmp(cmd, "last") == 0){
        int size_list = get_size_list(li);
        search_list_at(li, size_list, &response);
        printf("%d\n", response);
    }
    if(strcmp(cmd, "remove") == 0){
        response = remove_list_at(li, value);
        printf("%d\n", response);
        show_list(li);
    }
    if(strcmp(cmd, "list") == 0){
        show_list(li);
    }
    if(strcmp(cmd, "clear") == 0){
        free_list(li);
    }    
}

int main(int argc, char *argv[]) {
	char input[201];
    List *li = create_list();

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		print_entry(li, input);
	}
	return EXIT_SUCCESS;
}
