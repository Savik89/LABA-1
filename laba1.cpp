#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

const string filename = "students.txt";
const string filename2 = "tournament.txt";
const int maxStudents = 30;

struct Students {
	string name;
	char sex;
	short int groupId;
	short int numberInGroup;
	int grades[8];
	float avg;
};

struct Tournament {
	string teamName;
	string name;
	char goldenPin;
	int captainAge;
};

int countStudents() {
	int count = 0;
	ifstream file(filename);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Students student;
	while (file >> student.name) {
		file >> student.sex >> student.groupId >> student.numberInGroup;
		for (int i = 0; i < 8; i++) {
			file >> student.grades[i];
		}
		file >> student.avg;
		count++;
	}
	file.close();
	return count;
}

int countTeams() {
	int count = 0;
	ifstream file(filename2);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Tournament tournament;
	while (file >> tournament.teamName) {
		file >> tournament.name >> tournament.goldenPin >> tournament.captainAge;
		count++;
	}
	file.close();
	return count;
}

void addTeam() {
	ofstream file(filename2, ios::app);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	ifstream file2(filename);
	if (!file2) {
		cout << "файл не открыт";
		exit(0);
	}
	Tournament team;
	cout << "Введите название команды: ";
	cin >> team.teamName;
	cout << "Введите имя капитана: ";
	cin >> team.name;
	cout << "Есть ли золотой значок ГТО (y/n): ";
	cin >> team.goldenPin;
	cout << "Введите возраст капитана: ";
	cin >> team.captainAge;
	string target = team.name;
	Students student;
	bool flag = true;
	while (file2 >> student.name && flag) {
		file2 >> student.sex >> student.groupId >> student.numberInGroup;
		for (int i = 0; i < 8; i++) {
			file2 >> student.grades[i];
		}
		file2 >> student.avg;
		if (student.name == target) {
			file << team.teamName << " " << team.name << " " << team.goldenPin << " " << team.captainAge << endl;
			file.close();
			cin.clear();
			cout << "\nкоманда добавлена!";
			flag = false;
		}
	}
	if (flag) {
		cout << "\n\nтакого студента не существует!";
	}
	file.close();
	file2.close();
}

void printTeams() {
	ifstream file(filename2);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	string temp;
	while (!file.eof()) {
		getline(file, temp);
		cout << temp << endl;
	}
	file.close();
}

void checkCaptainAge() {
	ifstream file(filename);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Tournament team;
	Students student;
	for (int i = 0; i < countStudents(); i++){
		file >> student.name >> student.sex >> student.groupId >> student.numberInGroup;
		for (int j = 0; j < 8; j++) {
			file >> student.grades[j];
		}
		file >> student.avg;
		ifstream file2(filename2);
		if (!file2) {
			cout << "файл не открыт";
			exit(0);
		}
		for (int j = 0; j < countTeams(); j++) {
			file2 >> team.teamName >> team.name >> team.goldenPin >> team.captainAge;
			if (student.name == team.name && team.captainAge < 18) {
				cout << student.name << endl << student.sex << endl << student.groupId << endl << student.numberInGroup << endl;
				for (int k = 0; k < 8; k++) {
					cout << student.grades[k] << " ";
				}
				cout << "\nвозраст капитана:" << team.captainAge;
				cout << "\n\n";
			}
		}
		file2.close();
	}
	file.close();
}

void checkGoldenPin() {
	ifstream file(filename);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Tournament team;
	Students student;
	for (int i = 0; i < countStudents(); i++) {
		file >> student.name >> student.sex >> student.groupId >> student.numberInGroup;
		for (int j = 0; j < 8; j++) {
			file >> student.grades[j];
		}
		file >> student.avg;
		ifstream file2(filename2);
		if (!file2) {
			cout << "файл не открыт";
			exit(0);
		}
		for (int j = 0; j < countTeams(); j++) {
			file2 >> team.teamName >> team.name >> team.goldenPin >> team.captainAge;
			if (student.name == team.name && (team.goldenPin == 'y' || team.goldenPin == 'Y')) {
				cout << student.name << endl << student.sex << endl << student.groupId << endl << student.numberInGroup << endl;
				for (int k = 0; k < 8; k++) {
					cout << student.grades[k] << " ";
				}
				cout << "\nзолотой значок есть";
				cout << "\n\n";
			}
		}
		file2.close();
	}
	file.close();
}

void checkCapitain() {
	ifstream file(filename);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Tournament team;
	Students student;
	for (int i = 0; i < countStudents(); i++) {
		file >> student.name >> student.sex >> student.groupId >> student.numberInGroup;
		for (int j = 0; j < 8; j++) {
			file >> student.grades[j];
		}
		file >> student.avg;
		ifstream file2(filename2);
		if (!file2) {
			cout << "файл не открыт";
			exit(0);
		}
		for (int j = 0; j < countTeams(); j++) {
			file2 >> team.teamName >> team.name >> team.goldenPin >> team.captainAge;
			if (student.name == team.name ) {
				cout << student.name << endl << student.sex << endl << student.groupId << endl << student.numberInGroup << endl;
				for (int k = 0; k < 8; k++) {
					cout << student.grades[k] << " ";
				}
				cout << "\nкапитан команды " << team.teamName;
				cout << "\n\n";
			}
		}
		file2.close();
	}
	file.close();
}

