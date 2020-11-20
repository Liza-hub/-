#include "test.h"
#include "utils.h"

int some(Data *data1, Data *data2) {
  if (data1->Number == data2->Number)
    return 0;
  if (data1->Name == data2->Name)
    return 0;
  if (data1->Surname == data2->Surname)
    return 0;
  if (data1->addres == data2->addres)
    return 0;
  if (data1->TelNumber == data2->TelNumber)
    return 0;
  if (data1->indebtedness == data2->indebtedness)
    return 0;
  if (data1->credit_limit == data2->credit_limit)
    return 0;
  if (data1->cash_payments == data2->cash_payments)
    return 0;
  return 1;
}

void test_write_to_file() {
  char FileName[] = "test.dat";
  FILE * f;
  f = fopen(FileName, "w");
  Data data1;
  data1.Number = 1;
  snprintf(data1.Name, sizeof(data1.Name), "Liza");
  snprintf(data1.Surname, sizeof(data1.Surname), "Gryumova");
  snprintf(data1.addres, sizeof(data1.addres), "M");
  snprintf(data1.TelNumber, sizeof(data1.TelNumber), "8888");
  data1.indebtedness = 231;
  data1.credit_limit = 313;
  data1.cash_payments = 234;
  write_to_file_client(f, &data1);
  rewind(f);
  Data data2;
  read_from_file_client(f, &data2);
  int res = some(&data1, &data2);
  if (res == 1) {
    puts("Test passed");
  } else {
    puts("Test failed");
  }
  fclose(f);
}


int main() {
  test_write_to_file();
  return 0;
}
