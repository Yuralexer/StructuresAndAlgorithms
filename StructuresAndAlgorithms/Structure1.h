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
		const int N = 100;
		operation dataBase[100] = {operation()};
	};

	void printDataBase(table database, int reading_cash_register_code) {
		system("cls");
		printf("Касса\tПродукт\tКол-во\tЦена\t\tСкидка\t\tСтоимость\n");
		for (operation i : database.dataBase) {
			if (i.cash_register_code == reading_cash_register_code)
				printf("%i\t%i\t%i\t%f\t%f\t%f\n", i.cash_register_code, i.product_id, i.product_count, i.product_price, i.discount, i.total_product_price);
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
		if (db.n < db.N) {
			for (int i = db.n; i >= 1; i--) {
				db.dataBase[i] = db.dataBase[i - 1];
			}
			db.n++;
		}
		else {
			for (int i = db.N - 1; i >= 1; i--) {
				db.dataBase[i] = db.dataBase[i - 1];
			}
		}
		db.dataBase[0] = a;
	}

	void deleteOperations(table &db, int cash_register_code) {
		int i = 0;
		while (i < db.n) {
			if (db.dataBase[i].cash_register_code == cash_register_code) {
				for (int j = i; j < db.n; j++)
					db.dataBase[j] = db.dataBase[j + 1];
				db.dataBase[db.n - 1] = operation();
				db.n--;
			}
			else i++;
		}
	}
}