void addStudent() {
	ofstream file(filename, ios::app);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Students student;
	cout << "введите имя: ";
	cin >> student.name;
	cout << "введите пол: ";
	cin >> student.sex;
	cout << "введите номер группы: ";
	cin >> student.groupId;
	cout << "введите номер в группе: ";
	cin >> student.numberInGroup;
	cout << "введите оценки: ";
	float avg = 0;
	for (int i = 0; i < 8; i++){
		cin >> student.grades[i];
		avg += student.grades[i];
		if (student.grades[i] < 3 || student.grades[i] > 5) {
			cout << "оценка от 3 до 5 !!";
			avg = 0;
			_getch();
			system("cls");
		}
	}
	student.avg = avg/8;
	avg = 0;
	file << student.name << " " << student.sex << " " << student.groupId << " " << student.numberInGroup << " ";
	for (int i = 0; i < 8; i++) {
		file << student.grades[i] << " ";
	}
	file << student.avg;
	file << endl;
	file.close();
	cin.clear();
	cout << "\nстудент добавлен" << endl;
}

void editStudent() {
	string target;
	cout << "Введите имя студента, которого меняем: ";
	cin >> target;
	ifstream inputfile(filename);
	if (!inputfile) {
		cout << "файл не открыт";
		exit(0);
	}
	ofstream outputfile("tempstudents.txt");
	if (!outputfile) {
		cout << "файл не открыт";
		exit(0);
	}
	Students student;
	bool flag = false;
	bool flag2 = false;
	while (inputfile >> student.name) {
		inputfile >> student.sex >> student.groupId >> student.numberInGroup;
		for (int i = 0; i < 8; i++) {
			inputfile >> student.grades[i];
		}
		inputfile >> student.avg;
		if (student.name == target && !flag2) {
			flag = true;
			flag2 = true;
			cout << "Введите новое имя студента: ";
			cin >> student.name;
			cout << "Введите пол студента: ";
			cin >> student.sex;
			cout << "Введите номер группы: ";
			cin >> student.groupId;
			cout << "Введите номер студента в группе: ";
			cin >> student.numberInGroup;
			cout << "Введите новые оценки: ";
			float avg = 0;
			for (int i = 0; i < 8; i++) {
				cin >> student.grades[i];
				avg += student.grades[i];
			}
			student.avg = avg / 8;
			outputfile << student.name << " " << student.sex << " " << student.groupId << " " << student.numberInGroup << " ";
			for (int i = 0; i < 8; i++) {
				outputfile << student.grades[i] << " ";
			}
			outputfile << student.avg << endl;
			cout << "\nинформация обновлена";
		}
		else {
			outputfile << student.name << " " << student.sex << " " << student.groupId << " " << student.numberInGroup << " ";
			for (int i = 0; i < 8; i++) {
				outputfile << student.grades[i] << " ";
			}
			outputfile << student.avg << endl;
		}
	}
	inputfile.close();
	outputfile.close();
	remove(filename.c_str());
	rename("tempstudents.txt", filename.c_str());
	if (!flag) {
		cout << "Студент с именем " << target << " не найден ! ";
	}
}

void printStudents() {
	ifstream file(filename);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	string temp;
	while (!file.eof()) {
		getline(file, temp);
		cout << temp << endl;
	}
	file.close();
}

void studentsInGroup() {
	int target;
	cout << "Введите номер группы: ";
	cin >> target;
	ifstream file(filename);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Students student;
	bool flag = false;
	while (file >> student.name) {
		file >> student.sex >> student.groupId >> student.numberInGroup;
		for (int i = 0; i < 8; i++) {
			file >> student.grades[i];
		}
		file >> student.avg;
		if (student.groupId == target) {
			if (!flag)
				cout << "студенты найдены!\n\n";
			flag = true;
			cout << student.name << endl << student.sex << endl << student.groupId << endl << student.numberInGroup << endl;
			for (int i = 0; i < 8; i++) {
				cout << student.grades[i] << " ";
			}
			cout << "\n\n";
		}
	}
	if (!flag) {
		cout << "студенты с таким номером группы не найдены";
	}
	file.close();
}

void printTopStudents() {
	ifstream file(filename);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Students student[maxStudents];
	int count = countStudents();
	for (int i = 0; i < count; i++) {
		file >> student[i].name >> student[i].sex >> student[i].groupId >> student[i].numberInGroup;
		for (int j = 0; j < 8; j++)
			file >> student[i].grades[j];
		file >> student[i].avg;
	}
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (student[j].avg < student[j + 1].avg)
				swap(student[j], student[j + 1]);
		}
	}
	for (int i = 0; i < count; i++) {
		cout << student[i].name << " " << student[i].sex << " " << student[i].groupId << " " << student[i].numberInGroup << " ";
		for (int j = 0; j < 8; j++)
			cout << student[i].grades[j] << " ";
		cout << student[i].avg << endl;
	}
	file.close();
}

