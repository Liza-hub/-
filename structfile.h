#ifndef PROJECT_INCLUDE_STRUCTFILE_H_
#define PROJECT_INCLUDE_STRUCTFILE_H_


#include "source.h"
#include <stdlib.h>
#include <stdio.h>

void masterWrite(FILE *ofPTR, Data Client);

void transactionWrite(FILE *ofPtr, Data transfer);

void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord, Data client, Data transfer);


#endif  // PROJECT_INCLUDE_STRUCTFILE_H_
