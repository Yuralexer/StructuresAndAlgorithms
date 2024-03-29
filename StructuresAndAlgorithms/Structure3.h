#pragma once
#include <iostream>
#include <vector>
#include <ios>

namespace std {

	struct operation {
		int cash_register_code;
		int product_id;
		int product_count;
		float product_price;
		float discount;
		float total_product_price;
	};

	struct table {
		int n = 0;
		vector <operation> dataBase;
	};

	void printDataBase(table database, int reading_cash_register_code) {
		system("cls");
		printf("�����\t�������\t���-��\t����\t\t������\t\t���������\n");
		for (int i = 0; i < database.n; i++) {
			if (database.dataBase[i].cash_register_code == reading_cash_register_code)
				printf("%i\t%i\t%i\t%f\t%f\t%f\n", database.dataBase[i].cash_register_code, database.dataBase[i].product_id, database.dataBase[i].product_count, database.dataBase[i].product_price, database.dataBase[i].discount, database.dataBase[i].total_product_price);
		}
	}

	operation addoperation() {
		operation r_volume;
		int temp_volume_int; float temp_volume_float;
		while (true) {
			printf("������� ����� �����: ");
			cin >> temp_volume_int;
			if (temp_volume_int >= 0) {
				r_volume.cash_register_code = temp_volume_int;
				system("cls");
				break;
			}
			system("cls");
			printf("������� ����� ����� �����!\n");
		}
		while (true) {
			printf("������� ��� ������: ");
			cin >> temp_volume_int;
			if (temp_volume_int >= 0) {
				r_volume.product_id = temp_volume_int;
				system("cls");
				break;
			}
			system("cls");
			printf("������� ����� ��� ������!\n");
		}
		while (true) {
			printf("������� ���������� ������: ");
			cin >> temp_volume_int;
			if (temp_volume_int >= 1) {
				r_volume.product_count = temp_volume_int;
				system("cls");
				break;
			}
			system("cls");
			printf("������� ������� ���������� ������!\n");
		}
		while (true) {
			printf("������� ���� ������: ");
			cin >> temp_volume_float;
			if (temp_volume_float > 0) {
				r_volume.product_price = temp_volume_float;
				system("cls");
				break;
			}
			system("cls");
			printf("������� ������� ���� ������!\n");
		}
		while (true) {
			printf("������� ���������� ������ (� ���������): ");
			cin >> temp_volume_float;
			if (temp_volume_float >= 0) {
				r_volume.discount = temp_volume_float;
				system("cls");
				break;
			}
			system("cls");
			printf("������� ������� ���� ������!\n");
		}
		r_volume.total_product_price = r_volume.product_count * r_volume.product_price * (1 - r_volume.discount * 0.01);
		return r_volume;
	}

	void addOperationInDataBase(table& db, operation a) {
		db.dataBase.insert(db.dataBase.begin(), a);
		db.n++;
	}

	void deleteOperations(table& db, int cash_register_code) {
		int i = 0;
		while (i < db.n) {
			if (db.dataBase[i].cash_register_code == cash_register_code) {
				db.dataBase.erase(db.dataBase.begin() + i);
				db.n--;
			}
			else i++;
		}
	}
}