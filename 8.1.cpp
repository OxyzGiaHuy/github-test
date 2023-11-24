#include <stdio.h>
#include <ctype.h>
#define MAX 100
int strcmp_Huy(char s1[], char s2[]);
int strcspn_Huy(char s1[], char s2[]);
double atof_Huy(const char s[]);

int main() {
	char s1[MAX], s2[MAX];
	printf("Nhap vao chuoi 1: ");
	fgets(s1, MAX, stdin);
	printf("Nhap vao chuoi 2: ");
	fgets(s2, MAX, stdin);
	printf("strcmp(s1, s2): %d\n", strcmp_Huy(s1, s2));
	printf("strcspn(s1, s2): %d\n", strcspn_Huy(s1, s2));
	printf("atof(s1): %lf\n", atof_Huy(s1));
	printf("atof(s2): %lf", atof_Huy(s2));
	return 0;
}

int strcmp_Huy(char s1[], char s2[]) {
	for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
		if (s1[i] < s2[i]) return -1;
		else if (s1[i] > s2[i]) return 1;
		else continue;
	}
	return 0;
}

int strcspn_Huy(char s1[], char s2[]) {
	int length = 0;
	for (int i = 0; s1[i] != '\0'; i++) {
		for (int j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) return length;
		}
		length++;
	}
}

double atof_Huy(const char s[]) {
	double num = 0;
	int i = 0, sign = 1;
	// kiem tra dau
	if (s[i] == '+' || s[i] == '-') {
		if (s[i] == '-') sign = -1;
		i++;
	}
	// xu ly phan nguyen
	for (; isdigit(s[i]); i++) {
		num = num * 10.0 + (s[i] - 48);// do bang ASCII
	}
	// xu ly phan thap phan
	int Pow = 1;
	if (s[i] == '.') {
		i++;
		for (int j = i; isdigit(s[j]); j++) {
			num = num * 10.0 + (s[j] - 48);
			Pow *= 10;
		}
	}
	return sign * num / Pow;
}