void countMen() {
	int count = countStudents(), countM = 0;
	ifstream file(filename);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Students student;
	for (int i = 0; i < count; i++) {
		file >> student.name >> student.sex >> student.groupId >> student.numberInGroup;
		for (int j = 0; j < 8; j++)
			file >> student.grades[j];
		file >> student.avg;
		if (student.sex == 'M' || student.sex == 'm')
			countM++;
	}
	cout << "Мужчин: " << countM << endl;
	cout << "Женщин: " << count - countM << endl;
}

void checkStipend(){
	bool flag = false;
	ifstream file(filename);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Students student;
	while (file >> student.name) {
		file >> student.sex >> student.groupId >> student.numberInGroup;
		for (int i = 0; i < 8; i++) {
			file >> student.grades[i];
		}
		file >> student.avg;
		if (student.avg == 5) {
			cout << "Отличник: ";
			cout << student.name << endl << student.sex << endl << student.groupId << endl << student.numberInGroup << endl;
			for (int i = 0; i < 8; i++) {
				cout << student.grades[i] << " ";
			}
			cout << "\n\n";
			break;
		}
		else for (int i = 0; i < 8; i++) {
			if (student.grades[i] == 3 && !flag) {
				flag = true;
			}
			if (flag) {
				cout << "Троечник без стипендии: ";
				cout << student.name << endl << student.sex << endl << student.groupId << endl << student.numberInGroup << endl;
				for (int i = 0; i < 8; i++) {
					cout << student.grades[i] << " ";
				}
				cout << "\n\n";
				break;
			}
			else {
				cout << "Хорошист: ";
				cout << student.name << endl << student.sex << endl << student.groupId << endl << student.numberInGroup << endl;
				for (int i = 0; i < 8; i++) {
					cout << student.grades[i] << " ";
				}
				cout << "\n\n";
				break;
			}
		}
	}
}

void studentsWithNumber(){
	int target;
	cout << "Введите номер студента в группе: ";
	cin >> target;
	ifstream file(filename);
	if (!file) {
		cout << "файл не открыт";
		exit(0);
	}
	Students student;
	bool flag = false;
	while (file >> student.name) {
		file >> student.sex >> student.groupId >> student.numberInGroup;
		for (int i = 0; i < 8; i++) {
			file >> student.grades[i];
		}
		file >> student.avg;
		if (student.numberInGroup == target) {
			if (!flag)
				cout << "студенты найдены!\n\n";
			flag = true;
			cout << student.name << endl << student.sex << endl << student.groupId << endl << student.numberInGroup << endl;
			for (int i = 0; i < 8; i++) {
				cout << student.grades[i] << " ";
			}
			cout << "\n\n";
		}
	}
	if (!flag) {
		cout << "студенты с таким номером в группе не найдены";
	}
}

void main(){
	system("cls");
	int choice;
	cout << "Что будем делать?" << endl;
	cout << "1. Создать новую запись" << endl;
	cout << "2. Внести изменения в уже имеющуюся запись" << endl;
	cout << "3. Вывод всех данных о студентах" << endl;
	cout << "4. Вывод информации обо всех студентах определённой группы" << endl;
	cout << "5. Вывод топа самых успешных студентов" << endl;
	cout << "6. Вывод количество студентов мужского и женского пола" << endl;
	cout << "7. Вывод данных о студентах которые не получают стипендию или..." << endl;
	cout << "8. Вывод данных о студентах, имеющих определённый номер в списке" << endl;
	cout << "9. Кубок первокурсника (idz)" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		addStudent();
		_getch();
		system("cls");
		main();
		break;
	case 2:
		system("cls");
		editStudent();
		_getch();
		system("cls");
		main();
		break;
	case 3:
		system("cls");
		printStudents();
		_getch();
		main();
		break;
	case 4:
		system("cls");
		studentsInGroup();
		_getch();
		main();
		break;
	case 5:
		system("cls");
		printTopStudents();
		_getch();
		main();
		break;
	case 6:
		system("cls");
		countMen();
		_getch();
		main();
		break;
	case 7:
		system("cls");
		checkStipend();
		_getch();
		main();
		break;
	case 8:
		system("cls");
		studentsWithNumber();
		_getch();
		main();
		break;
	case 9:
		system("cls");
		int choice2;
		cout << "1. Добавить команду на турнир" << endl;
		cout << "2. Вывести все команды турнира" << endl;
		cout << "3. Вывести информацию о студентах моложе 18 лет" << endl;
		cout << "4. Вывести информацию о студентах с золотым значком ГТО" << endl;
		cout << "5. Вывести информацию о студентах которые капитаны" << endl;
		cin >> choice2;
		switch (choice2) {
		case 1:
			system("cls");
			addTeam();
			_getch();
			main();
			break;
		case 2:
			system("cls");
			printTeams();
			_getch();
			main();
			break;
		case 3:
			system("cls");
			checkCaptainAge();
			_getch();
			main();
			break;
		case 4:
			system("cls");
			checkGoldenPin();
			_getch();
			main();
		case 5:
			system("cls");
			checkCapitain();
			_getch();
			main();
		}
	default:
		break;
	}
}