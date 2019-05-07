#include <iostream>
#include <cassert>
using namespace std;
struct Student {
    char name[17];
    uint16_t year;
    float average;
    uint8_t gerder:1;
    uint8_t courses;
    Student* starosta;
};

char nibble_to_hex (uint8_t i){
char digits []="0123456789abcdef";
return digits[i];
}
void
print_in_hex(uint8_t byte){
    cout<<nibble_to_hex(byte>>4)
    <<nibble_to_hex(byte & 0b00001111);


}

const uint8_t*
as_bytes(const void* data)
{
   return reinterpret_cast<const uint8_t*>(data);
}

void
print_in_hex(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
char
bit_digit(uint8_t byte, int bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}
void
print_in_binary(uint8_t byte) {
    for (int bit = 7; bit >=0; bit--) {
        cout << bit_digit(byte, bit);
    }
}
void
print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
void calc_hex (uint16_t op1,char operat, uint16_t op2 )
{
    if ((operat=='&') || (operat=='^') || (operat=='|')){
     print_in_hex(&op1, sizeof(op1));
     cout << " "<< operat<<" " ;
     print_in_hex(&op2, sizeof(op2));
     cout<< " = ";
     uint16_t res;
     if (operat== '&')
        res=op1&op2;

     if (operat== '|')
        res=op1|op2;
      if (operat== '^')
        res=op1^op2;
     print_in_hex(&res, sizeof(res));
}
else
    cout<< "Nekorrekt operator";
}
void calc_bin (uint16_t op1,char operat, uint16_t op2 )
{
    if ((operat=='&') || (operat=='^') || (operat=='|')){
     print_in_binary(&op1, sizeof(op1));
     cout << " "<< operat<<" " ;
     print_in_binary(&op2, sizeof(op2));
     cout<< " = ";
     uint16_t res;
     if (operat== '&')
        res=op1&op2;

     if (operat== '|')
        res=op1|op2;
      if (operat== '^')
        res=op1^op2;
     print_in_binary(&res, sizeof(res));
}
else
    cout<< "Nekorrekt operator";
}


int main()
{  assert(nibble_to_hex(0x0) == '0');
assert(nibble_to_hex(0x1) == '1');
assert(nibble_to_hex(0x2) == '2');
assert(nibble_to_hex(0x3) == '3');
assert(nibble_to_hex(0x4) == '4');
assert(nibble_to_hex(0x5) == '5');
assert(nibble_to_hex(0x6) == '6');
assert(nibble_to_hex(0x7) == '7');
assert(nibble_to_hex(0x8) == '8');
assert(nibble_to_hex(0x9) == '9');
assert(nibble_to_hex(0xa) == 'a');
assert(nibble_to_hex(0xb) == 'b');
assert(nibble_to_hex(0xc) == 'c');
assert(nibble_to_hex(0xd) == 'd');
assert(nibble_to_hex(0xe) == 'e');
assert(nibble_to_hex(0xf) == 'f');
/* uint32_t u32 = 0xa3;
cout << "u32 bytes: ";
print_in_hex(&u32, sizeof(u32));
cout << '\n';
 uint16_t u16 = 0x70;
cout << "u16 bytes: ";
print_in_hex(&u16, sizeof(u16));
cout << '\n';
uint32_t byte =0x42;
cout << "u32 bytes: ";
print_in_binary (&byte, sizeof(byte));
*/
/*uint16_t op1;
uint16_t op2;
char operat;

cin>>op1;

cin>>operat;

cin>>op2;

calc_hex (op1, operat, op2);
cout<< '\n';
calc_bin (op1, operat, op2);*/
Student students[3]{{"Ivan", 2016, 3.8,1,15, nullptr},{"Masha",2016,4.5,0,15,&students[0]},{"Kostya",2016,4.9,1,15,&students[0]}};
cout<< "Address of student :\t" <<&students[0]<<" "<<&students[1]<<" "<<&students[2]<<" "<<"\n";
cout<<"Size of students:\t" <<sizeof(students[0])<<"  "<<sizeof(students[1])<<"  "<<sizeof(students[2])<<'\n';
cout<<"Adress of name of Stud[1]:\t" <<(void*)(&students[1].name)<<'\n';
cout<<"Size of name of Stud[1]:\t"<<sizeof(students[1].name)<<'\n';
cout<<"Hex name of Stud[1]:\t";
print_in_hex(&students[1].name, sizeof(students[1].name));
cout<<'\n';
cout<<"Bin name of Stud[1]:\t";
print_in_binary(&students[1].name, sizeof(students[1].name));
cout<<'\n';
cout<<"Adress of year of Stud[1]:\t" <<(void*)(&students[1].year)<<'\n';
cout<<"Size of year of Stud[1]:\t"<<sizeof(students[1].year)<<'\n';
cout<<"Hex year of Stud[1]:\t";
print_in_hex(&students[1].year, sizeof(students[1].year));
cout<<'\n';
cout<<"Bin year of Stud[1]:\t";
print_in_binary(&students[1].year, sizeof(students[1].year));
cout<<'\n';
cout<<"Adress of average of Stud[1]:\t" <<(void*)(&students[1].average)<<'\n';
cout<<"Size of average of Stud[1]:\t"<<sizeof(students[1].average)<<'\n';
cout<<"Hex average of Stud[1]:\t";
print_in_hex(&students[1].average, sizeof(students[1].average));
cout<<'\n';
cout<<"Bin average of Stud[1]:\t";
print_in_binary(&students[1].average, sizeof(students[1].average));
cout<<'\n';
cout<<"Adress of courses of Stud[1]:\t" <<(void*)(&students[1].courses)<<'\n';
cout<<"Size of courses of Stud[1]:\t"<<sizeof(students[1].courses)<<'\n';
cout<<"Hex courses of Stud[1]:\t";
print_in_hex(&students[1].courses, sizeof(students[1].courses));
cout<<'\n';
cout<<"Bin courses of Stud[1]:\t";
print_in_binary(&students[1].courses, sizeof(students[1].courses));
cout<<'\n';
cout<<"Adress of starosta of Stud[1]:\t" <<(void*)(&students[1].starosta)<<'\n';
cout<<"Size of starosta of Stud[1]:\t"<<sizeof(students[1].starosta)<<'\n';
cout<<"Hex starosta of Stud[1]:\t";
print_in_hex(&students[1].starosta, sizeof(students[1].starosta));
cout<<'\n';
cout<<"Bin starosta of Stud[1]:\t";
print_in_binary(&students[1].starosta, sizeof(students[1].starosta));
cout<<'\n';




    return 0;


}
