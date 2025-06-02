class Human{
  static int breath = 0;
}

class Harsh{
  void increaseLifeRate(int x) {
    Human.breath += x;
    print('Life of Harsh Increased by ${Human.breath} breaths');
  }

  void showLifeCount() {
    print('Life(Harsh): ${Human.breath}');
  }
}

class Jasmin{
  void increaseLifeRate(int x) {
    Human.breath += x;
    print('Life of Jasmin Increased by ${Human.breath} breaths');
  }

  void showLifeCount() {
    print('Life(Jasmin): ${Human.breath}');
  }
}

void main() {
  Jasmin jasmin = Jasmin();
  Harsh harsh = Harsh();

  jasmin.increaseLifeRate(10);
  jasmin.showLifeCount();
  jasmin.increaseLifeRate(10);
  jasmin.showLifeCount();
  Harsh.increaseLifeRate(10);
  Harsh.showLifeCount();
}