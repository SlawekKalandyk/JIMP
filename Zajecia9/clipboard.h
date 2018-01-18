// Sławomir Kalandyk
#ifndef CLIPBOARD_H
#define CLIPBOARD_H

int set(const char *text);
void printToStdout(void);
int append(const char *text);
void clean(void);
int count(void);
int capacity(void);
void initialise(void);

#endif