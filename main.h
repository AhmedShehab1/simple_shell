#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define BUFFER_SIZE 1024
extern char **environ;
/**
 * struct Directories - Dir In PATH Variable
 * @PtrToStr: Directory Name
 * @next: Pointer To Next node
 *
*/
typedef struct Directories
{
	char *PtrToStr;
	struct Directories *next;
} PathDir;
char *_getenv(const char *name);
char *NameOfProgram;
void void_RedirectedCommandInput(char *Str, PathDir *A_PtrToStruct);
char **_strtok(char *A_PtrToCommand);
void void_MyShell(char *A_LinePtr, PathDir *A_PtrToStruct);
char *HandlePath(char *CommandString, PathDir *A_PtrToStruct);
char *_strcat(char const *dest, char const *src);
int execBuiltInCommands(char *A_PtrToStr);
void _exit_(void);
void PrintEnv(void);
int _strcmp(const char *A_Str1, const char *A_Str2);
PathDir *PathDirLL(PathDir *A_PtrToStruct);
void _freeLL(PathDir *A_PtrToStruct);
#endif
