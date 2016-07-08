#include <inttypes.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char current_dir_abs_path[1024];
    do {
        DIR *dir;
        struct dirent *dp;
        char current_dir[1024];

        getcwd(current_dir, sizeof(current_dir));

        if ( (dir = opendir(current_dir)) == NULL) {
            fprintf(stderr, "Cannot open %s: %s\n", current_dir, strerror(errno));
            exit(1);
        }

        realpath(current_dir, current_dir_abs_path);

        while ( (dp = readdir(dir)) != NULL) {
            if ( strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0 ) {
                printf("ID for %s/%s -> %" PRIu64 "\n", current_dir_abs_path, dp->d_name, dp->d_ino);
            }
        }

        chdir("..");
        closedir(dir);
    } while (strcmp(current_dir_abs_path, "/") != 0);
}
