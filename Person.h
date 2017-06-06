#define STR_LEN 50

typedef struct _person
{
    int ssn;               // 주민등록번호
    char name[STR_LEN];    // 이 름
    char addr[STR_LEN];    // 주 소

} Person;

int GetSSN(Person* p);
void ShowPerInfo(Person* p);
Person* MakePersonData(int ssn, char* name, char* addr);
