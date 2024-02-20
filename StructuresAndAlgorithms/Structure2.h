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
		operation* dataBase = new operation[n];
	};

	void printDataBase(table database, int reading_cash_register_code) {
		system("cls");
		printf("Касса\tПродукт\tКол-во\tЦена\t\tСкидка\t\tСтоимость\n");
		for (int i = 0; i < database.n; i++) {
			if (database.dataBase[i].cash_register_code == reading_cash_register_code)
				printf("%i\t%i\t%i\t%f\t%f\t%f\n", database.dataBase[i].cash_register_code, database.dataBase[i].product_id, database.dataBase[i].product_count, database.dataBase[i].product_price, database.dataBase[i].discount, database.dataBase[i].total_product_price);
		}
	}

	operation addoperation() {
		operation r_volume;
		int temp_volume_int; float temp_volume_float;
		while (true) {
			printf("Введите номер кассы: ");
			cin >> temp_volume_int;
			if (temp_volume_int >= 0) {
				r_volume.cash_register_code = temp_volume_int;
				system("cls");
				break;
			}
			system("cls");
			printf("Неверно введён номер кассы!\n");
		}
		while (true) {
			printf("Введите код товара: ");
			cin >> temp_volume_int;
			if (temp_volume_int >= 0) {
				r_volume.product_id = temp_volume_int;
				system("cls");
				break;
			}
			system("cls");
			printf("Неверно введён код товара!\n");
		}
		while (true) {
			printf("Введите количество товара: ");
			cin >> temp_volume_int;
			if (temp_volume_int >= 1) {
				r_volume.product_count = temp_volume_int;
				system("cls");
				break;
			}
			system("cls");
			printf("Неверно введено количество товара!\n");
		}
		while (true) {
			printf("Введите цену товара: ");
			cin >> temp_volume_float;
			if (temp_volume_float > 0) {
				r_volume.product_price = temp_volume_float;
				system("cls");
				break;
			}
			system("cls");
			printf("Неверно введена цена товара!\n");
		}
		while (true) {
			printf("Введите процентную скидку (в процентах): ");
			cin >> temp_volume_float;
			if (temp_volume_float >= 0) {
				r_volume.discount = temp_volume_float;
				system("cls");
				break;
			}
			system("cls");
			printf("Неверно введена цена товара!\n");
		}
		r_volume.total_product_price = r_volume.product_count * r_volume.product_price * (1 - r_volume.discount * 0.01);
		return r_volume;
	}

	void addOperationInDataBase(table& db, operation a) {
		db.n++;
		operation* temp_table = new operation[db.n];
		temp_table[0] = a;
		for (int i = 0; i < db.n; i++)
			temp_table[i + 1] = db.dataBase[i];
		db.dataBase = temp_table;
	}

	void deleteOperations(table& db, int cash_register_code) {
		int count_remove_operations = 0, temp_count_remove_operations = 0;
		for (int i = 0; i < db.n; i++)
			if (db.dataBase[i].cash_register_code == cash_register_code) temp_count_remove_operations++;
		operation* temp_table = new operation[db.n - temp_count_remove_operations];
		for (int i = 0; i < db.n; i++) 
			if (db.dataBase[i].cash_register_code == cash_register_code) {
				temp_count_remove_operations--;
				count_remove_operations++;
			}
			else
				temp_table[i - count_remove_operations] = db.dataBase[i];

		db.n -= count_remove_operations;
		db.dataBase = temp_table;
	}
}