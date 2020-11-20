#include <stdio.h>
#include "menu.h"
#include "source.h"

void menu_choice() {
  printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
}

void input_client() {
  printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
  "1 Number account: ",
  "2 Client name: ",
  "3 Surname: ",
  "4 Addres client: ",
  "5 Client Telnum: ",
  "6 Client indebtedness: ",
  "7 Client credit limit: ",
  "8 Client cash payments: ");
}

void input_transfer() {
  printf("%s\n%s\n",
    "1 Number account:",
    "2 Client cash payments: ");
}
