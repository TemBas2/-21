#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_file_content(const char *file_path);
void write_file_content(const char *file_path);

int main() {
    char file_path[256] = "";
    int should_exit = 0;

    while (!should_exit) {
        int choice;
        scanf("%d", &choice);
        getchar();

        if (choice == -1) {
            should_exit = 1;
        } else if (choice == 1) {
            fgets(file_path, sizeof(file_path), stdin);
            file_path[strcspn(file_path, "\n")] = 0;
            print_file_content(file_path);
        } else if (choice == 2) {
            write_file_content(file_path);
        }
    }
    return 0;
}

void print_file_content(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }

    char buffer[256];
    if (fscanf(file, "%255[^\n]", buffer) == EOF) {
        printf("n/a\n");
        fclose(file);
        return;
    }
    printf("%s", buffer);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void write_file_content(const char *file_path) {
    if (file_path[0] == '\0') {
        printf("n/a\n");
        return;
    }
    FILE *file = fopen(file_path, "a");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }

    char input_text[256];
    fgets(input_text, sizeof(input_text), stdin);
    input_text[strcspn(input_text, "\n")] = 0;
    fprintf(file, "%s\n", input_text);
    fclose(file);
    print_file_content(file_path);
}
