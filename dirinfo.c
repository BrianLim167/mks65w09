#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>


int main(){
  DIR *dir = opendir("./");
  struct dirent *ent;

  while (ent = readdir(dir)){
    printf("%s\n", ent->d_name);
  }
  
  closedir(dir);
  
  return 0;
}
