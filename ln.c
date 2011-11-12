#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int symlink = 0;
  char *old, *new;

  if(argc < 3 || argc > 4){
    printf(2, "Usage: ln [-s] old new\n");
    exit();
  }

  if(argc == 4){
    symlink = 1;
    old = argv[2];
    new = argv[3];
  }else{
    old = argv[1];
    new = argv[2];
  }

  if(link(old, new, symlink) < 0)
    printf(2, "link %s %s: failed\n", argv[1], argv[2]);
  exit();
}
