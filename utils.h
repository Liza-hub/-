#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_


#include "source.h"


void write_to_file_client(FILE *f, Data *client);
int read_from_file_client(FILE *f, Data *client);

void write_to_file_transfer(FILE *f, Data *client);
int read_from_file_transfer(FILE *f, Data *client);

#endif  // PROJECT_INCLUDE_UTILS_H_
