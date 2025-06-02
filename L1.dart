abstract class GTU {
  String? id;
  String? uniName;

  void showUniDetails(){}
}

class University extends GTU{
  String? universityName;
  String? gtuId;

  void showDetails() {
    print('Darshan University\n');
  }

  @override
  void showUniDetails() {
    print('Univerity Name: $universityName\nGTUID: $gtuId');
  }
}

class Student extends University {
  String? studentName;
  int? enrollNo;
  int? rollNo;

  @override
  void showDetails() {
    print(
        'Name: $studentName\nUniversityname: $universityName\nUniversity ID: $gtuId\nEnrollment number: $enrollNo\nRoll number: $rollNo');
  }
}

void main() {
  Student Harsh = Student();
  Harsh.studentName = 'Harsh Khant';
  Harsh.universityName = 'DU';
  Harsh.gtuId = '2';
  Harsh.enrollNo = 6534;
  Harsh.rollNo = 239;

  Harsh.showDetails();
  print('\n');
  Harsh.showUniDetails();
}
