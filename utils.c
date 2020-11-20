#include <stdio.h>
#include <stdlib.h>

#include "source.h"
#include "utils.h"

void write_to_file_client(FILE *f, Data *client) {
  fprintf(f, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n", client->Number,
                                                                 client->Name,
                                                                 client->Surname,
                                                                 client->addres,
                                                                 client->TelNumber,
                                                                 client->indebtedness,
                                                                 client->credit_limit ,
                                                                 client->cash_payments);
}


int read_from_file_client(FILE *f, Data *client_data) {
  int res = 0;
  res = fscanf(f, "%10d%10s%10s%10s%10s%10lf%10lf%10lf", &client_data->Number,
                                                     client_data->Name,
                                                     client_data->Surname,
                                                     client_data->addres,
                                                     client_data->TelNumber,
                                                     &client_data->indebtedness,
                                                     &client_data->credit_limit,
                                                     &client_data->cash_payments);
  return res;
}


void write_to_file_transfer(FILE *f, Data *transfer) {
  fprintf(f, "%-3d%-5.2f\n", transfer->Number, transfer->cash_payments);
}


int read_from_file_transfer(FILE *f, Data *transfer) {
  int res = 0;
  res = fscanf(f, "%d %lf", &transfer->Number, &transfer->cash_payments);
  return res;
}
