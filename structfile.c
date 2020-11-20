#include <stdio.h>
#include <stdlib.h>

#include "source.h"
#include "utils.h"
#include "structfile.h"
#include "menu.h"



void masterWrite(FILE *ofPTR, Data Client) {
  input_client();
  while (scanf("%d%19s%19s%29s%14s%lf%lf%lf", &Client.Number,
                                             Client.Name,
                                             Client.Surname,
                                             Client.addres,
                                             Client.TelNumber,
                                             &Client.indebtedness,
                                             &Client.credit_limit ,
                                             &Client.cash_payments) != -1) {
    write_to_file_client(ofPTR, &Client);
    input_client();
  }
}


void transactionWrite(FILE *ofPtr, Data transfer) {
  input_transfer();
  while (scanf("%d %lf", &transfer.Number, &transfer.cash_payments) != -1) {
     write_to_file_transfer(ofPtr, &transfer);
     input_transfer();
  }
}


void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord, Data client, Data transfer) {
  while (read_from_file_client(ofPTR, &client) != -1) {
    while (read_from_file_transfer(ofPTR_2, &transfer) != -1) {
      if (client.Number == transfer.Number && transfer.cash_payments != 0) {
        client.credit_limit += transfer.cash_payments;
      }
    }
    write_to_file_client(blackrecord, &client);
    rewind(ofPTR_2);
  }
}
