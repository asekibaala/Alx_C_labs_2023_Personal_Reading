#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define S_IRUSER (1 << 2)
#define S_IWUSER (1 << 1)
#define S_IXUSER (1 << 0)

#define S_IRGRP (1 << 5)
#define S_IWGRP (1 << 4)
#define S_IXGRP (1 << 3)

#define S_IROTH (1 << 8)
#define S_IWOTH (1 << 7)
#define S_IXOTH (1 << 6)

int 
file (char *name)
{
    printf("%s\n",name);
    struct stat buf;
    char timestr[32];

    if ( stat(name , &buf)<0)
    {
        printf("\tCannot stat it ---errno=%d\n", errno);
        return -1;
    }

printf ("\tDevice ID:\t%ld\n", buf.st_dev);
  printf ("\tInode no:\t%ld\n", buf.st_ino);

  printf ("\tFile mode:\t%o\n", buf.st_mode);
  if (buf.st_mode & S_IFREG)
    printf ("\t\tordinary file\n");
  if (buf.st_mode & S_IFDIR)
    printf ("\t\tdirectory\n");
  if (buf.st_mode & S_IRUSR)
    printf ("\t\treadable for owner\n");
  if (buf.st_mode & S_IWUSR)
    printf ("\t\twritable for owner\n");
  if (buf.st_mode & S_IXUSR)
    printf ("\t\texecutable for owner\n");
  if (buf.st_mode & S_IRGRP)
    printf ("\t\treadable for group\n");
  if (buf.st_mode & S_IWGRP)
    printf ("\t\twritable for group\n");
  if (buf.st_mode & S_IXGRP)
    printf ("\t\texecutable for group\n");
  if (buf.st_mode & S_IROTH)
    printf ("\t\treadable for others\n");
  if (buf.st_mode & S_IWOTH)
    printf ("\t\twritable for others\n");
  if (buf.st_mode & S_IXOTH)
    printf ("\t\texecutable for others\n");
  printf ("\tHard links:\t%ld\n", buf.st_nlink);
  printf ("\tOwner UID:\t%d\n", buf.st_uid);
  printf ("\tGroup GID:\t%d\n", buf.st_gid);
  printf ("\tSpecial ID:\t%ld\n", buf.st_rdev);
  printf ("\tFile size:\t%ld\n", buf.st_size);
//      printf("\tBlk size:\t%ld\n", buf.st_blksize);      absent in MS Windows
//      printf("\tBlk count:\t%ld\n", buf.st_blocks);      absent in MS Windows
  printf ("\tAccess time:\t%s", ctime (&buf.st_atime));
  printf ("\tCreation time:\t%s", ctime (&buf.st_ctime));
  printf ("\tModifictn time:\t%s", ctime (&buf.st_mtime));
  return 0;

}
int
main (int argc, char *argv[])
{
  if (argc < 2)
    {
      fprintf (stderr, "usage: %s filename...\n", argv[0]);
      return 1;
    }
  int i;
  for (i = 1; i < argc; i++)
    file (argv[i]);
  return 0;
}