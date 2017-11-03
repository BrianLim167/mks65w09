#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
  char path[] = "./";

  DIR *siz = opendir(path);
  DIR *dir = opendir(path);
  DIR *fil = opendir(path);
  struct dirent *ent;
  struct stat buffer;
  size_t size = 0;

  printf("Stats for %s\n",path);
  printf("========\n");

  printf("Size\n");
  while (ent = readdir(siz)){
    stat(ent->d_name,&buffer);
    if (ent->d_type == DT_REG) size += buffer.st_size;
  }
  printf("\t%lu bytes\n", size);
  printf("--------\n");

  printf("Directories\n");
  while (ent = readdir(dir)){
    if (ent->d_type == DT_DIR) printf("\t%s\n", ent->d_name);
  }
  printf("--------\n");

  printf("Files\n");
  while (ent = readdir(fil)){
    if (ent->d_type == DT_REG) printf("\t%s\n", ent->d_name);
  }
  printf("--------\n");


  closedir(siz);
  closedir(dir);
  closedir(fil);

  return 0;
}
