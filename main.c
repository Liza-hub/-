#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "source.h"
#include "structfile.h"
#include "menu.h"



int main(void) {
  int choice;
  FILE *Ptr = NULL, *Ptr_2 = NULL, *blackrecord = NULL;
  Data client_data = {};
  Data transfer = {};
  menu_choice();
  int res = scanf("%d", &choice);
  while (res != -1) {
    switch (choice) {
      case 1:
        Ptr = fopen("record.dat", "r+");
        if (Ptr == NULL) {
          puts("Not acess");
        } else {
          masterWrite(Ptr, client_data);
          fclose(Ptr);
        }
        break;
      case 2:
        Ptr = fopen("transaction.dat", "r+");
        if (Ptr == NULL) {
          puts("Not acess");
        } else {
          transactionWrite(Ptr, transfer);
          fclose(Ptr);
        }
        break;
      case 3:
        Ptr = fopen("record.dat", "r+");
        Ptr_2 = fopen("transaction.dat", "r+");
        blackrecord = fopen("blackrecord.dat", "w");
        if (Ptr == NULL || Ptr_2 == NULL || blackrecord == NULL) {
          puts("exit");
        } else {
          blackRecord(Ptr, Ptr_2, blackrecord, client_data, transfer);
          fclose(Ptr);
          fclose(Ptr_2);
          fclose(blackrecord);
        }
        break;
      default:
        puts("error");
        break;
      }
      menu_choice();
      res = scanf("%d", &choice);
    }
  return 0;
}
