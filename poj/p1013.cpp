#include <iostream>
#include <cstring>

char left[12];
char right[12];
char result[12];
bool light[12];
bool heavy[12];

void update() {
  int length = strlen(left);
  switch(result[0]) {
    case 'e':
      for(int i=0; i<length; ++i) {
        light[left[i] - 'A'] = false;
        heavy[left[i] - 'A'] = false;
        light[right[i] - 'A'] = false;
        heavy[right[i] - 'A'] = false;
      }
      break;
    case 'u':
      for(int i=0; i<length; ++i) {
        light[left[i] - 'A'] = false;
        heavy[right[i] - 'A'] = false;
      }
      for(int i=0; i<12; ++i) {
        int coin = i + 'A';
        if((strchr(left, coin)==NULL)&&(strchr(right, coin)==NULL)) {
          light[i] = false;
          heavy[i] = false;
        }
      }
      break;
    case 'd':
      for(int i=0; i<length; ++i) {
        heavy[left[i] - 'A'] = false;
        light[right[i] - 'A'] = false;
      }
      for(int i=0; i<12; ++i) {
        int coin = i + 'A';
        if((strchr(left, coin)==NULL)&&(strchr(right, coin)==NULL)) {
          light[i] = false;
          heavy[i] = false;
        }
      }
      break;
  }
}

int main(int argc, char* argv[]) {
  int count = 0;
  std::cin >> count;
  for(int i=0; i<count; ++i) {
    for(int k=0; k<12; ++k) {
      light[k] = true;
      heavy[k] = true;
    }
    for(int k=0; k<3; ++k) {
      std::cin >> left >> right >> result;
      update();
    }
    for(int k=0; k<12; ++k) {
      if(light[k] ^ heavy[k]) {
        char coin = static_cast<char>(k + 'A');
        std::cout << coin << " is the counterfeit coin and it is " << (light[k] ? "light" : "heavy") << "." << std::endl; 
      }
    }
  }
  return 0;
}
